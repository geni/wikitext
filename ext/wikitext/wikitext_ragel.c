
#line 1 "wikitext_ragel.rl"
// Copyright 2008-present Greg Hurrell. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

//----------------------------------------------------------------------//
// NOTE: wikitext_ragel.c is generated from wikitext_ragel.rl, so       //
//       if you make changes to the former they will be overwritten.    //
//       You should perform all your edits in wikitext_ragel.rl.        //
//----------------------------------------------------------------------//

#include "wikitext_ragel.h"
#include "wikitext.h"
#include <stdio.h>

#define EMIT(t)     do { out->type = t; out->stop = p + 1; out->column_stop += (out->stop - out->start); } while (0)
#define MARK()      do { mark = p; } while (0)
#define REWIND()    do { p = mark; } while (0)
#define AT_END()    (p + 1 == pe)
#define DISTANCE()  (p + 1 - ts)
#define NEXT_CHAR() (*(p + 1))


#line 45 "wikitext_ragel.c"
static const int wikitext_start = 109;
static const int wikitext_first_final = 109;
static const int wikitext_error = 0;

static const int wikitext_en_main = 109;


#line 490 "wikitext_ragel.rl"


// for now we use the scanner as a tokenizer that returns one token at a time, just like ANTLR
// ultimately we could look at embedding all of the transformation inside the scanner itself (combined scanner/parser)
// pass in the last token because that's useful for the scanner to know
// p data pointer (required by Ragel machine); overriden with contents of last_token if supplied
// pe data end pointer (required by Ragel machine)
void next_token(token_t *out, token_t *last_token, unsigned char *p, unsigned char *pe)
{
    int last_token_type = NO_TOKEN;
    if (last_token)
    {
        last_token_type     = last_token->type;
        p = last_token->stop;
        out->line_start     = out->line_stop    = last_token->line_stop;
        out->column_start   = out->column_stop  = last_token->column_stop;
    }
    else
    {
        out->line_start     = 1;
        out->column_start   = 1;
        out->line_stop      = 1;
        out->column_stop    = 1;
    }
    out->type       = NO_TOKEN;
    out->code_point = 0;
    out->start      = p;
    if (p == pe)
    {
        // all done, have reached end of input
        out->stop  = p;
        out->type  = END_OF_FILE;
        return;
    }

    unsigned char *mark;      // for manual backtracking
    unsigned char *eof = pe;  // required for backtracking (longest match determination)
    int     cs;         // current state (standard Ragel)
    unsigned char *ts;        // token start (scanner)
    unsigned char *te;        // token end (scanner)
    int     act;        // identity of last patterned matched (scanner)

#line 96 "wikitext_ragel.c"
	{
	cs = wikitext_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 532 "wikitext_ragel.rl"

#line 106 "wikitext_ragel.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 388 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(AMP);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr3:
#line 376 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DECIMAL_ENTITY);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr5:
#line 370 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(HEX_ENTITY);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr7:
#line 364 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NAMED_ENTITY);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr11:
#line 358 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(AMP_ENTITY);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr15:
#line 352 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT_ENTITY);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr16:
#line 1 "NONE"
	{	switch( act ) {
	case 21:
	{{p = ((te))-1;}
            EMIT(URI);
            {p++; cs = 109; goto _out;}
        }
	break;
	case 22:
	{{p = ((te))-1;}
            EMIT(MAIL);
            {p++; cs = 109; goto _out;}
        }
	break;
	case 43:
	{{p = ((te))-1;}
            EMIT(SPECIAL_URI_CHARS);
            {p++; cs = 109; goto _out;}
        }
	break;
	case 44:
	{{p = ((te))-1;}
            EMIT(ALNUM);
            {p++; cs = 109; goto _out;}
        }
	break;
	case 45:
	{{p = ((te))-1;}
            EMIT(PRINTABLE);
            {p++; cs = 109; goto _out;}
        }
	break;
	}
	}
	goto st109;
tr23:
#line 394 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(LESS);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr39:
#line 133 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr41:
#line 175 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr47:
#line 103 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr50:
#line 121 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr56:
#line 163 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr58:
#line 193 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr68:
#line 127 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr70:
#line 169 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr76:
#line 97 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr79:
#line 109 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr85:
#line 157 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr87:
#line 187 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr99:
#line 115 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr100:
#line 449 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(ALNUM);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr107:
#line 304 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(URI);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr115:
#line 56 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 1)) & 0x1f) << 6 |
            (*p & 0x3f);
    }
#line 481 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr118:
#line 62 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 2)) & 0x0f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
#line 481 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr121:
#line 69 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 3)) & 0x07) << 18 |
            ((uint32_t)(*(p - 2)) & 0x3f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
#line 481 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr122:
#line 51 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
#line 481 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr123:
#line 430 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 109; goto _out;}
        }}
#line 51 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
	goto st109;
tr127:
#line 382 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr128:
#line 225 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(OL);
            else
                EMIT(PRINTABLE);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr132:
#line 238 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(UL);
            else
                EMIT(PRINTABLE);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr146:
#line 181 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr148:
#line 334 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SEPARATOR);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr153:
#line 430 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr154:
#line 430 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr155:
#line 213 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
            {
                REWIND();
                EMIT(PRE);
            }
            else
                EMIT(SPACE);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr157:
