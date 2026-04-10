
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
static const int wikitext_start = 135;
static const int wikitext_first_final = 135;
static const int wikitext_error = 0;

static const int wikitext_en_main = 135;


#line 533 "wikitext_ragel.rl"


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

#line 575 "wikitext_ragel.rl"
    
#line 106 "wikitext_ragel.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 419 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(AMP);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr3:
#line 407 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DECIMAL_ENTITY);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr5:
#line 401 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(HEX_ENTITY);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr7:
#line 395 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NAMED_ENTITY);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr11:
#line 389 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(AMP_ENTITY);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr15:
#line 383 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT_ENTITY);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr16:
#line 1 "NONE"
	{	switch( act ) {
	case 20:
	{{p = ((te))-1;}
            EMIT(HR);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 21:
	{{p = ((te))-1;}
            EMIT(BR_CLEAR);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 22:
	{{p = ((te))-1;}
            EMIT(BR);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 26:
	{{p = ((te))-1;}
            EMIT(URI);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 27:
	{{p = ((te))-1;}
            EMIT(MAIL);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 41:
	{{p = ((te))-1;}
            EMIT(LESS);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 50:
	{{p = ((te))-1;}
            EMIT(SPECIAL_URI_CHARS);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 51:
	{{p = ((te))-1;}
            EMIT(ALNUM);
            {p++; cs = 135; goto _out;}
        }
	break;
	case 52:
	{{p = ((te))-1;}
            EMIT(PRINTABLE);
            {p++; cs = 135; goto _out;}
        }
	break;
	}
	}
	goto st135;
tr23:
#line 425 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(LESS);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr39:
#line 134 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr41:
#line 176 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr47:
#line 104 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr50:
#line 122 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr55:
#line 276 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SPAN_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr60:
#line 164 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr62:
#line 194 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr73:
#line 128 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr88:
#line 170 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr94:
#line 98 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr97:
#line 110 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr102:
#line 270 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SPAN_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr107:
#line 158 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr109:
#line 188 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr121:
#line 116 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr122:
#line 492 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(ALNUM);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr129:
#line 335 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(URI);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr137:
#line 449 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(IMG_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr144:
#line 437 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_START_HTTP);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr147:
#line 443 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_START_HTTPS);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr148:
#line 56 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 1)) & 0x1f) << 6 |
            (*p & 0x3f);
    }
#line 524 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr151:
#line 62 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 2)) & 0x0f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
#line 524 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr154:
#line 69 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 3)) & 0x07) << 18 |
            ((uint32_t)(*(p - 2)) & 0x3f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
#line 524 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr155:
#line 51 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
#line 524 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr156:
#line 473 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 135; goto _out;}
        }}
#line 51 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
	goto st135;
tr160:
#line 413 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr161:
#line 226 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(OL);
            else
                EMIT(PRINTABLE);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr165:
#line 239 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(UL);
            else
                EMIT(PRINTABLE);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr180:
#line 182 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr182:
#line 365 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SEPARATOR);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr187:
#line 473 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr188:
#line 473 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr189:
#line 214 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
            {
                REWIND();
                EMIT(PRE);
            }
            else
                EMIT(SPACE);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr191:
#line 486 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(SPECIAL_URI_CHARS);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr192:
#line 504 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PRINTABLE);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr193:
#line 419 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(AMP);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr197:
#line 140 "wikitext_ragel.rl"
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
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr201:
#line 140 "wikitext_ragel.rl"
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
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr206:
#line 252 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(HR);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr228:
#line 341 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(MAIL);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr232:
#line 347 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PATH);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr236:
#line 492 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(ALNUM);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr237:
#line 425 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LESS);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr246:
#line 264 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(BR);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr247:
#line 258 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(BR_CLEAR);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr248:
#line 282 "wikitext_ragel.rl"
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
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr250:
#line 201 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr251:
#line 201 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr255:
#line 335 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(URI);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr269:
#line 371 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr270:
#line 353 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr271:
#line 377 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr272:
#line 359 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr273:
#line 461 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LEFT_CURLY);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr275:
#line 449 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(IMG_START);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr277:
#line 467 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(RIGHT_CURLY);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
tr278:
#line 455 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_END);
            {p++; cs = 135; goto _out;}
        }}
	goto st135;
st135:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 1 "NONE"
	{ts = p;}
#line 767 "wikitext_ragel.c"
	switch( (*p) ) {
		case 10u: goto tr156;
		case 13u: goto tr157;
		case 32u: goto tr158;
		case 33u: goto st138;
		case 34u: goto tr160;
		case 35u: goto tr161;
		case 38u: goto tr163;
		case 39u: goto st141;
		case 42u: goto tr165;
		case 43u: goto st139;
		case 45u: goto tr166;
		case 46u: goto tr167;
		case 47u: goto st176;
		case 60u: goto tr170;
		case 61u: goto tr171;
		case 62u: goto tr172;
		case 64u: goto st139;
		case 70u: goto tr173;
		case 72u: goto tr174;
		case 77u: goto tr175;
		case 83u: goto tr176;
		case 91u: goto st208;
		case 92u: goto st139;
		case 93u: goto st209;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 96u: goto tr180;
		case 102u: goto tr173;
		case 104u: goto tr174;
		case 109u: goto tr175;
		case 115u: goto tr176;
		case 123u: goto st210;
		case 124u: goto tr182;
		case 125u: goto st212;
		case 126u: goto st139;
		case 127u: goto tr155;
	}
	if ( (*p) < 58u ) {
		if ( (*p) < 36u ) {
			if ( 1u <= (*p) && (*p) <= 31u )
				goto tr155;
		} else if ( (*p) > 37u ) {
			if ( (*p) > 44u ) {
				if ( 48u <= (*p) && (*p) <= 57u )
					goto tr169;
			} else if ( (*p) >= 40u )
				goto st138;
		} else
			goto st139;
	} else if ( (*p) > 63u ) {
		if ( (*p) < 194u ) {
			if ( 65u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) > 223u ) {
			if ( (*p) > 239u ) {
				if ( 240u <= (*p) && (*p) <= 244u )
					goto st132;
			} else if ( (*p) >= 224u )
				goto st130;
		} else
			goto st129;
	} else
		goto st138;
	goto st0;
st0:
cs = 0;
	goto _out;
tr157:
#line 51 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 846 "wikitext_ragel.c"
	if ( (*p) == 10u )
		goto tr188;
	goto tr187;
tr158:
#line 46 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 860 "wikitext_ragel.c"
	if ( (*p) == 32u )
		goto st137;
	goto tr189;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 33u: goto st138;
		case 44u: goto st138;
		case 46u: goto st138;
		case 63u: goto st138;
	}
	if ( (*p) > 41u ) {
		if ( 58u <= (*p) && (*p) <= 59u )
			goto st138;
	} else if ( (*p) >= 40u )
		goto st138;
	goto tr191;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto st139;
		case 47u: goto st139;
		case 64u: goto st139;
		case 92u: goto st139;
		case 126u: goto st139;
	}
	if ( (*p) > 37u ) {
		if ( 94u <= (*p) && (*p) <= 95u )
			goto st139;
	} else if ( (*p) >= 36u )
		goto st139;
	goto tr192;
tr163:
#line 1 "NONE"
	{te = p+1;}
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 906 "wikitext_ragel.c"
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
	goto tr193;
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
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 39u )
		goto st142;
	goto tr197;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 39u )
		goto st143;
	goto tr197;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 39u )
		goto st144;
	goto tr197;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 39u )
		goto tr201;
	goto tr197;
