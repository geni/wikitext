
#line 1 "wikitext_ragel.rl"
// Copyright 2008-2009 Wincent Colaiuta. All rights reserved.
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
static const int wikitext_start = 132;
static const int wikitext_first_final = 132;
static const int wikitext_error = 0;

static const int wikitext_en_main = 132;


#line 526 "wikitext_ragel.rl"


// for now we use the scanner as a tokenizer that returns one token at a time, just like ANTLR
// ultimately we could look at embedding all of the transformation inside the scanner itself (combined scanner/parser)
// pass in the last token because that's useful for the scanner to know
// p data pointer (required by Ragel machine); overriden with contents of last_token if supplied
// pe data end pointer (required by Ragel machine)
void next_token(token_t *out, token_t *last_token, char *p, char *pe)
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

    char    *mark;      // for manual backtracking
    char    *eof = pe;  // required for backtracking (longest match determination)
    int     cs;         // current state (standard Ragel)
    char    *ts;        // token start (scanner)
    char    *te;        // token end (scanner)
    int     act;        // identity of last patterned matched (scanner)
    
#line 96 "wikitext_ragel.c"
	{
	cs = wikitext_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 568 "wikitext_ragel.rl"
    
#line 106 "wikitext_ragel.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 55 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 1)) & 0x1f) << 6 |
            (*p & 0x3f);
    }
#line 517 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr3:
#line 61 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 2)) & 0x0f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
#line 517 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr6:
#line 68 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 3)) & 0x07) << 18 |
            ((uint32_t)(*(p - 2)) & 0x3f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
#line 517 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr7:
#line 412 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(AMP);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr10:
#line 400 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DECIMAL_ENTITY);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr12:
#line 394 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(HEX_ENTITY);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr14:
#line 388 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NAMED_ENTITY);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr18:
#line 382 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(AMP_ENTITY);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr22:
#line 376 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT_ENTITY);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr23:
#line 1 "NONE"
	{	switch( act ) {
	case 20:
	{{p = ((te))-1;}
            EMIT(HR);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 21:
	{{p = ((te))-1;}
            EMIT(BR_CLEAR);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 22:
	{{p = ((te))-1;}
            EMIT(BR);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 26:
	{{p = ((te))-1;}
            EMIT(URI);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 27:
	{{p = ((te))-1;}
            EMIT(MAIL);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 41:
	{{p = ((te))-1;}
            EMIT(LESS);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 50:
	{{p = ((te))-1;}
            EMIT(SPECIAL_URI_CHARS);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 51:
	{{p = ((te))-1;}
            EMIT(ALNUM);
            {p++; cs = 132; goto _out;}
        }
	break;
	case 52:
	{{p = ((te))-1;}
            EMIT(PRINTABLE);
            {p++; cs = 132; goto _out;}
        }
	break;
	}
	}
	goto st132;
tr30:
#line 418 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(LESS);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr46:
#line 127 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr48:
#line 169 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr54:
#line 97 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr57:
#line 115 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr62:
#line 269 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SPAN_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr67:
#line 157 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr69:
#line 187 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr80:
#line 121 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr95:
#line 163 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr101:
#line 91 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr104:
#line 103 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr109:
#line 263 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SPAN_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr114:
#line 151 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr116:
#line 181 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr128:
#line 109 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr129:
#line 485 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(ALNUM);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr133:
#line 328 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(URI);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr141:
#line 442 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(IMG_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr148:
#line 430 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_START_HTTP);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr151:
#line 436 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_START_HTTPS);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr155:
#line 50 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
#line 517 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr156:
#line 466 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 132; goto _out;}
        }}
#line 50 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
	goto st132;
tr160:
#line 406 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr161:
#line 219 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(OL);
            else
                EMIT(PRINTABLE);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr165:
#line 232 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(UL);
            else
                EMIT(PRINTABLE);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr180:
#line 175 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr182:
#line 358 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SEPARATOR);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr184:
#line 466 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr185:
#line 466 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr186:
#line 207 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
            {
                REWIND();
                EMIT(PRE);
            }
            else
                EMIT(SPACE);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr188:
#line 479 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(SPECIAL_URI_CHARS);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr189:
#line 497 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PRINTABLE);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr190:
#line 412 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(AMP);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr194:
#line 133 "wikitext_ragel.rl"
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
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr198:
#line 133 "wikitext_ragel.rl"
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
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr203:
#line 245 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(HR);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr225:
#line 334 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(MAIL);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr229:
#line 340 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PATH);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr233:
#line 485 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(ALNUM);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr234:
#line 418 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LESS);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr243:
#line 257 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(BR);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr244:
#line 251 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(BR_CLEAR);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr245:
#line 275 "wikitext_ragel.rl"
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
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr247:
#line 194 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr248:
#line 194 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr252:
#line 328 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(URI);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr266:
#line 364 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr267:
#line 346 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr268:
#line 370 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr269:
#line 352 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr270:
#line 454 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LEFT_CURLY);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr272:
#line 442 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(IMG_START);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr274:
#line 460 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(RIGHT_CURLY);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
tr275:
#line 448 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_END);
            {p++; cs = 132; goto _out;}
        }}
	goto st132;
st132:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 1 "NONE"
	{ts = p;}
#line 767 "wikitext_ragel.c"
	switch( (*p) ) {
		case 10: goto tr156;
		case 13: goto tr157;
		case 32: goto tr158;
		case 33: goto st135;
		case 34: goto tr160;
		case 35: goto tr161;
		case 38: goto tr163;
		case 39: goto st138;
		case 42: goto tr165;
		case 43: goto st136;
		case 45: goto tr166;
		case 46: goto tr167;
		case 47: goto st173;
		case 60: goto tr170;
		case 61: goto tr171;
		case 62: goto tr172;
		case 64: goto st136;
		case 70: goto tr173;
		case 72: goto tr174;
		case 77: goto tr175;
		case 83: goto tr176;
		case 91: goto st205;
		case 92: goto st136;
		case 93: goto st206;
		case 94: goto st136;
		case 95: goto tr179;
		case 96: goto tr180;
		case 102: goto tr173;
		case 104: goto tr174;
		case 109: goto tr175;
		case 115: goto tr176;
		case 123: goto st207;
		case 124: goto tr182;
		case 125: goto st209;
		case 126: goto st136;
		case 127: goto tr155;
	}
	if ( (*p) < 36 ) {
		if ( (*p) < -32 ) {
			if ( -62 <= (*p) && (*p) <= -33 )
				goto st1;
		} else if ( (*p) > -17 ) {
			if ( (*p) > -12 ) {
				if ( 1 <= (*p) && (*p) <= 31 )
					goto tr155;
			} else if ( (*p) >= -16 )
				goto st4;
		} else
			goto st2;
	} else if ( (*p) > 37 ) {
		if ( (*p) < 48 ) {
			if ( 40 <= (*p) && (*p) <= 44 )
				goto st135;
		} else if ( (*p) > 57 ) {
			if ( (*p) > 63 ) {
				if ( 65 <= (*p) && (*p) <= 122 )
					goto tr169;
			} else if ( (*p) >= 58 )
				goto st135;
		} else
			goto tr169;
	} else
		goto st136;
	goto st0;
st0:
cs = 0;
	goto _out;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) <= -65 )
		goto tr0;
	goto st0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) <= -65 )
		goto st3;
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) <= -65 )
		goto tr3;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) <= -65 )
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) <= -65 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) <= -65 )
		goto tr6;
	goto st0;