#line 443 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(SPECIAL_URI_CHARS);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr158:
#line 461 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PRINTABLE);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr159:
#line 388 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(AMP);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr163:
#line 139 "wikitext_ragel.rl"
	{te = p;p--;{
            if (DISTANCE() == 5)
                EMIT(STRONG_EM);
            else if (DISTANCE() == 4)
            {
                p--;
                EMIT(STRONG_EM);
            }
            else if (DISTANCE() == 3)
                EMIT(STRONG);
            else if (DISTANCE() == 2)
                EMIT(EM);
            else
                EMIT(PRINTABLE);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr167:
#line 139 "wikitext_ragel.rl"
	{te = p+1;{
            if (DISTANCE() == 5)
                EMIT(STRONG_EM);
            else if (DISTANCE() == 4)
            {
                p--;
                EMIT(STRONG_EM);
            }
            else if (DISTANCE() == 3)
                EMIT(STRONG);
            else if (DISTANCE() == 2)
                EMIT(EM);
            else
                EMIT(PRINTABLE);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr169:
#line 310 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(MAIL);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr173:
#line 316 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PATH);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr177:
#line 449 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(ALNUM);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr178:
#line 394 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LESS);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr187:
#line 251 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE || last_token_type == BLOCKQUOTE_START)
            {
                REWIND();
                if (DISTANCE() == 1)
                    EMIT(H1_START);
                else if (DISTANCE() == 2)
                    EMIT(H2_START);
                else if (DISTANCE() == 3)
                    EMIT(H3_START);
                else if (DISTANCE() == 4)
                    EMIT(H4_START);
                else if (DISTANCE() == 5)
                    EMIT(H5_START);
                else if (DISTANCE() == 6)
                    EMIT(H6_START);
                else if (DISTANCE() > 6)
                {
                    p = ts + 6;
                    EMIT(H6_START);
                }
            }
            else if (AT_END() || NEXT_CHAR() == '\n' || NEXT_CHAR() == '\r')
            {
                REWIND();
                if (DISTANCE() == 1)
                    EMIT(H1_END);
                else if (DISTANCE() == 2)
                    EMIT(H2_END);
                else if (DISTANCE() == 3)
                    EMIT(H3_END);
                else if (DISTANCE() == 4)
                    EMIT(H4_END);
                else if (DISTANCE() == 5)
                    EMIT(H5_END);
                else if (DISTANCE() == 6)
                    EMIT(H6_END);
                else if (DISTANCE() > 6)
                {
                    p -= 6; // will scan the H6 on the next scan
                    EMIT(PRINTABLE);
                }
            }
            else
            {
                // note that a H*_END token will never match before a BLOCKQUOTE_END
                REWIND();
                EMIT(PRINTABLE);
            }
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr189:
#line 200 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr190:
#line 200 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr194:
#line 304 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(URI);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr208:
#line 340 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr209:
#line 322 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr210:
#line 346 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr211:
#line 328 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr212:
#line 418 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LEFT_CURLY);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr213:
#line 406 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_START);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr214:
#line 424 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(RIGHT_CURLY);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
tr215:
#line 412 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_END);
            {p++; cs = 109; goto _out;}
        }}
	goto st109;
st109:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 1 "NONE"
	{ts = p;}
#line 687 "wikitext_ragel.c"
	switch( (*p) ) {
		case 10u: goto tr123;
		case 13u: goto tr124;
		case 32u: goto tr125;
		case 33u: goto st112;
		case 34u: goto tr127;
		case 35u: goto tr128;
		case 38u: goto tr130;
		case 39u: goto st115;
		case 42u: goto tr132;
		case 43u: goto st113;
		case 45u: goto tr133;
		case 46u: goto tr134;
		case 47u: goto st126;
		case 60u: goto tr137;
		case 61u: goto tr138;
		case 62u: goto tr139;
		case 64u: goto st113;
		case 70u: goto tr140;
		case 72u: goto tr141;
		case 77u: goto tr142;
		case 83u: goto tr143;
		case 91u: goto st155;
		case 92u: goto st113;
		case 93u: goto st156;
		case 94u: goto st113;
		case 95u: goto tr133;
		case 96u: goto tr146;
		case 102u: goto tr140;
		case 104u: goto tr141;
		case 109u: goto tr142;
		case 115u: goto tr143;
		case 123u: goto st157;
		case 124u: goto tr148;
		case 125u: goto st158;
		case 126u: goto st113;
		case 127u: goto tr122;
	}
	if ( (*p) < 58u ) {
		if ( (*p) < 36u ) {
			if ( 1u <= (*p) && (*p) <= 31u )
				goto tr122;
		} else if ( (*p) > 37u ) {
			if ( (*p) > 44u ) {
				if ( 48u <= (*p) && (*p) <= 57u )
					goto tr136;
			} else if ( (*p) >= 40u )
				goto st112;
		} else
			goto st113;
	} else if ( (*p) > 63u ) {
		if ( (*p) < 194u ) {
			if ( 65u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) > 223u ) {
			if ( (*p) > 239u ) {
				if ( 240u <= (*p) && (*p) <= 244u )
					goto st106;
			} else if ( (*p) >= 224u )
				goto st104;
		} else
			goto st103;
	} else
		goto st112;
	goto st0;
st0:
cs = 0;
	goto _out;
tr124:
#line 51 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 766 "wikitext_ragel.c"
	if ( (*p) == 10u )
		goto tr154;
	goto tr153;
tr125:
#line 46 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 780 "wikitext_ragel.c"
	if ( (*p) == 32u )
		goto st111;
	goto tr155;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 33u: goto st112;
		case 44u: goto st112;
		case 46u: goto st112;
		case 63u: goto st112;
	}
	if ( (*p) > 41u ) {
		if ( 58u <= (*p) && (*p) <= 59u )
			goto st112;
	} else if ( (*p) >= 40u )
		goto st112;
	goto tr157;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 43u: goto st113;
		case 45u: goto st113;
		case 47u: goto st113;
		case 64u: goto st113;
		case 92u: goto st113;
		case 126u: goto st113;
	}
	if ( (*p) > 37u ) {
		if ( 94u <= (*p) && (*p) <= 95u )
			goto st113;
	} else if ( (*p) >= 36u )
		goto st113;
	goto tr158;