tr166:
#line 1 "NONE"
	{te = p+1;}
#line 504 "wikitext_ragel.rl"
	{act = 52;}
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 1143 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr202;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr192;
tr202:
#line 1 "NONE"
	{te = p+1;}
#line 504 "wikitext_ragel.rl"
	{act = 52;}
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 1176 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr204;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr192;
tr204:
#line 1 "NONE"
	{te = p+1;}
#line 504 "wikitext_ragel.rl"
	{act = 52;}
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 1209 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr205;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr192;
tr205:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 1242 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr207;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr207:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 1275 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr208;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr208:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 1308 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr209;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr209:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 1341 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr210;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr210:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 1374 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr211;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr211:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 1407 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr212;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr212:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 1440 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr213;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr213:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 1473 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr214;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr214:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 1506 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr215;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr215:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 1539 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr216;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr216:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 1572 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr217;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr217:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 1605 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr218;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr218:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 1638 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr219;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr219:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 1671 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr220;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr220:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 1704 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr221;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr221:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 1737 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr222;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr222:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 1770 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr223;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr223:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 1803 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr224;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr224:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 1836 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr225;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr225:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 1869 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr226;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr226:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 1902 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr227;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr206;
tr179:
#line 1 "NONE"
	{te = p+1;}
#line 504 "wikitext_ragel.rl"
	{act = 52;}
	goto st169;
tr227:
#line 1 "NONE"
	{te = p+1;}
#line 252 "wikitext_ragel.rl"
	{act = 20;}
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 1941 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto tr179;
		case 47u: goto st139;
		case 64u: goto tr203;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto tr179;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st14;
	goto tr16;
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
#line 341 "wikitext_ragel.rl"
	{act = 27;}
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 2050 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr229;
	} else
		goto tr229;
	goto tr228;