tr157:
#line 50 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 888 "wikitext_ragel.c"
	if ( (*p) == 10 )
		goto tr185;
	goto tr184;
tr158:
#line 45 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 902 "wikitext_ragel.c"
	if ( (*p) == 32 )
		goto st134;
	goto tr186;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 33: goto st135;
		case 44: goto st135;
		case 46: goto st135;
		case 63: goto st135;
	}
	if ( (*p) > 41 ) {
		if ( 58 <= (*p) && (*p) <= 59 )
			goto st135;
	} else if ( (*p) >= 40 )
		goto st135;
	goto tr188;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto st136;
		case 47: goto st136;
		case 64: goto st136;
		case 92: goto st136;
		case 126: goto st136;
	}
	if ( (*p) > 37 ) {
		if ( 94 <= (*p) && (*p) <= 95 )
			goto st136;
	} else if ( (*p) >= 36 )
		goto st136;
	goto tr189;
tr163:
#line 1 "NONE"
	{te = p+1;}
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 948 "wikitext_ragel.c"
	switch( (*p) ) {
		case 35: goto st7;
		case 97: goto st13;
		case 113: goto st16;
	}
	if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto st11;
	} else if ( (*p) >= 65 )
		goto st11;
	goto tr190;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 88: goto st9;
		case 120: goto st9;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st8;
	goto tr7;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 59 )
		goto tr10;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st8;
	goto tr7;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st10;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st10;
	} else
		goto st10;
	goto tr7;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 59 )
		goto tr12;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st10;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st10;
	} else
		goto st10;
	goto tr7;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 59 )
		goto tr14;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 59 )
		goto tr14;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st12;
	goto tr7;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 59: goto tr14;
		case 109: goto st14;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 59: goto tr14;
		case 112: goto st15;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 59 )
		goto tr18;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 59: goto tr14;
		case 117: goto st17;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 59: goto tr14;
		case 111: goto st18;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 59: goto tr14;
		case 116: goto st19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	if ( (*p) == 59 )
		goto tr22;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr7;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	if ( (*p) == 39 )
		goto st139;
	goto tr194;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	if ( (*p) == 39 )
		goto st140;
	goto tr194;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	if ( (*p) == 39 )
		goto st141;
	goto tr194;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 39 )
		goto tr198;
	goto tr194;
tr166:
#line 1 "NONE"
	{te = p+1;}