tr130:
#line 1 "NONE"
	{te = p+1;}
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 826 "wikitext_ragel.c"
	switch( (*p) ) {
		case 35u: goto st1;
		case 97u: goto st7;
		case 113u: goto st10;
	}
	if ( (*p) > 90u ) {
		if ( 98u <= (*p) && (*p) <= 122u )
			goto st5;
	} else if ( (*p) >= 65u )
		goto st5;
	goto tr159;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 88u: goto st3;
		case 120u: goto st3;
	}
	if ( 48u <= (*p) && (*p) <= 57u )
		goto st2;
	goto tr0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 59u )
		goto tr3;
	if ( 48u <= (*p) && (*p) <= 57u )
		goto st2;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st4;
	} else if ( (*p) > 70u ) {
		if ( 97u <= (*p) && (*p) <= 102u )
			goto st4;
	} else
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 59u )
		goto tr5;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st4;
	} else if ( (*p) > 70u ) {
		if ( 97u <= (*p) && (*p) <= 102u )
			goto st4;
	} else
		goto st4;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 59u )
		goto tr7;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 59u )
		goto tr7;
	if ( 48u <= (*p) && (*p) <= 57u )
		goto st6;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 59u: goto tr7;
		case 109u: goto st8;
	}
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	switch( (*p) ) {
		case 59u: goto tr7;
		case 112u: goto st9;
	}
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 59u )
		goto tr11;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 59u: goto tr7;
		case 117u: goto st11;
	}
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 59u: goto tr7;
		case 111u: goto st12;
	}
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	switch( (*p) ) {
		case 59u: goto tr7;
		case 116u: goto st13;
	}
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 59u )
		goto tr15;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st6;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st5;
	} else
		goto st5;
	goto tr0;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 39u )
		goto st116;
	goto tr163;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) == 39u )
		goto st117;
	goto tr163;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 39u )
		goto st118;
	goto tr163;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) == 39u )
		goto tr167;
	goto tr163;
tr133:
#line 1 "NONE"
	{te = p+1;}
#line 461 "wikitext_ragel.rl"
	{act = 45;}
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 1063 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st113;
		case 45u: goto tr133;
		case 47u: goto st113;
		case 64u: goto tr168;
		case 92u: goto st113;
		case 94u: goto st113;
		case 95u: goto tr133;
		case 126u: goto st113;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st113;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr158;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr16;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st16;
	} else
		goto st16;
	goto tr16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st16;
	} else
		goto st16;
	goto tr16;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st18;
	} else
		goto st18;
	goto tr16;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr22;
	} else
		goto tr22;
	goto tr16;
tr22:
#line 1 "NONE"
	{te = p+1;}
#line 310 "wikitext_ragel.rl"
	{act = 22;}
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 1172 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr170;
	} else
		goto tr170;
	goto tr169;
tr170:
#line 1 "NONE"
	{te = p+1;}
#line 310 "wikitext_ragel.rl"
	{act = 22;}
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 1194 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr171;
	} else
		goto tr171;
	goto tr169;
tr171:
#line 1 "NONE"
	{te = p+1;}
#line 310 "wikitext_ragel.rl"
	{act = 22;}
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 1216 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr172;
	} else
		goto tr172;
	goto tr169;
tr172:
#line 1 "NONE"
	{te = p+1;}
#line 310 "wikitext_ragel.rl"
	{act = 22;}
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 1238 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st16;
	} else
		goto st16;
	goto tr169;
tr168:
#line 1 "NONE"
	{te = p+1;}
#line 461 "wikitext_ragel.rl"
	{act = 45;}
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 1260 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st113;
		case 45u: goto st113;
		case 47u: goto st113;
		case 64u: goto st113;
		case 92u: goto st113;
		case 126u: goto st113;
	}
	if ( (*p) < 65u ) {
		if ( (*p) > 37u ) {
			if ( 48u <= (*p) && (*p) <= 57u )
				goto st16;
		} else if ( (*p) >= 36u )
			goto st113;
	} else if ( (*p) > 90u ) {
		if ( (*p) > 95u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st16;
		} else if ( (*p) >= 94u )
			goto st113;
	} else
		goto st16;
	goto tr158;
tr134:
#line 1 "NONE"
	{te = p+1;}
#line 443 "wikitext_ragel.rl"
	{act = 43;}
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 1294 "wikitext_ragel.c"
	switch( (*p) ) {
		case 33u: goto st112;
		case 44u: goto st112;
		case 45u: goto st14;
		case 46u: goto tr134;
		case 63u: goto st112;
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 58u ) {
		if ( (*p) > 41u ) {
			if ( 48u <= (*p) && (*p) <= 57u )
				goto st14;
		} else if ( (*p) >= 40u )
			goto st112;
	} else if ( (*p) > 59u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st112;
	goto tr157;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 43u: goto st113;
		case 45u: goto st127;
		case 47u: goto st113;
		case 64u: goto st113;
		case 92u: goto st113;
		case 94u: goto st113;
		case 95u: goto st127;
		case 126u: goto st113;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st113;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st128;
		} else if ( (*p) >= 65u )
			goto st128;
	} else
		goto st128;
	goto tr173;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 43u: goto st113;
		case 45u: goto st127;
		case 47u: goto st126;
		case 64u: goto st113;
		case 92u: goto st113;
		case 94u: goto st113;
		case 95u: goto st127;
		case 126u: goto st113;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st113;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st128;
		} else if ( (*p) >= 65u )
			goto st128;
	} else
		goto st128;
	goto tr173;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	switch( (*p) ) {
		case 47u: goto st129;
		case 95u: goto st128;
	}
	if ( (*p) < 65u ) {
		if ( 45u <= (*p) && (*p) <= 57u )
			goto st128;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st128;
	} else
		goto st128;
	goto tr173;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 95u )
		goto st128;
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st128;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st128;
		} else if ( (*p) >= 65u )
			goto st128;
	} else
		goto st128;
	goto tr173;