tr229:
#line 1 "NONE"
	{te = p+1;}
#line 341 "wikitext_ragel.rl"
	{act = 27;}
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 2072 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr230;
	} else
		goto tr230;
	goto tr228;
tr230:
#line 1 "NONE"
	{te = p+1;}
#line 341 "wikitext_ragel.rl"
	{act = 27;}
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 2094 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st17;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st16;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr231;
	} else
		goto tr231;
	goto tr228;
tr231:
#line 1 "NONE"
	{te = p+1;}
#line 341 "wikitext_ragel.rl"
	{act = 27;}
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 2116 "wikitext_ragel.c"
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
	goto tr228;
tr203:
#line 1 "NONE"
	{te = p+1;}
#line 504 "wikitext_ragel.rl"
	{act = 52;}
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 2138 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto st139;
		case 47u: goto st139;
		case 64u: goto st139;
		case 92u: goto st139;
		case 126u: goto st139;
	}
	if ( (*p) < 65u ) {
		if ( (*p) > 37u ) {
			if ( 48u <= (*p) && (*p) <= 57u )
				goto st16;
		} else if ( (*p) >= 36u )
			goto st139;
	} else if ( (*p) > 90u ) {
		if ( (*p) > 95u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st16;
		} else if ( (*p) >= 94u )
			goto st139;
	} else
		goto st16;
	goto tr192;
tr167:
#line 1 "NONE"
	{te = p+1;}
#line 486 "wikitext_ragel.rl"
	{act = 50;}
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 2172 "wikitext_ragel.c"
	switch( (*p) ) {
		case 33u: goto st138;
		case 44u: goto st138;
		case 45u: goto st14;
		case 46u: goto tr167;
		case 63u: goto st138;
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 58u ) {
		if ( (*p) > 41u ) {
			if ( 48u <= (*p) && (*p) <= 57u )
				goto st14;
		} else if ( (*p) >= 40u )
			goto st138;
	} else if ( (*p) > 59u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st14;
		} else if ( (*p) >= 65u )
			goto st14;
	} else
		goto st138;
	goto tr191;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto st177;
		case 47u: goto st139;
		case 64u: goto st139;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto st177;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st178;
		} else if ( (*p) >= 65u )
			goto st178;
	} else
		goto st178;
	goto tr232;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 43u: goto st139;
		case 45u: goto st177;
		case 47u: goto st176;
		case 64u: goto st139;
		case 92u: goto st139;
		case 94u: goto st139;
		case 95u: goto st177;
		case 126u: goto st139;
	}
	if ( (*p) < 46u ) {
		if ( 36u <= (*p) && (*p) <= 37u )
			goto st139;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st178;
		} else if ( (*p) >= 65u )
			goto st178;
	} else
		goto st178;
	goto tr232;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 47u: goto st179;
		case 95u: goto st178;
	}
	if ( (*p) < 65u ) {
		if ( 45u <= (*p) && (*p) <= 57u )
			goto st178;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st178;
	} else
		goto st178;
	goto tr232;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) == 95u )
		goto st178;
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st178;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st178;
		} else if ( (*p) >= 65u )
			goto st178;
	} else
		goto st178;
	goto tr232;
tr169:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 2294 "wikitext_ragel.c"
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
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr170:
#line 1 "NONE"
	{te = p+1;}