#line 497 "wikitext_ragel.rl"
	{act = 52;}
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 1185 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr199;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr189;
tr199:
#line 1 "NONE"
	{te = p+1;}
#line 497 "wikitext_ragel.rl"
	{act = 52;}
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 1218 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr201;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr189;
tr201:
#line 1 "NONE"
	{te = p+1;}
#line 497 "wikitext_ragel.rl"
	{act = 52;}
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 1251 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr202;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr189;
tr202:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 1284 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr204;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr204:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 1317 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr205;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr205:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 1350 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr206;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr206:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 1383 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr207;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr207:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 1416 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr208;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr208:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 1449 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr209;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr209:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 1482 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr210;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr210:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 1515 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr211;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr211:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 1548 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr212;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr212:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 1581 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr213;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr213:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 1614 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr214;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr214:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 1647 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr215;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr215:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 1680 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr216;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr216:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 1713 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr217;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr217:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 1746 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr218;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr218:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 1779 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr219;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr219:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 1812 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr220;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr220:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 1845 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr221;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr221:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 1878 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr222;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr222:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 1911 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr223;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr223:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 1944 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr224;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr203;
tr179:
#line 1 "NONE"
	{te = p+1;}
#line 497 "wikitext_ragel.rl"
	{act = 52;}
	goto st166;
tr224:
#line 1 "NONE"
	{te = p+1;}
#line 245 "wikitext_ragel.rl"
	{act = 20;}
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 1983 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto tr179;
		case 47: goto st136;
		case 64: goto tr200;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto tr179;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr23;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 64: goto st21;
		case 95: goto st20;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st20;
	goto tr23;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st22;
	} else
		goto st22;
	goto tr23;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) == 46 )
		goto st23;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st22;
	} else
		goto st22;
	goto tr23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st24;
	} else
		goto st24;
	goto tr23;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 46 )
		goto st23;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr29;
	} else
		goto tr29;
	goto tr23;
tr29:
#line 1 "NONE"
	{te = p+1;}
#line 334 "wikitext_ragel.rl"
	{act = 27;}
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 2092 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st23;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr226;
	} else
		goto tr226;
	goto tr225;
tr226:
#line 1 "NONE"
	{te = p+1;}
#line 334 "wikitext_ragel.rl"
	{act = 27;}
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 2114 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st23;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr227;
	} else
		goto tr227;
	goto tr225;
tr227:
#line 1 "NONE"
	{te = p+1;}
#line 334 "wikitext_ragel.rl"
	{act = 27;}
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 2136 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st23;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr228;
	} else
		goto tr228;
	goto tr225;
tr228:
#line 1 "NONE"
	{te = p+1;}
#line 334 "wikitext_ragel.rl"
	{act = 27;}
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 2158 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st23;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st22;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st22;
	} else
		goto st22;
	goto tr225;
tr200:
#line 1 "NONE"
	{te = p+1;}
#line 497 "wikitext_ragel.rl"
	{act = 52;}
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 2180 "wikitext_ragel.c"
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto st136;
		case 47: goto st136;
		case 64: goto st136;
		case 92: goto st136;
		case 126: goto st136;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 37 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st22;
		} else if ( (*p) >= 36 )
			goto st136;
	} else if ( (*p) > 90 ) {
		if ( (*p) > 95 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st22;
		} else if ( (*p) >= 94 )
			goto st136;
	} else
		goto st22;
	goto tr189;
tr167:
#line 1 "NONE"
	{te = p+1;}
#line 479 "wikitext_ragel.rl"
	{act = 50;}
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 2214 "wikitext_ragel.c"
	switch( (*p) ) {
		case 33: goto st135;
		case 44: goto st135;
		case 45: goto st20;
		case 46: goto tr167;
		case 63: goto st135;
		case 64: goto st21;
		case 95: goto st20;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 41 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st20;
		} else if ( (*p) >= 40 )
			goto st135;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st20;
		} else if ( (*p) >= 65 )
			goto st20;
	} else
		goto st135;
	goto tr188;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto st174;
		case 47: goto st136;
		case 64: goto st136;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto st174;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st175;
		} else if ( (*p) >= 65 )
			goto st175;
	} else
		goto st175;
	goto tr229;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 43: goto st136;
		case 45: goto st174;
		case 47: goto st173;
		case 64: goto st136;
		case 92: goto st136;
		case 94: goto st136;
		case 95: goto st174;
		case 126: goto st136;
	}
	if ( (*p) < 46 ) {
		if ( 36 <= (*p) && (*p) <= 37 )
			goto st136;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st175;
		} else if ( (*p) >= 65 )
			goto st175;
	} else
		goto st175;
	goto tr229;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 47: goto st176;
		case 95: goto st175;
	}
	if ( (*p) < 65 ) {
		if ( 45 <= (*p) && (*p) <= 57 )
			goto st175;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st175;
	} else
		goto st175;
	goto tr229;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	if ( (*p) == 95 )
		goto st175;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st175;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st175;
		} else if ( (*p) >= 65 )
			goto st175;
	} else
		goto st175;
	goto tr229;
