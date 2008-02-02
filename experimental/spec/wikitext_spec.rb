#!/usr/bin/env ruby
# Copyright 2008 Wincent Colaiuta
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

require File.join(File.dirname(__FILE__), 'spec_helper.rb')
require 'wikitext'

describe Wikitext, 'token_types method' do
  before do
    @tokens = Wikitext::token_types
  end

  it 'should report the available token types as a hash' do
    @tokens.should be_kind_of(Hash)
  end

  it 'should report token names as symbols and values as numbers' do
    @tokens.each do |k, v|
      k.should be_kind_of(Integer)
      v.should be_kind_of(Symbol)
    end
  end

  it 'should report unique token names and values' do
    keys = @tokens.keys
    keys.uniq.length.should == keys.length
    values = @tokens.values
    values.uniq.length.should == values.length
  end
end

describe Wikitext::Parser, 'tokenizing' do
  before do
    @parser = Wikitext::Parser.new
    @types  = Wikitext::token_types
  end

  it 'should do nothing if passed nil' do
    @parser.tokenize(nil).should == nil
  end

  it "should complain if passed an object that doesn't quack like a string" do
    lambda { @parser.tokenize({}) }.should raise_error
  end

  it 'should tokenize strings containing a single symbol' do
    @tokens = @parser.tokenize('foo')
    @tokens.length.should == 2
    @tokens[0].token_type.should    == :printable
    @tokens[0].string_value.should  == 'foo'
    @tokens[1].token_type.should    == :end_of_file
    @tokens[1].string_value.should  == ''
  end

  it 'should tokenize strings containing multiple symbols' do
    @tokens = @parser.tokenize('foo http://example.com/')
    @tokens.length.should == 4
    @tokens[0].token_type.should    == :printable
    @tokens[0].string_value.should  == 'foo'
    @tokens[1].token_type.should    == :space
    @tokens[1].string_value.should  == ' '
    @tokens[2].token_type.should    == :uri
    @tokens[2].string_value.should  == 'http://example.com/'
    @tokens[3].token_type.should    == :end_of_file
    @tokens[3].string_value.should  == ''
  end

  it 'should tokenize runs of printable characters as as single symbol' do
    @tokens = @parser.tokenize('foo')
    @tokens.length.should == 2
    @tokens[0].token_type.should    == :printable
    @tokens[0].string_value.should  == 'foo'
    @tokens[0].line_start.should    == 1
    @tokens[0].column_start.should  == 1
    @tokens[0].line_stop.should     == 1
    @tokens[0].column_stop.should   == 4
    @tokens[1].token_type.should    == :end_of_file
    @tokens[1].string_value.should  == ''
  end

  it 'should tokenize END_OF_FILE tokens as zero-width tokens' do
    @tokens = @parser.tokenize('')
    @tokens.length.should == 1
    @tokens[0].token_type.should    == :end_of_file
    @tokens[0].line_start.should    == 1
    @tokens[0].column_start.should  == 1
    @tokens[0].line_stop.should     == 1
    @tokens[0].column_stop.should   == 1
    @tokens[0].string_value.should  == ''
  end

  it 'should be able to tokenize large blocks of text' do
    large_block_of_text = <<SLAB
paragraph
second line

new paragraph

= a heading =

> a blockquote
> second line of blockquote
>
> new paragraph within blockquote

== another heading ==

paragraph within ''multiple '''styles''''' and <tt>tt span</tt>

similar, but with '''styles in ''different'' order'''

again, a '''different ''order'''''

* list item 1
** nested list item 1
** nested list item 2
** nested list item 3
* list item 2

 // this is a code block
 notice how it can contain ''markup''
 which would '''otherwise''' have <tt>special</tt> meaning
 although explicit entities &copy; are passed through unchanged

a normal paragraph again

This is where we show a link to an article on [[GCC]].
Related to that, [[GCC|a link]] to the same
article but with custom link text.

External links [http://example.com work too].
As well as autolinks as seen http://example.com/
here.

Look at how we handle bad syntax. [[This is an unterminated
link. And [http://example.com/ is another.

# this is an ordered list
# which continues
## and has another ordered list
## nested inside it
# and then falls back
#* and then nests another list
#* this time an unordered one
#** itself containing a nested list
#** which continues
#**# and finally nests yet another ordered list
#**# which continues
#* drops back quite a way
# and finally all the way
#****** and finishes with an invalid item

=== heading with missing closing tag
* list
# new list
SLAB

    @tokens = @parser.tokenize(large_block_of_text)
    @tokens
  end
end