#line 425 "wikitext_ragel.rl"
	{act = 41;}
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 2321 "wikitext_ragel.c"
	switch( (*p) ) {
		case 47u: goto st19;
		case 66u: goto st52;
		case 69u: goto st73;
		case 78u: goto st75;
		case 80u: goto st81;
		case 83u: goto st84;
		case 84u: goto st93;
		case 98u: goto st52;
		case 101u: goto st73;
		case 110u: goto st75;
		case 112u: goto st95;
		case 115u: goto st84;
		case 116u: goto st93;
	}
	goto tr237;
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
		case 84u: goto st50;
		case 98u: goto st20;
		case 101u: goto st30;
		case 110u: goto st32;
		case 112u: goto st38;
		case 115u: goto st41;
		case 116u: goto st50;
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
		case 80u: goto st42;
		case 84u: goto st45;
		case 112u: goto st42;
		case 116u: goto st45;
	}
	goto tr23;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 65u: goto st43;
		case 97u: goto st43;
	}
	goto tr23;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 78u: goto st44;
		case 110u: goto st44;
	}
	goto tr23;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 62u )
		goto tr55;
	goto tr23;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 82u: goto st46;
		case 114u: goto st46;
	}
	goto tr23;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 79u: goto st47;
		case 111u: goto st47;
	}
	goto tr23;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 78u: goto st48;
		case 110u: goto st48;
	}
	goto tr23;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 71u: goto st49;
		case 103u: goto st49;
	}
	goto tr23;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 62u )
		goto tr60;
	goto tr23;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 84u: goto st51;
		case 116u: goto st51;
	}
	goto tr23;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( (*p) == 62u )
		goto tr62;
	goto tr23;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 76u: goto st53;
		case 82u: goto st62;
		case 108u: goto st53;
		case 114u: goto st62;
	}
	goto tr23;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 79u: goto st54;
		case 111u: goto st54;
	}
	goto tr23;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 67u: goto st55;
		case 99u: goto st55;
	}
	goto tr23;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 75u: goto st56;
		case 107u: goto st56;
	}
	goto tr23;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 81u: goto st57;
		case 113u: goto st57;
	}
	goto tr23;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 85u: goto st58;
		case 117u: goto st58;
	}
	goto tr23;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 79u: goto st59;
		case 111u: goto st59;
	}
	goto tr23;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 84u: goto st60;
		case 116u: goto st60;
	}
	goto tr23;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 69u: goto st61;
		case 101u: goto st61;
	}
	goto tr23;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	if ( (*p) == 62u )
		goto tr73;
	goto tr23;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 32u: goto st65;
		case 62u: goto tr77;
	}
	if ( (*p) < 58u ) {
		if ( (*p) > 13u ) {
			if ( 33u <= (*p) && (*p) <= 47u )
				goto st64;
		} else if ( (*p) >= 9u )
			goto st63;
	} else if ( (*p) > 64u ) {
		if ( (*p) > 96u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st64;
		} else if ( (*p) >= 91u )
			goto st64;
	} else
		goto st64;
	goto tr23;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 32u: goto st63;
		case 62u: goto tr77;
	}
	if ( (*p) < 58u ) {
		if ( (*p) > 13u ) {
			if ( 33u <= (*p) && (*p) <= 47u )
				goto st64;
		} else if ( (*p) >= 9u )
			goto st63;
	} else if ( (*p) > 64u ) {
		if ( (*p) > 96u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st64;
		} else if ( (*p) >= 91u )
			goto st64;
	} else
		goto st64;
	goto tr23;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	if ( (*p) == 62u )
		goto tr77;
	if ( (*p) < 58u ) {
		if ( 33u <= (*p) && (*p) <= 47u )
			goto st64;
	} else if ( (*p) > 64u ) {
		if ( (*p) > 96u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st64;
		} else if ( (*p) >= 91u )
			goto st64;
	} else
		goto st64;
	goto tr16;
tr77:
#line 1 "NONE"
	{te = p+1;}
#line 264 "wikitext_ragel.rl"
	{act = 22;}
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 2797 "wikitext_ragel.c"
	if ( (*p) == 62u )
		goto tr77;
	if ( (*p) < 58u ) {
		if ( 33u <= (*p) && (*p) <= 47u )
			goto st64;
	} else if ( (*p) > 64u ) {
		if ( (*p) > 96u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st64;
		} else if ( (*p) >= 91u )
			goto st64;
	} else
		goto st64;
	goto tr246;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 32u: goto st63;
		case 62u: goto tr77;
		case 67u: goto st66;
		case 99u: goto st66;
	}
	if ( (*p) < 58u ) {
		if ( (*p) > 13u ) {
			if ( 33u <= (*p) && (*p) <= 47u )
				goto st64;
		} else if ( (*p) >= 9u )
			goto st63;
	} else if ( (*p) > 64u ) {
		if ( (*p) > 96u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st64;
		} else if ( (*p) >= 91u )
			goto st64;
	} else
		goto st64;
	goto tr23;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 76u: goto st67;
		case 108u: goto st67;
	}
	goto tr23;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 69u: goto st68;
		case 101u: goto st68;
	}
	goto tr23;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 65u: goto st69;
		case 97u: goto st69;
	}
	goto tr23;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 82u: goto st70;
		case 114u: goto st70;
	}
	goto tr23;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 62u )
		goto tr84;
	if ( (*p) < 65u ) {
		if ( (*p) < 48u ) {
			if ( 33u <= (*p) && (*p) <= 47u )
				goto st70;
		} else if ( (*p) > 57u ) {
			if ( 58u <= (*p) && (*p) <= 64u )
				goto st70;
		} else
			goto st71;
	} else if ( (*p) > 90u ) {
		if ( (*p) < 97u ) {
			if ( 91u <= (*p) && (*p) <= 96u )
				goto st70;
		} else if ( (*p) > 122u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st70;
		} else
			goto st71;
	} else
		goto st71;
	goto tr16;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 62u )
		goto tr86;
	if ( (*p) < 65u ) {
		if ( (*p) < 48u ) {
			if ( 33u <= (*p) && (*p) <= 47u )
				goto st72;
		} else if ( (*p) > 57u ) {
			if ( 58u <= (*p) && (*p) <= 64u )
				goto st72;
		} else
			goto st71;
	} else if ( (*p) > 90u ) {
		if ( (*p) < 97u ) {
			if ( 91u <= (*p) && (*p) <= 96u )
				goto st72;
		} else if ( (*p) > 122u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st72;
		} else
			goto st71;
	} else
		goto st71;
	goto tr16;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 62u )
		goto tr86;
	if ( (*p) < 58u ) {
		if ( 33u <= (*p) && (*p) <= 47u )
			goto st72;
	} else if ( (*p) > 64u ) {
		if ( (*p) > 96u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st72;
		} else if ( (*p) >= 91u )
			goto st72;
	} else
		goto st72;
	goto tr16;