tr169:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 2336 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 95: goto st20;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr170:
#line 1 "NONE"
	{te = p+1;}
#line 418 "wikitext_ragel.rl"
	{act = 41;}
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 2363 "wikitext_ragel.c"
	switch( (*p) ) {
		case 47: goto st25;
		case 66: goto st58;
		case 69: goto st79;
		case 78: goto st81;
		case 80: goto st87;
		case 83: goto st90;
		case 84: goto st99;
		case 98: goto st58;
		case 101: goto st79;
		case 110: goto st81;
		case 112: goto st101;
		case 115: goto st90;
		case 116: goto st99;
	}
	goto tr234;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	switch( (*p) ) {
		case 66: goto st26;
		case 69: goto st36;
		case 78: goto st38;
		case 80: goto st44;
		case 83: goto st47;
		case 84: goto st56;
		case 98: goto st26;
		case 101: goto st36;
		case 110: goto st38;
		case 112: goto st44;
		case 115: goto st47;
		case 116: goto st56;
	}
	goto tr30;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 76: goto st27;
		case 108: goto st27;
	}
	goto tr30;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	switch( (*p) ) {
		case 79: goto st28;
		case 111: goto st28;
	}
	goto tr30;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 67: goto st29;
		case 99: goto st29;
	}
	goto tr30;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 75: goto st30;
		case 107: goto st30;
	}
	goto tr30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 81: goto st31;
		case 113: goto st31;
	}
	goto tr30;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 85: goto st32;
		case 117: goto st32;
	}
	goto tr30;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 79: goto st33;
		case 111: goto st33;
	}
	goto tr30;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	switch( (*p) ) {
		case 84: goto st34;
		case 116: goto st34;
	}
	goto tr30;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 69: goto st35;
		case 101: goto st35;
	}
	goto tr30;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 62 )
		goto tr46;
	goto tr30;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 77: goto st37;
		case 109: goto st37;
	}
	goto tr30;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 62 )
		goto tr48;
	goto tr30;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 79: goto st39;
		case 111: goto st39;
	}
	goto tr30;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 87: goto st40;
		case 119: goto st40;
	}
	goto tr30;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 73: goto st41;
		case 105: goto st41;
	}
	goto tr30;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 75: goto st42;
		case 107: goto st42;
	}
	goto tr30;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 73: goto st43;
		case 105: goto st43;
	}
	goto tr30;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( (*p) == 62 )
		goto tr54;
	goto tr30;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 82: goto st45;
		case 114: goto st45;
	}
	goto tr30;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 69: goto st46;
		case 101: goto st46;
	}
	goto tr30;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	if ( (*p) == 62 )
		goto tr57;
	goto tr30;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 80: goto st48;
		case 84: goto st51;
		case 112: goto st48;
		case 116: goto st51;
	}
	goto tr30;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 65: goto st49;
		case 97: goto st49;
	}
	goto tr30;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 78: goto st50;
		case 110: goto st50;
	}
	goto tr30;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 62 )
		goto tr62;
	goto tr30;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 82: goto st52;
		case 114: goto st52;
	}
	goto tr30;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 79: goto st53;
		case 111: goto st53;
	}
	goto tr30;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 78: goto st54;
		case 110: goto st54;
	}
	goto tr30;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 71: goto st55;
		case 103: goto st55;
	}
	goto tr30;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 62 )
		goto tr67;
	goto tr30;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 84: goto st57;
		case 116: goto st57;
	}
	goto tr30;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 62 )
		goto tr69;
	goto tr30;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 76: goto st59;
		case 82: goto st68;
		case 108: goto st59;
		case 114: goto st68;
	}
	goto tr30;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 79: goto st60;
		case 111: goto st60;
	}
	goto tr30;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 67: goto st61;
		case 99: goto st61;
	}
	goto tr30;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 75: goto st62;
		case 107: goto st62;
	}
	goto tr30;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 81: goto st63;
		case 113: goto st63;
	}
	goto tr30;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 85: goto st64;
		case 117: goto st64;
	}
	goto tr30;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 79: goto st65;
		case 111: goto st65;
	}
	goto tr30;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 84: goto st66;
		case 116: goto st66;
	}
	goto tr30;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 69: goto st67;
		case 101: goto st67;
	}
	goto tr30;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	if ( (*p) == 62 )
		goto tr80;
	goto tr30;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 32: goto st71;
		case 62: goto tr84;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 13 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st70;
		} else if ( (*p) >= 9 )
			goto st69;
	} else if ( (*p) > 64 ) {
		if ( (*p) > 96 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st70;
		} else if ( (*p) >= 91 )
			goto st70;
	} else
		goto st70;
	goto tr30;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 32: goto st69;
		case 62: goto tr84;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 13 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st70;
		} else if ( (*p) >= 9 )
			goto st69;
	} else if ( (*p) > 64 ) {
		if ( (*p) > 96 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st70;
		} else if ( (*p) >= 91 )
			goto st70;
	} else
		goto st70;
	goto tr30;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 62 )
		goto tr84;
	if ( (*p) < 58 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st70;
	} else if ( (*p) > 64 ) {
		if ( (*p) > 96 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st70;
		} else if ( (*p) >= 91 )
			goto st70;
	} else
		goto st70;
	goto tr23;