tr136:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 1416 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr137:
#line 1 "NONE"
	{te = p+1;}
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 1441 "wikitext_ragel.c"
	switch( (*p) ) {
		case 47u: goto st19;
		case 66u: goto st49;
		case 69u: goto st59;
		case 78u: goto st61;
		case 80u: goto st67;
		case 83u: goto st70;
		case 84u: goto st76;
		case 98u: goto st49;
		case 101u: goto st59;
		case 110u: goto st61;
		case 112u: goto st78;
		case 115u: goto st70;
		case 116u: goto st76;
	}
	goto tr178;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 66u: goto st20;
		case 69u: goto st30;
		case 78u: goto st32;
		case 80u: goto st38;
		case 83u: goto st41;
		case 84u: goto st47;
		case 98u: goto st20;
		case 101u: goto st30;
		case 110u: goto st32;
		case 112u: goto st38;
		case 115u: goto st41;
		case 116u: goto st47;
	}
	goto tr23;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 76u: goto st21;
		case 108u: goto st21;
	}
	goto tr23;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 79u: goto st22;
		case 111u: goto st22;
	}
	goto tr23;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 67u: goto st23;
		case 99u: goto st23;
	}
	goto tr23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 75u: goto st24;
		case 107u: goto st24;
	}
	goto tr23;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 81u: goto st25;
		case 113u: goto st25;
	}
	goto tr23;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 85u: goto st26;
		case 117u: goto st26;
	}
	goto tr23;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 79u: goto st27;
		case 111u: goto st27;
	}
	goto tr23;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	switch( (*p) ) {
		case 84u: goto st28;
		case 116u: goto st28;
	}
	goto tr23;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 69u: goto st29;
		case 101u: goto st29;
	}
	goto tr23;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 62u )
		goto tr39;
	goto tr23;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 77u: goto st31;
		case 109u: goto st31;
	}
	goto tr23;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 62u )
		goto tr41;
	goto tr23;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 79u: goto st33;
		case 111u: goto st33;
	}
	goto tr23;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	switch( (*p) ) {
		case 87u: goto st34;
		case 119u: goto st34;
	}
	goto tr23;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 73u: goto st35;
		case 105u: goto st35;
	}
	goto tr23;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	switch( (*p) ) {
		case 75u: goto st36;
		case 107u: goto st36;
	}
	goto tr23;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 73u: goto st37;
		case 105u: goto st37;
	}
	goto tr23;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 62u )
		goto tr47;
	goto tr23;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 82u: goto st39;
		case 114u: goto st39;
	}
	goto tr23;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 69u: goto st40;
		case 101u: goto st40;
	}
	goto tr23;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 62u )
		goto tr50;
	goto tr23;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 84u: goto st42;
		case 116u: goto st42;
	}
	goto tr23;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 82u: goto st43;
		case 114u: goto st43;
	}
	goto tr23;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 79u: goto st44;
		case 111u: goto st44;
	}
	goto tr23;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 78u: goto st45;
		case 110u: goto st45;
	}
	goto tr23;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 71u: goto st46;
		case 103u: goto st46;
	}
	goto tr23;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 62u )
		goto tr56;
	goto tr23;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 84u: goto st48;
		case 116u: goto st48;
	}
	goto tr23;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) == 62u )
		goto tr58;
	goto tr23;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 76u: goto st50;
		case 108u: goto st50;
	}
	goto tr23;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 79u: goto st51;
		case 111u: goto st51;
	}
	goto tr23;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 67u: goto st52;
		case 99u: goto st52;
	}
	goto tr23;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 75u: goto st53;
		case 107u: goto st53;
	}
	goto tr23;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 81u: goto st54;
		case 113u: goto st54;
	}
	goto tr23;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 85u: goto st55;
		case 117u: goto st55;
	}
	goto tr23;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 79u: goto st56;
		case 111u: goto st56;
	}
	goto tr23;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 84u: goto st57;
		case 116u: goto st57;
	}
	goto tr23;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 69u: goto st58;
		case 101u: goto st58;
	}
	goto tr23;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 62u )
		goto tr68;
	goto tr23;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 77u: goto st60;
		case 109u: goto st60;
	}
	goto tr23;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 62u )
		goto tr70;
	goto tr23;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 79u: goto st62;
		case 111u: goto st62;
	}
	goto tr23;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 87u: goto st63;
		case 119u: goto st63;
	}
	goto tr23;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 73u: goto st64;
		case 105u: goto st64;
	}
	goto tr23;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 75u: goto st65;
		case 107u: goto st65;
	}
	goto tr23;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 73u: goto st66;
		case 105u: goto st66;
	}
	goto tr23;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	if ( (*p) == 62u )
		goto tr76;
	goto tr23;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 82u: goto st68;
		case 114u: goto st68;
	}
	goto tr23;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 69u: goto st69;
		case 101u: goto st69;
	}
	goto tr23;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	if ( (*p) == 62u )
		goto tr79;
	goto tr23;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 84u: goto st71;
		case 116u: goto st71;
	}
	goto tr23;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 82u: goto st72;
		case 114u: goto st72;
	}
	goto tr23;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 79u: goto st73;
		case 111u: goto st73;
	}
	goto tr23;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 78u: goto st74;
		case 110u: goto st74;
	}
	goto tr23;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 71u: goto st75;
		case 103u: goto st75;
	}
	goto tr23;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 62u )
		goto tr85;
	goto tr23;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 84u: goto st77;
		case 116u: goto st77;
	}
	goto tr23;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 62u )
		goto tr87;
	goto tr23;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 82u: goto st68;
		case 114u: goto st79;
	}
	goto tr23;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 69u: goto st69;
		case 101u: goto st80;
	}
	goto tr23;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 32u: goto st81;
		case 62u: goto tr79;
	}
	goto tr23;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	if ( (*p) == 108u )
		goto st82;
	goto tr23;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) == 97u )
		goto st83;
	goto tr23;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 110u )
		goto st84;
	goto tr23;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	if ( (*p) == 103u )
		goto st85;
	goto tr23;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	if ( (*p) == 61u )
		goto st86;
	goto tr23;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 34u )
		goto st87;
	goto tr23;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st88;
	} else if ( (*p) >= 65u )
		goto st88;
	goto tr23;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	if ( (*p) == 34u )
		goto st89;
	if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st88;
	} else if ( (*p) >= 65u )
		goto st88;
	goto tr23;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 62u )
		goto tr99;
	goto tr23;