tr86:
#line 1 "NONE"
	{te = p+1;}
#line 258 "wikitext_ragel.rl"
	{act = 21;}
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 2955 "wikitext_ragel.c"
	if ( (*p) == 62u )
		goto tr86;
	if ( (*p) < 58u ) {
		if ( 33u <= (*p) && (*p) <= 47u )
			goto st72;
	} else if ( (*p) > 64u ) {
		if ( (*p) > 96u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st72;
		} else if ( (*p) >= 91u )
			goto st72;
	} else
		goto st72;
	goto tr247;
tr84:
#line 1 "NONE"
	{te = p+1;}
#line 258 "wikitext_ragel.rl"
	{act = 21;}
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 2980 "wikitext_ragel.c"
	if ( (*p) == 62u )
		goto tr84;
	if ( (*p) < 65u ) {
		if ( (*p) < 48u ) {
			if ( 33u <= (*p) && (*p) <= 47u )
				goto st70;
		} else if ( (*p) > 57u ) {
			if ( 58u <= (*p) && (*p) <= 64u )
				goto st70;
		} else
			goto st71;
	} else if ( (*p) > 90u ) {
		if ( (*p) < 97u ) {
			if ( 91u <= (*p) && (*p) <= 96u )
				goto st70;
		} else if ( (*p) > 122u ) {
			if ( 123u <= (*p) && (*p) <= 126u )
				goto st70;
		} else
			goto st71;
	} else
		goto st71;
	goto tr247;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 77u: goto st74;
		case 109u: goto st74;
	}
	goto tr23;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 62u )
		goto tr88;
	goto tr23;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 79u: goto st76;
		case 111u: goto st76;
	}
	goto tr23;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 87u: goto st77;
		case 119u: goto st77;
	}
	goto tr23;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 73u: goto st78;
		case 105u: goto st78;
	}
	goto tr23;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 75u: goto st79;
		case 107u: goto st79;
	}
	goto tr23;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 73u: goto st80;
		case 105u: goto st80;
	}
	goto tr23;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 62u )
		goto tr94;
	goto tr23;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 82u: goto st82;
		case 114u: goto st82;
	}
	goto tr23;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 69u: goto st83;
		case 101u: goto st83;
	}
	goto tr23;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 62u )
		goto tr97;
	goto tr23;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 80u: goto st85;
		case 84u: goto st88;
		case 112u: goto st85;
		case 116u: goto st88;
	}
	goto tr23;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 65u: goto st86;
		case 97u: goto st86;
	}
	goto tr23;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 78u: goto st87;
		case 110u: goto st87;
	}
	goto tr23;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 32u: goto st87;
		case 61u: goto st87;
		case 62u: goto tr102;
		case 95u: goto st87;
		case 126u: goto st87;
	}
	if ( (*p) < 34u ) {
		if ( 9u <= (*p) && (*p) <= 13u )
			goto st87;
	} else if ( (*p) > 59u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st87;
		} else if ( (*p) >= 64u )
			goto st87;
	} else
		goto st87;
	goto tr23;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 82u: goto st89;
		case 114u: goto st89;
	}
	goto tr23;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 79u: goto st90;
		case 111u: goto st90;
	}
	goto tr23;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 78u: goto st91;
		case 110u: goto st91;
	}
	goto tr23;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 71u: goto st92;
		case 103u: goto st92;
	}
	goto tr23;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	if ( (*p) == 62u )
		goto tr107;
	goto tr23;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 84u: goto st94;
		case 116u: goto st94;
	}
	goto tr23;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) == 62u )
		goto tr109;
	goto tr23;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 82u: goto st82;
		case 114u: goto st96;
	}
	goto tr23;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 69u: goto st83;
		case 101u: goto st97;
	}
	goto tr23;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 32u: goto st98;
		case 62u: goto tr97;
	}
	goto tr23;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 108u )
		goto st99;
	goto tr23;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 97u )
		goto st100;
	goto tr23;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 110u )
		goto st101;
	goto tr23;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 103u )
		goto st102;
	goto tr23;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 61u )
		goto st103;
	goto tr23;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	if ( (*p) == 34u )
		goto st104;
	goto tr23;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st105;
	} else if ( (*p) >= 65u )
		goto st105;
	goto tr23;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( (*p) == 34u )
		goto st106;
	if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st105;
	} else if ( (*p) >= 65u )
		goto st105;
	goto tr23;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 62u )
		goto tr121;
	goto tr23;