tr84:
#line 1 "NONE"
	{te = p+1;}
#line 257 "wikitext_ragel.rl"
	{act = 22;}
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 2839 "wikitext_ragel.c"
	if ( (*p) == 62 )
		goto tr84;
	if ( (*p) < 58 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st70;
	} else if ( (*p) > 64 ) {
		if ( (*p) > 96 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st70;
		} else if ( (*p) >= 91 )
			goto st70;
	} else
		goto st70;
	goto tr243;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 32: goto st69;
		case 62: goto tr84;
		case 67: goto st72;
		case 99: goto st72;
	}
	if ( (*p) < 58 ) {
		if ( (*p) > 13 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st70;
		} else if ( (*p) >= 9 )
			goto st69;
	} else if ( (*p) > 64 ) {
		if ( (*p) > 96 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st70;
		} else if ( (*p) >= 91 )
			goto st70;
	} else
		goto st70;
	goto tr30;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 76: goto st73;
		case 108: goto st73;
	}
	goto tr30;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 69: goto st74;
		case 101: goto st74;
	}
	goto tr30;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 65: goto st75;
		case 97: goto st75;
	}
	goto tr30;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 82: goto st76;
		case 114: goto st76;
	}
	goto tr30;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 62 )
		goto tr91;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st76;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st76;
		} else
			goto st77;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st76;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st76;
		} else
			goto st77;
	} else
		goto st77;
	goto tr23;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	if ( (*p) == 62 )
		goto tr93;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st78;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st78;
		} else
			goto st77;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st78;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st78;
		} else
			goto st77;
	} else
		goto st77;
	goto tr23;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 62 )
		goto tr93;
	if ( (*p) < 58 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st78;
	} else if ( (*p) > 64 ) {
		if ( (*p) > 96 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st78;
		} else if ( (*p) >= 91 )
			goto st78;
	} else
		goto st78;
	goto tr23;
tr93:
#line 1 "NONE"
	{te = p+1;}
#line 251 "wikitext_ragel.rl"
	{act = 21;}
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 2997 "wikitext_ragel.c"
	if ( (*p) == 62 )
		goto tr93;
	if ( (*p) < 58 ) {
		if ( 33 <= (*p) && (*p) <= 47 )
			goto st78;
	} else if ( (*p) > 64 ) {
		if ( (*p) > 96 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st78;
		} else if ( (*p) >= 91 )
			goto st78;
	} else
		goto st78;
	goto tr244;
tr91:
#line 1 "NONE"
	{te = p+1;}
#line 251 "wikitext_ragel.rl"
	{act = 21;}
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 3022 "wikitext_ragel.c"
	if ( (*p) == 62 )
		goto tr91;
	if ( (*p) < 65 ) {
		if ( (*p) < 48 ) {
			if ( 33 <= (*p) && (*p) <= 47 )
				goto st76;
		} else if ( (*p) > 57 ) {
			if ( 58 <= (*p) && (*p) <= 64 )
				goto st76;
		} else
			goto st77;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 91 <= (*p) && (*p) <= 96 )
				goto st76;
		} else if ( (*p) > 122 ) {
			if ( 123 <= (*p) && (*p) <= 126 )
				goto st76;
		} else
			goto st77;
	} else
		goto st77;
	goto tr244;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 77: goto st80;
		case 109: goto st80;
	}
	goto tr30;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	if ( (*p) == 62 )
		goto tr95;
	goto tr30;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 79: goto st82;
		case 111: goto st82;
	}
	goto tr30;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 87: goto st83;
		case 119: goto st83;
	}
	goto tr30;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 73: goto st84;
		case 105: goto st84;
	}
	goto tr30;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 75: goto st85;
		case 107: goto st85;
	}
	goto tr30;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 73: goto st86;
		case 105: goto st86;
	}
	goto tr30;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	if ( (*p) == 62 )
		goto tr101;
	goto tr30;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 82: goto st88;
		case 114: goto st88;
	}
	goto tr30;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 69: goto st89;
		case 101: goto st89;
	}
	goto tr30;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	if ( (*p) == 62 )
		goto tr104;
	goto tr30;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 80: goto st91;
		case 84: goto st94;
		case 112: goto st91;
		case 116: goto st94;
	}
	goto tr30;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 65: goto st92;
		case 97: goto st92;
	}
	goto tr30;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 78: goto st93;
		case 110: goto st93;
	}
	goto tr30;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 32: goto st93;
		case 61: goto st93;
		case 62: goto tr109;
		case 95: goto st93;
		case 126: goto st93;
	}
	if ( (*p) < 34 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st93;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st93;
		} else if ( (*p) >= 64 )
			goto st93;
	} else
		goto st93;
	goto tr30;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 82: goto st95;
		case 114: goto st95;
	}
	goto tr30;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 79: goto st96;
		case 111: goto st96;
	}
	goto tr30;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 78: goto st97;
		case 110: goto st97;
	}
	goto tr30;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 71: goto st98;
		case 103: goto st98;
	}
	goto tr30;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 62 )
		goto tr114;
	goto tr30;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 84: goto st100;
		case 116: goto st100;
	}
	goto tr30;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 62 )
		goto tr116;
	goto tr30;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 82: goto st88;
		case 114: goto st102;
	}
	goto tr30;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 69: goto st89;
		case 101: goto st103;
	}
	goto tr30;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 32: goto st104;
		case 62: goto tr104;
	}
	goto tr30;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	if ( (*p) == 108 )
		goto st105;
	goto tr30;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	if ( (*p) == 97 )
		goto st106;
	goto tr30;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 110 )
		goto st107;
	goto tr30;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 103 )
		goto st108;
	goto tr30;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) == 61 )
		goto st109;
	goto tr30;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
	if ( (*p) == 34 )
		goto st110;
	goto tr30;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st111;
	} else if ( (*p) >= 65 )
		goto st111;
	goto tr30;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 34 )
		goto st112;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st111;
	} else if ( (*p) >= 65 )
		goto st111;
	goto tr30;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	if ( (*p) == 62 )
		goto tr128;
	goto tr30;