tr138:
#line 46 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 2083 "wikitext_ragel.c"
	switch( (*p) ) {
		case 32u: goto st133;
		case 61u: goto tr138;
	}
	goto tr187;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( (*p) == 32u )
		goto st133;
	goto tr187;
tr139:
#line 46 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 2106 "wikitext_ragel.c"
	if ( (*p) == 32u )
		goto tr190;
	goto tr189;
tr140:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 2120 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr191;
		case 95u: goto st14;
		case 116u: goto tr191;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr191:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 2149 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 80u: goto tr192;
		case 95u: goto st14;
		case 112u: goto tr192;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr192:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 2178 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58u: goto st90;
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	if ( (*p) == 47u )
		goto st91;
	goto tr100;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	if ( (*p) == 47u )
		goto st92;
	goto tr100;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 45u: goto tr103;
		case 61u: goto tr103;
		case 95u: goto tr103;
		case 126u: goto tr103;
	}
	if ( (*p) < 64u ) {
		if ( (*p) < 42u ) {
			if ( 35u <= (*p) && (*p) <= 40u )
				goto tr103;
		} else if ( (*p) > 43u ) {
			if ( 47u <= (*p) && (*p) <= 57u )
				goto tr103;
		} else
			goto tr103;
	} else if ( (*p) > 90u ) {
		if ( (*p) < 194u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr103;
		} else if ( (*p) > 223u ) {
			if ( (*p) > 239u ) {
				if ( 240u <= (*p) && (*p) <= 244u )
					goto st96;
			} else if ( (*p) >= 224u )
				goto st95;
		} else
			goto st94;
	} else
		goto tr103;
	goto tr100;
tr103:
#line 1 "NONE"
	{te = p+1;}
#line 304 "wikitext_ragel.rl"
	{act = 21;}
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 2254 "wikitext_ragel.c"
	switch( (*p) ) {
		case 33u: goto st93;
		case 41u: goto st93;
		case 44u: goto st93;
		case 46u: goto st93;
		case 61u: goto tr103;
		case 63u: goto st93;
		case 95u: goto tr103;
		case 126u: goto tr103;
	}
	if ( (*p) < 97u ) {
		if ( (*p) < 58u ) {
			if ( 35u <= (*p) && (*p) <= 57u )
				goto tr103;
		} else if ( (*p) > 59u ) {
			if ( 64u <= (*p) && (*p) <= 90u )
				goto tr103;
		} else
			goto st93;
	} else if ( (*p) > 122u ) {
		if ( (*p) < 224u ) {
			if ( 194u <= (*p) && (*p) <= 223u )
				goto st94;
		} else if ( (*p) > 239u ) {
			if ( 240u <= (*p) && (*p) <= 244u )
				goto st96;
		} else
			goto st95;
	} else
		goto tr103;
	goto tr194;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 33u: goto st93;
		case 41u: goto st93;
		case 44u: goto st93;
		case 46u: goto st93;
		case 61u: goto tr103;
		case 63u: goto st93;
		case 95u: goto tr103;
		case 126u: goto tr103;
	}
	if ( (*p) < 97u ) {
		if ( (*p) < 58u ) {
			if ( 35u <= (*p) && (*p) <= 57u )
				goto tr103;
		} else if ( (*p) > 59u ) {
			if ( 64u <= (*p) && (*p) <= 90u )
				goto tr103;
		} else
			goto st93;
	} else if ( (*p) > 122u ) {
		if ( (*p) < 224u ) {
			if ( 194u <= (*p) && (*p) <= 223u )
				goto st94;
		} else if ( (*p) > 239u ) {
			if ( 240u <= (*p) && (*p) <= 244u )
				goto st96;
		} else
			goto st95;
	} else
		goto tr103;
	goto tr107;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr103;
	goto tr16;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st94;
	goto tr16;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st95;
	goto tr16;