tr171:
#line 46 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 3316 "wikitext_ragel.c"
	switch( (*p) ) {
		case 32u: goto st186;
		case 61u: goto tr171;
	}
	goto tr248;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	if ( (*p) == 32u )
		goto st186;
	goto tr248;
tr172:
#line 46 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 3339 "wikitext_ragel.c"
	if ( (*p) == 32u )
		goto tr251;
	goto tr250;
tr173:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 3353 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr252;
		case 95u: goto st14;
		case 116u: goto tr252;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr252:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 3382 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 80u: goto tr253;
		case 95u: goto st14;
		case 112u: goto tr253;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr253:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 3411 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58u: goto st107;
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 47u )
		goto st108;
	goto tr122;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 47u )
		goto st109;
	goto tr122;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	switch( (*p) ) {
		case 45u: goto tr125;
		case 61u: goto tr125;
		case 95u: goto tr125;
		case 126u: goto tr125;
	}
	if ( (*p) < 64u ) {
		if ( (*p) < 42u ) {
			if ( 35u <= (*p) && (*p) <= 40u )
				goto tr125;
		} else if ( (*p) > 43u ) {
			if ( 47u <= (*p) && (*p) <= 57u )
				goto tr125;
		} else
			goto tr125;
	} else if ( (*p) > 90u ) {
		if ( (*p) < 194u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr125;
		} else if ( (*p) > 223u ) {
			if ( (*p) > 239u ) {
				if ( 240u <= (*p) && (*p) <= 244u )
					goto st113;
			} else if ( (*p) >= 224u )
				goto st112;
		} else
			goto st111;
	} else
		goto tr125;
	goto tr122;
tr125:
#line 1 "NONE"
	{te = p+1;}
#line 335 "wikitext_ragel.rl"
	{act = 26;}
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 3487 "wikitext_ragel.c"
	switch( (*p) ) {
		case 33u: goto st110;
		case 41u: goto st110;
		case 44u: goto st110;
		case 46u: goto st110;
		case 61u: goto tr125;
		case 63u: goto st110;
		case 95u: goto tr125;
		case 126u: goto tr125;
	}
	if ( (*p) < 97u ) {
		if ( (*p) < 58u ) {
			if ( 35u <= (*p) && (*p) <= 57u )
				goto tr125;
		} else if ( (*p) > 59u ) {
			if ( 64u <= (*p) && (*p) <= 90u )
				goto tr125;
		} else
			goto st110;
	} else if ( (*p) > 122u ) {
		if ( (*p) < 224u ) {
			if ( 194u <= (*p) && (*p) <= 223u )
				goto st111;
		} else if ( (*p) > 239u ) {
			if ( 240u <= (*p) && (*p) <= 244u )
				goto st113;
		} else
			goto st112;
	} else
		goto tr125;
	goto tr255;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 33u: goto st110;
		case 41u: goto st110;
		case 44u: goto st110;
		case 46u: goto st110;
		case 61u: goto tr125;
		case 63u: goto st110;
		case 95u: goto tr125;
		case 126u: goto tr125;
	}
	if ( (*p) < 97u ) {
		if ( (*p) < 58u ) {
			if ( 35u <= (*p) && (*p) <= 57u )
				goto tr125;
		} else if ( (*p) > 59u ) {
			if ( 64u <= (*p) && (*p) <= 90u )
				goto tr125;
		} else
			goto st110;
	} else if ( (*p) > 122u ) {
		if ( (*p) < 224u ) {
			if ( 194u <= (*p) && (*p) <= 223u )
				goto st111;
		} else if ( (*p) > 239u ) {
			if ( 240u <= (*p) && (*p) <= 244u )
				goto st113;
		} else
			goto st112;
	} else
		goto tr125;
	goto tr129;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr125;
	goto tr16;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st111;
	goto tr16;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st112;
	goto tr16;