tr171:
#line 45 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 3358 "wikitext_ragel.c"
	switch( (*p) ) {
		case 32: goto st183;
		case 61: goto tr171;
	}
	goto tr245;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	if ( (*p) == 32 )
		goto st183;
	goto tr245;
tr172:
#line 45 "wikitext_ragel.rl"
	{
        MARK();
    }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 3381 "wikitext_ragel.c"
	if ( (*p) == 32 )
		goto tr248;
	goto tr247;
tr173:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 3395 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 84: goto tr249;
		case 95: goto st20;
		case 116: goto tr249;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr249:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 3424 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 80: goto tr250;
		case 95: goto st20;
		case 112: goto tr250;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr250:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 3453 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58: goto st113;
		case 64: goto st21;
		case 95: goto st20;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	if ( (*p) == 47 )
		goto st114;
	goto tr129;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) == 47 )
		goto st115;
	goto tr129;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 45: goto tr132;
		case 61: goto tr132;
		case 95: goto tr132;
		case 126: goto tr132;
	}
	if ( (*p) < 47 ) {
		if ( (*p) > 40 ) {
			if ( 42 <= (*p) && (*p) <= 43 )
				goto tr132;
		} else if ( (*p) >= 35 )
			goto tr132;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr132;
		} else if ( (*p) >= 64 )
			goto tr132;
	} else
		goto tr132;
	goto tr129;
tr132:
#line 1 "NONE"
	{te = p+1;}
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 3518 "wikitext_ragel.c"
	switch( (*p) ) {
		case 33: goto st116;
		case 41: goto st116;
		case 44: goto st116;
		case 46: goto st116;
		case 61: goto tr132;
		case 63: goto st116;
		case 95: goto tr132;
		case 126: goto tr132;
	}
	if ( (*p) < 58 ) {
		if ( 35 <= (*p) && (*p) <= 57 )
			goto tr132;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr132;
		} else if ( (*p) >= 64 )
			goto tr132;
	} else
		goto st116;
	goto tr252;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
	switch( (*p) ) {
		case 33: goto st116;
		case 41: goto st116;
		case 44: goto st116;
		case 46: goto st116;
		case 61: goto tr132;
		case 63: goto st116;
		case 95: goto tr132;
		case 126: goto tr132;
	}
	if ( (*p) < 58 ) {
		if ( 35 <= (*p) && (*p) <= 57 )
			goto tr132;
	} else if ( (*p) > 59 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr132;
		} else if ( (*p) >= 64 )
			goto tr132;
	} else
		goto st116;
	goto tr133;
tr174:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 3577 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 84: goto tr253;
		case 95: goto st20;
		case 116: goto tr253;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr253:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 3606 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 84: goto tr254;
		case 95: goto st20;
		case 116: goto tr254;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr254:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st191;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