tr141:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
#line 2352 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr195;
		case 95u: goto st14;
		case 116u: goto tr195;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr195:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 2381 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr196;
		case 95u: goto st14;
		case 116u: goto tr196;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr196:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 2410 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 80u: goto tr197;
		case 95u: goto st14;
		case 112u: goto tr197;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr197:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 2439 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58u: goto st90;
		case 64u: goto st15;
		case 83u: goto tr192;
		case 95u: goto st14;
		case 115u: goto tr192;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr142:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 2469 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 65u: goto tr198;
		case 95u: goto st14;
		case 97u: goto tr198;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 98u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 66u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr198:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 2498 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 73u: goto tr199;
		case 95u: goto st14;
		case 105u: goto tr199;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr199:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 2527 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 76u: goto tr200;
		case 95u: goto st14;
		case 108u: goto tr200;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr200:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 2556 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr201;
		case 95u: goto st14;
		case 116u: goto tr201;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr201:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 2585 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 79u: goto tr202;
		case 95u: goto st14;
		case 111u: goto tr202;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr202:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 2614 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58u: goto st97;
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 95u )
		goto st98;
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st98;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st98;
		} else if ( (*p) >= 65u )
			goto st98;
	} else
		goto st98;
	goto tr100;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 64u: goto st99;
		case 95u: goto st98;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st98;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st98;
		} else if ( (*p) >= 65u )
			goto st98;
	} else
		goto st98;
	goto tr100;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st100;
	} else
		goto st100;
	goto tr100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 46u )
		goto st101;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st100;
	} else
		goto st100;
	goto tr16;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st102;
	} else
		goto st102;
	goto tr16;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 46u )
		goto st101;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr114;
	} else
		goto tr114;
	goto tr16;
tr114:
#line 1 "NONE"
	{te = p+1;}
#line 304 "wikitext_ragel.rl"
	{act = 21;}
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 2736 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st101;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr204;
	} else
		goto tr204;
	goto tr194;
tr204:
#line 1 "NONE"
	{te = p+1;}
#line 304 "wikitext_ragel.rl"
	{act = 21;}
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 2758 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st101;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr205;
	} else
		goto tr205;
	goto tr194;
tr205:
#line 1 "NONE"
	{te = p+1;}
#line 304 "wikitext_ragel.rl"
	{act = 21;}
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 2780 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st101;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr206;
	} else
		goto tr206;
	goto tr194;
tr206:
#line 1 "NONE"
	{te = p+1;}
#line 304 "wikitext_ragel.rl"
	{act = 21;}
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 2802 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st101;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st100;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st100;
	} else
		goto st100;
	goto tr194;
tr143:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 2824 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 86u: goto tr207;
		case 95u: goto st14;
		case 118u: goto tr207;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
tr207:
#line 1 "NONE"
	{te = p+1;}