tr174:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 3585 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr256;
		case 95u: goto st14;
		case 116u: goto tr256;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr256:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 3614 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr257;
		case 95u: goto st14;
		case 116u: goto tr257;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr257:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 3643 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 80u: goto tr258;
		case 95u: goto st14;
		case 112u: goto tr258;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr258:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 3672 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58u: goto st107;
		case 64u: goto st15;
		case 83u: goto tr253;
		case 95u: goto st14;
		case 115u: goto tr253;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr175:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 3702 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 65u: goto tr259;
		case 95u: goto st14;
		case 97u: goto tr259;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 98u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 66u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr259:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 3731 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 73u: goto tr260;
		case 95u: goto st14;
		case 105u: goto tr260;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr260:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 3760 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 76u: goto tr261;
		case 95u: goto st14;
		case 108u: goto tr261;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr261:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 3789 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 84u: goto tr262;
		case 95u: goto st14;
		case 116u: goto tr262;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr262:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 3818 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 79u: goto tr263;
		case 95u: goto st14;
		case 111u: goto tr263;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr263:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 3847 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58u: goto st114;
		case 64u: goto st15;
		case 95u: goto st14;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 95u )
		goto st115;
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st115;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st115;
		} else if ( (*p) >= 65u )
			goto st115;
	} else
		goto st115;
	goto tr122;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 64u: goto st116;
		case 95u: goto st115;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st115;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto st115;
		} else if ( (*p) >= 65u )
			goto st115;
	} else
		goto st115;
	goto tr122;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st117;
	} else
		goto st117;
	goto tr122;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 46u )
		goto st118;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st117;
	} else
		goto st117;
	goto tr16;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st119;
	} else
		goto st119;
	goto tr16;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) == 46u )
		goto st118;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr136;
	} else
		goto tr136;
	goto tr16;
tr136:
#line 1 "NONE"
	{te = p+1;}
#line 335 "wikitext_ragel.rl"
	{act = 26;}
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 3969 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st118;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr265;
	} else
		goto tr265;
	goto tr255;
tr265:
#line 1 "NONE"
	{te = p+1;}
#line 335 "wikitext_ragel.rl"
	{act = 26;}
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 3991 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st118;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr266;
	} else
		goto tr266;
	goto tr255;
tr266:
#line 1 "NONE"
	{te = p+1;}
#line 335 "wikitext_ragel.rl"
	{act = 26;}
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
#line 4013 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st118;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto tr267;
	} else
		goto tr267;
	goto tr255;
tr267:
#line 1 "NONE"
	{te = p+1;}
#line 335 "wikitext_ragel.rl"
	{act = 26;}
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 4035 "wikitext_ragel.c"
	if ( (*p) == 46u )
		goto st118;
	if ( (*p) < 65u ) {
		if ( 48u <= (*p) && (*p) <= 57u )
			goto st117;
	} else if ( (*p) > 90u ) {
		if ( 97u <= (*p) && (*p) <= 122u )
			goto st117;
	} else
		goto st117;
	goto tr255;
tr176:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 4057 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 86u: goto tr268;
		case 95u: goto st14;
		case 118u: goto tr268;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
tr268:
#line 1 "NONE"
	{te = p+1;}
#line 492 "wikitext_ragel.rl"
	{act = 51;}
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 4086 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64u: goto st15;
		case 78u: goto tr253;
		case 95u: goto st14;
		case 110u: goto tr253;
	}
	if ( (*p) < 48u ) {
		if ( 45u <= (*p) && (*p) <= 46u )
			goto st14;
	} else if ( (*p) > 57u ) {
		if ( (*p) > 90u ) {
			if ( 97u <= (*p) && (*p) <= 122u )
				goto tr169;
		} else if ( (*p) >= 65u )
			goto tr169;
	} else
		goto tr169;
	goto tr236;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	if ( (*p) == 91u )
		goto tr270;
	goto tr269;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 93u )
		goto tr272;
	goto tr271;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	if ( (*p) == 123u )
		goto tr274;
	goto tr273;