#line 3635 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 80: goto tr255;
		case 95: goto st20;
		case 112: goto tr255;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr255:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 3664 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58: goto st113;
		case 64: goto st21;
		case 83: goto tr250;
		case 95: goto st20;
		case 115: goto tr250;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr175:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 3694 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 65: goto tr256;
		case 95: goto st20;
		case 97: goto tr256;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 98 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 66 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr256:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 3723 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 73: goto tr257;
		case 95: goto st20;
		case 105: goto tr257;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr257:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 3752 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 76: goto tr258;
		case 95: goto st20;
		case 108: goto tr258;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr258:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 3781 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 84: goto tr259;
		case 95: goto st20;
		case 116: goto tr259;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr259:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 3810 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 79: goto tr260;
		case 95: goto st20;
		case 111: goto tr260;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr260:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 3839 "wikitext_ragel.c"
	switch( (*p) ) {
		case 58: goto st117;
		case 64: goto st21;
		case 95: goto st20;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	if ( (*p) == 95 )
		goto st118;
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st118;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st118;
		} else if ( (*p) >= 65 )
			goto st118;
	} else
		goto st118;
	goto tr129;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 64: goto st119;
		case 95: goto st118;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st118;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st118;
		} else if ( (*p) >= 65 )
			goto st118;
	} else
		goto st118;
	goto tr129;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st120;
	} else
		goto st120;
	goto tr129;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 46 )
		goto st121;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st120;
	} else
		goto st120;
	goto tr23;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st122;
	} else
		goto st122;
	goto tr23;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) == 46 )
		goto st121;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr140;
	} else
		goto tr140;
	goto tr23;
tr140:
#line 1 "NONE"
	{te = p+1;}
#line 328 "wikitext_ragel.rl"
	{act = 26;}
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 3961 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st121;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr262;
	} else
		goto tr262;
	goto tr252;
tr262:
#line 1 "NONE"
	{te = p+1;}
#line 328 "wikitext_ragel.rl"
	{act = 26;}
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 3983 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st121;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr263;
	} else
		goto tr263;
	goto tr252;
tr263:
#line 1 "NONE"
	{te = p+1;}
#line 328 "wikitext_ragel.rl"
	{act = 26;}
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 4005 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st121;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr264;
	} else
		goto tr264;
	goto tr252;
tr264:
#line 1 "NONE"
	{te = p+1;}
#line 328 "wikitext_ragel.rl"
	{act = 26;}
	goto st202;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
#line 4027 "wikitext_ragel.c"
	if ( (*p) == 46 )
		goto st121;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st120;
	} else
		goto st120;
	goto tr252;
tr176:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 4049 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 86: goto tr265;
		case 95: goto st20;
		case 118: goto tr265;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
tr265:
#line 1 "NONE"
	{te = p+1;}
#line 485 "wikitext_ragel.rl"
	{act = 51;}
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
#line 4078 "wikitext_ragel.c"
	switch( (*p) ) {
		case 64: goto st21;
		case 78: goto tr250;
		case 95: goto st20;
		case 110: goto tr250;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr169;
		} else if ( (*p) >= 65 )
			goto tr169;
	} else
		goto tr169;
	goto tr233;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	if ( (*p) == 91 )
		goto tr267;
	goto tr266;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	if ( (*p) == 93 )
		goto tr269;
	goto tr268;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	if ( (*p) == 123 )
		goto tr271;
	goto tr270;