#line 449 "wikitext_ragel.rl"
	{act = 44;}
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 2853 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 78u: goto tr192;
		case 95u: goto st14;
		case 110u: goto tr192;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr136;
		} else if ( (*p) >= 65u )
			goto tr136;
	} else
		goto tr136;
	goto tr177;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 91u )
		goto tr209;
	goto tr208;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 93u )
		goto tr211;
	goto tr210;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) == 123u )
		goto tr213;
	goto tr212;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	if ( (*p) == 125u )
		goto tr215;
	goto tr214;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr115;
	goto st0;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st105;
	goto st0;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr118;
	goto st0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st107;
	goto st0;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st108;
	goto st0;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr121;
	goto st0;
	}
	_test_eof109: cs = 109; goto _test_eof;
	_test_eof110: cs = 110; goto _test_eof;
	_test_eof111: cs = 111; goto _test_eof;
	_test_eof112: cs = 112; goto _test_eof;
	_test_eof113: cs = 113; goto _test_eof;
	_test_eof114: cs = 114; goto _test_eof;
	_test_eof1: cs = 1; goto _test_eof;
	_test_eof2: cs = 2; goto _test_eof;
	_test_eof3: cs = 3; goto _test_eof;
	_test_eof4: cs = 4; goto _test_eof;
	_test_eof5: cs = 5; goto _test_eof;
	_test_eof6: cs = 6; goto _test_eof;
	_test_eof7: cs = 7; goto _test_eof;
	_test_eof8: cs = 8; goto _test_eof;
	_test_eof9: cs = 9; goto _test_eof;
	_test_eof10: cs = 10; goto _test_eof;
	_test_eof11: cs = 11; goto _test_eof;
	_test_eof12: cs = 12; goto _test_eof;
	_test_eof13: cs = 13; goto _test_eof;
	_test_eof115: cs = 115; goto _test_eof;
	_test_eof116: cs = 116; goto _test_eof;
	_test_eof117: cs = 117; goto _test_eof;
	_test_eof118: cs = 118; goto _test_eof;
	_test_eof119: cs = 119; goto _test_eof;
	_test_eof14: cs = 14; goto _test_eof;
	_test_eof15: cs = 15; goto _test_eof;
	_test_eof16: cs = 16; goto _test_eof;
	_test_eof17: cs = 17; goto _test_eof;
	_test_eof18: cs = 18; goto _test_eof;
	_test_eof120: cs = 120; goto _test_eof;
	_test_eof121: cs = 121; goto _test_eof;
	_test_eof122: cs = 122; goto _test_eof;
	_test_eof123: cs = 123; goto _test_eof;
	_test_eof124: cs = 124; goto _test_eof;
	_test_eof125: cs = 125; goto _test_eof;
	_test_eof126: cs = 126; goto _test_eof;
	_test_eof127: cs = 127; goto _test_eof;
	_test_eof128: cs = 128; goto _test_eof;
	_test_eof129: cs = 129; goto _test_eof;
	_test_eof130: cs = 130; goto _test_eof;
	_test_eof131: cs = 131; goto _test_eof;
	_test_eof19: cs = 19; goto _test_eof;
	_test_eof20: cs = 20; goto _test_eof;
	_test_eof21: cs = 21; goto _test_eof;
	_test_eof22: cs = 22; goto _test_eof;
	_test_eof23: cs = 23; goto _test_eof;
	_test_eof24: cs = 24; goto _test_eof;
	_test_eof25: cs = 25; goto _test_eof;
	_test_eof26: cs = 26; goto _test_eof;
	_test_eof27: cs = 27; goto _test_eof;
	_test_eof28: cs = 28; goto _test_eof;
	_test_eof29: cs = 29; goto _test_eof;
	_test_eof30: cs = 30; goto _test_eof;
	_test_eof31: cs = 31; goto _test_eof;
	_test_eof32: cs = 32; goto _test_eof;
	_test_eof33: cs = 33; goto _test_eof;
	_test_eof34: cs = 34; goto _test_eof;
	_test_eof35: cs = 35; goto _test_eof;
	_test_eof36: cs = 36; goto _test_eof;
	_test_eof37: cs = 37; goto _test_eof;
	_test_eof38: cs = 38; goto _test_eof;
	_test_eof39: cs = 39; goto _test_eof;
	_test_eof40: cs = 40; goto _test_eof;
	_test_eof41: cs = 41; goto _test_eof;
	_test_eof42: cs = 42; goto _test_eof;
	_test_eof43: cs = 43; goto _test_eof;
	_test_eof44: cs = 44; goto _test_eof;
	_test_eof45: cs = 45; goto _test_eof;
	_test_eof46: cs = 46; goto _test_eof;
	_test_eof47: cs = 47; goto _test_eof;
	_test_eof48: cs = 48; goto _test_eof;
	_test_eof49: cs = 49; goto _test_eof;
	_test_eof50: cs = 50; goto _test_eof;
	_test_eof51: cs = 51; goto _test_eof;
	_test_eof52: cs = 52; goto _test_eof;
	_test_eof53: cs = 53; goto _test_eof;
	_test_eof54: cs = 54; goto _test_eof;
	_test_eof55: cs = 55; goto _test_eof;
	_test_eof56: cs = 56; goto _test_eof;
	_test_eof57: cs = 57; goto _test_eof;
	_test_eof58: cs = 58; goto _test_eof;
	_test_eof59: cs = 59; goto _test_eof;
	_test_eof60: cs = 60; goto _test_eof;
	_test_eof61: cs = 61; goto _test_eof;
	_test_eof62: cs = 62; goto _test_eof;
	_test_eof63: cs = 63; goto _test_eof;
	_test_eof64: cs = 64; goto _test_eof;
	_test_eof65: cs = 65; goto _test_eof;
	_test_eof66: cs = 66; goto _test_eof;
	_test_eof67: cs = 67; goto _test_eof;
	_test_eof68: cs = 68; goto _test_eof;
	_test_eof69: cs = 69; goto _test_eof;
	_test_eof70: cs = 70; goto _test_eof;
	_test_eof71: cs = 71; goto _test_eof;
	_test_eof72: cs = 72; goto _test_eof;
	_test_eof73: cs = 73; goto _test_eof;
	_test_eof74: cs = 74; goto _test_eof;
	_test_eof75: cs = 75; goto _test_eof;
	_test_eof76: cs = 76; goto _test_eof;
	_test_eof77: cs = 77; goto _test_eof;
	_test_eof78: cs = 78; goto _test_eof;
	_test_eof79: cs = 79; goto _test_eof;
	_test_eof80: cs = 80; goto _test_eof;
	_test_eof81: cs = 81; goto _test_eof;
	_test_eof82: cs = 82; goto _test_eof;
	_test_eof83: cs = 83; goto _test_eof;
	_test_eof84: cs = 84; goto _test_eof;
	_test_eof85: cs = 85; goto _test_eof;
	_test_eof86: cs = 86; goto _test_eof;
	_test_eof87: cs = 87; goto _test_eof;
	_test_eof88: cs = 88; goto _test_eof;
	_test_eof89: cs = 89; goto _test_eof;
	_test_eof132: cs = 132; goto _test_eof;
	_test_eof133: cs = 133; goto _test_eof;
	_test_eof134: cs = 134; goto _test_eof;
	_test_eof135: cs = 135; goto _test_eof;
	_test_eof136: cs = 136; goto _test_eof;
	_test_eof137: cs = 137; goto _test_eof;
	_test_eof90: cs = 90; goto _test_eof;
	_test_eof91: cs = 91; goto _test_eof;
	_test_eof92: cs = 92; goto _test_eof;
	_test_eof138: cs = 138; goto _test_eof;
	_test_eof93: cs = 93; goto _test_eof;
	_test_eof94: cs = 94; goto _test_eof;
	_test_eof95: cs = 95; goto _test_eof;
	_test_eof96: cs = 96; goto _test_eof;
	_test_eof139: cs = 139; goto _test_eof;
	_test_eof140: cs = 140; goto _test_eof;
	_test_eof141: cs = 141; goto _test_eof;
	_test_eof142: cs = 142; goto _test_eof;
	_test_eof143: cs = 143; goto _test_eof;
	_test_eof144: cs = 144; goto _test_eof;
	_test_eof145: cs = 145; goto _test_eof;
	_test_eof146: cs = 146; goto _test_eof;
	_test_eof147: cs = 147; goto _test_eof;
	_test_eof148: cs = 148; goto _test_eof;
	_test_eof97: cs = 97; goto _test_eof;
	_test_eof98: cs = 98; goto _test_eof;
	_test_eof99: cs = 99; goto _test_eof;
	_test_eof100: cs = 100; goto _test_eof;
	_test_eof101: cs = 101; goto _test_eof;
	_test_eof102: cs = 102; goto _test_eof;
	_test_eof149: cs = 149; goto _test_eof;
	_test_eof150: cs = 150; goto _test_eof;
	_test_eof151: cs = 151; goto _test_eof;
	_test_eof152: cs = 152; goto _test_eof;
	_test_eof153: cs = 153; goto _test_eof;
	_test_eof154: cs = 154; goto _test_eof;
	_test_eof155: cs = 155; goto _test_eof;
	_test_eof156: cs = 156; goto _test_eof;
	_test_eof157: cs = 157; goto _test_eof;
	_test_eof158: cs = 158; goto _test_eof;
	_test_eof103: cs = 103; goto _test_eof;
	_test_eof104: cs = 104; goto _test_eof;
	_test_eof105: cs = 105; goto _test_eof;
	_test_eof106: cs = 106; goto _test_eof;
	_test_eof107: cs = 107; goto _test_eof;
	_test_eof108: cs = 108; goto _test_eof;

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 110: goto tr153;
	case 111: goto tr155;
	case 112: goto tr157;
	case 113: goto tr158;
	case 114: goto tr159;
	case 1: goto tr0;
	case 2: goto tr0;
	case 3: goto tr0;
	case 4: goto tr0;
	case 5: goto tr0;
	case 6: goto tr0;
	case 7: goto tr0;
	case 8: goto tr0;
	case 9: goto tr0;
	case 10: goto tr0;
	case 11: goto tr0;
	case 12: goto tr0;
	case 13: goto tr0;
	case 115: goto tr163;
	case 116: goto tr163;
	case 117: goto tr163;
	case 118: goto tr163;
	case 119: goto tr158;
	case 14: goto tr16;
	case 15: goto tr16;
	case 16: goto tr16;
	case 17: goto tr16;
	case 18: goto tr16;
	case 120: goto tr169;
	case 121: goto tr169;
	case 122: goto tr169;
	case 123: goto tr169;
	case 124: goto tr158;
	case 125: goto tr157;
	case 126: goto tr173;
	case 127: goto tr173;
	case 128: goto tr173;
	case 129: goto tr173;
	case 130: goto tr177;
	case 131: goto tr178;
	case 19: goto tr23;
	case 20: goto tr23;
	case 21: goto tr23;
	case 22: goto tr23;
	case 23: goto tr23;
	case 24: goto tr23;
	case 25: goto tr23;
	case 26: goto tr23;
	case 27: goto tr23;
	case 28: goto tr23;
	case 29: goto tr23;
	case 30: goto tr23;
	case 31: goto tr23;
	case 32: goto tr23;
	case 33: goto tr23;
	case 34: goto tr23;
	case 35: goto tr23;
	case 36: goto tr23;
	case 37: goto tr23;
	case 38: goto tr23;
	case 39: goto tr23;
	case 40: goto tr23;
	case 41: goto tr23;
	case 42: goto tr23;
	case 43: goto tr23;
	case 44: goto tr23;
	case 45: goto tr23;
	case 46: goto tr23;
	case 47: goto tr23;
	case 48: goto tr23;
	case 49: goto tr23;
	case 50: goto tr23;
	case 51: goto tr23;
	case 52: goto tr23;
	case 53: goto tr23;
	case 54: goto tr23;
	case 55: goto tr23;
	case 56: goto tr23;
	case 57: goto tr23;
	case 58: goto tr23;
	case 59: goto tr23;
	case 60: goto tr23;
	case 61: goto tr23;
	case 62: goto tr23;
	case 63: goto tr23;
	case 64: goto tr23;
	case 65: goto tr23;
	case 66: goto tr23;
	case 67: goto tr23;
	case 68: goto tr23;
	case 69: goto tr23;
	case 70: goto tr23;
	case 71: goto tr23;
	case 72: goto tr23;
	case 73: goto tr23;
	case 74: goto tr23;
	case 75: goto tr23;
	case 76: goto tr23;
	case 77: goto tr23;
	case 78: goto tr23;
	case 79: goto tr23;
	case 80: goto tr23;
	case 81: goto tr23;
	case 82: goto tr23;
	case 83: goto tr23;
	case 84: goto tr23;
	case 85: goto tr23;
	case 86: goto tr23;
	case 87: goto tr23;
	case 88: goto tr23;
	case 89: goto tr23;
	case 132: goto tr187;
	case 133: goto tr187;
	case 134: goto tr189;
	case 135: goto tr177;
	case 136: goto tr177;
	case 137: goto tr177;
	case 90: goto tr100;
	case 91: goto tr100;
	case 92: goto tr100;
	case 138: goto tr194;
	case 93: goto tr107;
	case 94: goto tr16;
	case 95: goto tr16;
	case 96: goto tr16;
	case 139: goto tr177;
	case 140: goto tr177;
	case 141: goto tr177;
	case 142: goto tr177;
	case 143: goto tr177;
	case 144: goto tr177;
	case 145: goto tr177;
	case 146: goto tr177;
	case 147: goto tr177;
	case 148: goto tr177;
	case 97: goto tr100;
	case 98: goto tr100;
	case 99: goto tr100;
	case 100: goto tr16;
	case 101: goto tr16;
	case 102: goto tr16;
	case 149: goto tr194;
	case 150: goto tr194;
	case 151: goto tr194;
	case 152: goto tr194;
	case 153: goto tr177;
	case 154: goto tr177;
	case 155: goto tr208;
	case 156: goto tr210;
	case 157: goto tr212;
	case 158: goto tr214;
	}
	}

	_out: {}
	}

#line 533 "wikitext_ragel.rl"
    if (cs == wikitext_error)
        rb_raise(eWikitextParserError, "failed before finding a token");
    else if (out->type == NO_TOKEN)
        rb_raise(eWikitextParserError, "failed to produce a token");
}