tr274:
#line 1 "NONE"
	{te = p+1;}
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 4134 "wikitext_ragel.c"
	if ( (*p) == 104u )
		goto st120;
	goto tr275;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 116u )
		goto st121;
	goto tr137;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 116u )
		goto st122;
	goto tr137;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 112u )
		goto st123;
	goto tr137;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 58u: goto st124;
		case 115u: goto st126;
	}
	goto tr137;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 47u )
		goto st125;
	goto tr137;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 47u )
		goto tr144;
	goto tr137;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) == 58u )
		goto st127;
	goto tr137;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 47u )
		goto st128;
	goto tr137;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 47u )
		goto tr147;
	goto tr137;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	if ( (*p) == 125u )
		goto tr278;
	goto tr277;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr148;
	goto st0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st131;
	goto st0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr151;
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st133;
	goto st0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto st134;
	goto st0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( 128u <= (*p) && (*p) <= 191u )
		goto tr154;
	goto st0;
	}
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
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
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
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
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
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
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
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
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 136: goto tr187;
	case 137: goto tr189;
	case 138: goto tr191;
	case 139: goto tr192;
	case 140: goto tr193;
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
	case 141: goto tr197;
	case 142: goto tr197;
	case 143: goto tr197;
	case 144: goto tr197;
	case 145: goto tr192;
	case 146: goto tr192;
	case 147: goto tr192;
	case 148: goto tr206;
	case 149: goto tr206;
	case 150: goto tr206;
	case 151: goto tr206;
	case 152: goto tr206;
	case 153: goto tr206;
	case 154: goto tr206;
	case 155: goto tr206;
	case 156: goto tr206;
	case 157: goto tr206;
	case 158: goto tr206;
	case 159: goto tr206;
	case 160: goto tr206;
	case 161: goto tr206;
	case 162: goto tr206;
	case 163: goto tr206;
	case 164: goto tr206;
	case 165: goto tr206;
	case 166: goto tr206;
	case 167: goto tr206;
	case 168: goto tr206;
	case 169: goto tr16;
	case 14: goto tr16;
	case 15: goto tr16;
	case 16: goto tr16;
	case 17: goto tr16;
	case 18: goto tr16;
	case 170: goto tr228;
	case 171: goto tr228;
	case 172: goto tr228;
	case 173: goto tr228;
	case 174: goto tr192;
	case 175: goto tr191;
	case 176: goto tr232;
	case 177: goto tr232;
	case 178: goto tr232;
	case 179: goto tr232;
	case 180: goto tr236;
	case 181: goto tr237;
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
	case 64: goto tr16;
	case 182: goto tr246;
	case 65: goto tr23;
	case 66: goto tr23;
	case 67: goto tr23;
	case 68: goto tr23;
	case 69: goto tr23;
	case 70: goto tr16;
	case 71: goto tr16;
	case 72: goto tr16;
	case 183: goto tr247;
	case 184: goto tr247;
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
	case 90: goto tr23;
	case 91: goto tr23;
	case 92: goto tr23;
	case 93: goto tr23;
	case 94: goto tr23;
	case 95: goto tr23;
	case 96: goto tr23;
	case 97: goto tr23;
	case 98: goto tr23;
	case 99: goto tr23;
	case 100: goto tr23;
	case 101: goto tr23;
	case 102: goto tr23;
	case 103: goto tr23;
	case 104: goto tr23;
	case 105: goto tr23;
	case 106: goto tr23;
	case 185: goto tr248;
	case 186: goto tr248;
	case 187: goto tr250;
	case 188: goto tr236;
	case 189: goto tr236;
	case 190: goto tr236;
	case 107: goto tr122;
	case 108: goto tr122;
	case 109: goto tr122;
	case 191: goto tr255;
	case 110: goto tr129;
	case 111: goto tr16;
	case 112: goto tr16;
	case 113: goto tr16;
	case 192: goto tr236;
	case 193: goto tr236;
	case 194: goto tr236;
	case 195: goto tr236;
	case 196: goto tr236;
	case 197: goto tr236;
	case 198: goto tr236;
	case 199: goto tr236;
	case 200: goto tr236;
	case 201: goto tr236;
	case 114: goto tr122;
	case 115: goto tr122;
	case 116: goto tr122;
	case 117: goto tr16;
	case 118: goto tr16;
	case 119: goto tr16;
	case 202: goto tr255;
	case 203: goto tr255;
	case 204: goto tr255;
	case 205: goto tr255;
	case 206: goto tr236;
	case 207: goto tr236;
	case 208: goto tr269;
	case 209: goto tr271;
	case 210: goto tr273;
	case 211: goto tr275;
	case 120: goto tr137;
	case 121: goto tr137;
	case 122: goto tr137;
	case 123: goto tr137;
	case 124: goto tr137;
	case 125: goto tr137;
	case 126: goto tr137;
	case 127: goto tr137;
	case 128: goto tr137;
	case 212: goto tr277;
	}
	}

	_out: {}
	}

#line 576 "wikitext_ragel.rl"
    if (cs == wikitext_error)
        rb_raise(eWikitextParserError, "failed before finding a token");
    else if (out->type == NO_TOKEN)
        rb_raise(eWikitextParserError, "failed to produce a token");
}