tr271:
#line 1 "NONE"
	{te = p+1;}
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 4126 "wikitext_ragel.c"
	if ( (*p) == 104 )
		goto st123;
	goto tr272;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 116 )
		goto st124;
	goto tr141;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) == 116 )
		goto st125;
	goto tr141;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	if ( (*p) == 112 )
		goto st126;
	goto tr141;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 58: goto st127;
		case 115: goto st129;
	}
	goto tr141;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) == 47 )
		goto st128;
	goto tr141;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) == 47 )
		goto tr148;
	goto tr141;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 58 )
		goto st130;
	goto tr141;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) == 47 )
		goto st131;
	goto tr141;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	if ( (*p) == 47 )
		goto tr151;
	goto tr141;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) == 125 )
		goto tr275;
	goto tr274;
	}
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
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
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
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
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
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
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 133: goto tr184;
	case 134: goto tr186;
	case 135: goto tr188;
	case 136: goto tr189;
	case 137: goto tr190;
	case 7: goto tr7;
	case 8: goto tr7;
	case 9: goto tr7;
	case 10: goto tr7;
	case 11: goto tr7;
	case 12: goto tr7;
	case 13: goto tr7;
	case 14: goto tr7;
	case 15: goto tr7;
	case 16: goto tr7;
	case 17: goto tr7;
	case 18: goto tr7;
	case 19: goto tr7;
	case 138: goto tr194;
	case 139: goto tr194;
	case 140: goto tr194;
	case 141: goto tr194;
	case 142: goto tr189;
	case 143: goto tr189;
	case 144: goto tr189;
	case 145: goto tr203;
	case 146: goto tr203;
	case 147: goto tr203;
	case 148: goto tr203;
	case 149: goto tr203;
	case 150: goto tr203;
	case 151: goto tr203;
	case 152: goto tr203;
	case 153: goto tr203;
	case 154: goto tr203;
	case 155: goto tr203;
	case 156: goto tr203;
	case 157: goto tr203;
	case 158: goto tr203;
	case 159: goto tr203;
	case 160: goto tr203;
	case 161: goto tr203;
	case 162: goto tr203;
	case 163: goto tr203;
	case 164: goto tr203;
	case 165: goto tr203;
	case 166: goto tr23;
	case 20: goto tr23;
	case 21: goto tr23;
	case 22: goto tr23;
	case 23: goto tr23;
	case 24: goto tr23;
	case 167: goto tr225;
	case 168: goto tr225;
	case 169: goto tr225;
	case 170: goto tr225;
	case 171: goto tr189;
	case 172: goto tr188;
	case 173: goto tr229;
	case 174: goto tr229;
	case 175: goto tr229;
	case 176: goto tr229;
	case 177: goto tr233;
	case 178: goto tr234;
	case 25: goto tr30;
	case 26: goto tr30;
	case 27: goto tr30;
	case 28: goto tr30;
	case 29: goto tr30;
	case 30: goto tr30;
	case 31: goto tr30;
	case 32: goto tr30;
	case 33: goto tr30;
	case 34: goto tr30;
	case 35: goto tr30;
	case 36: goto tr30;
	case 37: goto tr30;
	case 38: goto tr30;
	case 39: goto tr30;
	case 40: goto tr30;
	case 41: goto tr30;
	case 42: goto tr30;
	case 43: goto tr30;
	case 44: goto tr30;
	case 45: goto tr30;
	case 46: goto tr30;
	case 47: goto tr30;
	case 48: goto tr30;
	case 49: goto tr30;
	case 50: goto tr30;
	case 51: goto tr30;
	case 52: goto tr30;
	case 53: goto tr30;
	case 54: goto tr30;
	case 55: goto tr30;
	case 56: goto tr30;
	case 57: goto tr30;
	case 58: goto tr30;
	case 59: goto tr30;
	case 60: goto tr30;
	case 61: goto tr30;
	case 62: goto tr30;
	case 63: goto tr30;
	case 64: goto tr30;
	case 65: goto tr30;
	case 66: goto tr30;
	case 67: goto tr30;
	case 68: goto tr30;
	case 69: goto tr30;
	case 70: goto tr23;
	case 179: goto tr243;
	case 71: goto tr30;
	case 72: goto tr30;
	case 73: goto tr30;
	case 74: goto tr30;
	case 75: goto tr30;
	case 76: goto tr23;
	case 77: goto tr23;
	case 78: goto tr23;
	case 180: goto tr244;
	case 181: goto tr244;
	case 79: goto tr30;
	case 80: goto tr30;
	case 81: goto tr30;
	case 82: goto tr30;
	case 83: goto tr30;
	case 84: goto tr30;
	case 85: goto tr30;
	case 86: goto tr30;
	case 87: goto tr30;
	case 88: goto tr30;
	case 89: goto tr30;
	case 90: goto tr30;
	case 91: goto tr30;
	case 92: goto tr30;
	case 93: goto tr30;
	case 94: goto tr30;
	case 95: goto tr30;
	case 96: goto tr30;
	case 97: goto tr30;
	case 98: goto tr30;
	case 99: goto tr30;
	case 100: goto tr30;
	case 101: goto tr30;
	case 102: goto tr30;
	case 103: goto tr30;
	case 104: goto tr30;
	case 105: goto tr30;
	case 106: goto tr30;
	case 107: goto tr30;
	case 108: goto tr30;
	case 109: goto tr30;
	case 110: goto tr30;
	case 111: goto tr30;
	case 112: goto tr30;
	case 182: goto tr245;
	case 183: goto tr245;
	case 184: goto tr247;
	case 185: goto tr233;
	case 186: goto tr233;
	case 187: goto tr233;
	case 113: goto tr129;
	case 114: goto tr129;
	case 115: goto tr129;
	case 188: goto tr252;
	case 116: goto tr133;
	case 189: goto tr233;
	case 190: goto tr233;
	case 191: goto tr233;
	case 192: goto tr233;
	case 193: goto tr233;
	case 194: goto tr233;
	case 195: goto tr233;
	case 196: goto tr233;
	case 197: goto tr233;
	case 198: goto tr233;
	case 117: goto tr129;
	case 118: goto tr129;
	case 119: goto tr129;
	case 120: goto tr23;
	case 121: goto tr23;
	case 122: goto tr23;
	case 199: goto tr252;
	case 200: goto tr252;
	case 201: goto tr252;
	case 202: goto tr252;
	case 203: goto tr233;
	case 204: goto tr233;
	case 205: goto tr266;
	case 206: goto tr268;
	case 207: goto tr270;
	case 208: goto tr272;
	case 123: goto tr141;
	case 124: goto tr141;
	case 125: goto tr141;
	case 126: goto tr141;
	case 127: goto tr141;
	case 128: goto tr141;
	case 129: goto tr141;
	case 130: goto tr141;
	case 131: goto tr141;
	case 209: goto tr274;
	}
	}

	_out: {}
	}

#line 569 "wikitext_ragel.rl"
    if (cs == wikitext_error)
        rb_raise(eWikitextParserError, "failed before finding a token");
    else if (out->type == NO_TOKEN)
        rb_raise(eWikitextParserError, "failed to produce a token");
}
