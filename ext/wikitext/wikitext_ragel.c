
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
static const char _wikitext_actions[] = {
	0, 1, 0, 1, 1, 1, 5, 1, 
	6, 1, 7, 1, 14, 1, 15, 1, 
	16, 1, 17, 1, 18, 1, 19, 1, 
	20, 1, 21, 1, 22, 1, 23, 1, 
	24, 1, 25, 1, 26, 1, 27, 1, 
	28, 1, 29, 1, 30, 1, 31, 1, 
	32, 1, 33, 1, 34, 1, 35, 1, 
	36, 1, 37, 1, 38, 1, 39, 1, 
	40, 1, 41, 1, 42, 1, 43, 1, 
	44, 1, 46, 1, 47, 1, 48, 1, 
	49, 1, 50, 1, 51, 1, 52, 1, 
	53, 1, 54, 1, 55, 1, 56, 1, 
	57, 1, 58, 1, 59, 1, 60, 1, 
	61, 1, 62, 1, 63, 1, 64, 1, 
	65, 1, 66, 1, 67, 1, 68, 2, 
	1, 45, 2, 2, 45, 2, 3, 45, 
	2, 4, 45, 2, 7, 8, 2, 7, 
	9, 2, 7, 10, 2, 7, 11, 2, 
	7, 12, 2, 7, 13, 2, 44, 1
	
};

static const short _wikitext_key_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 12, 
	16, 19, 25, 32, 39, 42, 50, 58, 
	65, 73, 81, 89, 96, 106, 112, 119, 
	125, 132, 144, 146, 148, 150, 152, 154, 
	156, 158, 160, 162, 163, 165, 166, 168, 
	170, 172, 174, 176, 177, 179, 181, 182, 
	184, 186, 188, 190, 192, 193, 195, 196, 
	200, 202, 204, 206, 208, 210, 212, 214, 
	216, 217, 218, 219, 221, 222, 224, 226, 
	228, 230, 232, 233, 235, 237, 238, 240, 
	242, 244, 246, 248, 249, 251, 252, 254, 
	256, 258, 259, 260, 261, 262, 263, 264, 
	268, 273, 274, 275, 276, 290, 306, 315, 
	325, 331, 338, 344, 351, 405, 406, 407, 
	415, 425, 432, 433, 434, 435, 436, 452, 
	468, 484, 500, 516, 532, 548, 564, 580, 
	596, 612, 628, 644, 660, 676, 692, 708, 
	724, 740, 756, 772, 788, 804, 820, 836, 
	843, 850, 857, 864, 880, 897, 913, 929, 
	937, 946, 956, 969, 971, 972, 973, 985, 
	997, 1008, 1024, 1036, 1048, 1060, 1073, 1085, 
	1097, 1109, 1121, 1133, 1144, 1151, 1158, 1165, 
	1172, 1184, 1196, 1197, 1198, 1199
};

static const char _wikitext_trans_keys[] = {
	-128, -65, -128, -65, -128, -65, -128, -65, 
	-128, -65, -128, -65, 88, 120, 48, 57, 
	59, 48, 57, 48, 57, 65, 70, 97, 
	102, 59, 48, 57, 65, 70, 97, 102, 
	59, 48, 57, 65, 90, 97, 122, 59, 
	48, 57, 59, 109, 48, 57, 65, 90, 
	97, 122, 59, 112, 48, 57, 65, 90, 
	97, 122, 59, 48, 57, 65, 90, 97, 
	122, 59, 117, 48, 57, 65, 90, 97, 
	122, 59, 111, 48, 57, 65, 90, 97, 
	122, 59, 116, 48, 57, 65, 90, 97, 
	122, 59, 48, 57, 65, 90, 97, 122, 
	64, 95, 45, 46, 48, 57, 65, 90, 
	97, 122, 48, 57, 65, 90, 97, 122, 
	46, 48, 57, 65, 90, 97, 122, 48, 
	57, 65, 90, 97, 122, 46, 48, 57, 
	65, 90, 97, 122, 66, 69, 78, 80, 
	83, 84, 98, 101, 110, 112, 115, 116, 
	76, 108, 79, 111, 67, 99, 75, 107, 
	81, 113, 85, 117, 79, 111, 84, 116, 
	69, 101, 62, 77, 109, 62, 79, 111, 
	87, 119, 73, 105, 75, 107, 73, 105, 
	62, 82, 114, 69, 101, 62, 84, 116, 
	82, 114, 79, 111, 78, 110, 71, 103, 
	62, 84, 116, 62, 76, 82, 108, 114, 
	79, 111, 67, 99, 75, 107, 81, 113, 
	85, 117, 79, 111, 84, 116, 69, 101, 
	62, 47, 62, 77, 109, 62, 79, 111, 
	87, 119, 73, 105, 75, 107, 73, 105, 
	62, 82, 114, 69, 101, 62, 84, 116, 
	82, 114, 79, 111, 78, 110, 71, 103, 
	62, 84, 116, 62, 82, 114, 69, 101, 
	32, 62, 108, 97, 110, 103, 61, 34, 
	65, 90, 97, 122, 34, 65, 90, 97, 
	122, 62, 47, 47, 45, 61, 95, 126, 
	35, 40, 42, 43, 47, 57, 64, 90, 
	97, 122, 33, 41, 44, 46, 61, 63, 
	95, 126, 35, 57, 58, 59, 64, 90, 
	97, 122, 95, 45, 46, 48, 57, 65, 
	90, 97, 122, 64, 95, 45, 46, 48, 
	57, 65, 90, 97, 122, 48, 57, 65, 
	90, 97, 122, 46, 48, 57, 65, 90, 
	97, 122, 48, 57, 65, 90, 97, 122, 
	46, 48, 57, 65, 90, 97, 122, 10, 
	13, 32, 33, 34, 35, 38, 39, 42, 
	43, 45, 46, 47, 60, 61, 62, 64, 
	70, 72, 77, 83, 91, 92, 93, 94, 
	95, 96, 102, 104, 109, 115, 123, 124, 
	125, 126, 127, -62, -33, -32, -17, -16, 
	-12, 1, 31, 36, 37, 40, 44, 48, 
	57, 58, 63, 65, 122, 10, 32, 33, 
	44, 46, 63, 40, 41, 58, 59, 43, 
	45, 47, 64, 92, 126, 36, 37, 94, 
	95, 35, 97, 113, 65, 90, 98, 122, 
	39, 39, 39, 39, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 94, 95, 126, 36, 37, 46, 57, 
	65, 90, 97, 122, 46, 48, 57, 65, 
	90, 97, 122, 46, 48, 57, 65, 90, 
	97, 122, 46, 48, 57, 65, 90, 97, 
	122, 46, 48, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 126, 36, 37, 
	48, 57, 65, 90, 94, 95, 97, 122, 
	33, 44, 45, 46, 63, 64, 95, 40, 
	41, 48, 57, 58, 59, 65, 90, 97, 
	122, 43, 45, 47, 64, 92, 94, 95, 
	126, 36, 37, 46, 57, 65, 90, 97, 
	122, 43, 45, 47, 64, 92, 94, 95, 
	126, 36, 37, 46, 57, 65, 90, 97, 
	122, 47, 95, 45, 57, 65, 90, 97, 
	122, 95, 45, 46, 48, 57, 65, 90, 
	97, 122, 64, 95, 45, 46, 48, 57, 
	65, 90, 97, 122, 47, 66, 69, 78, 
	80, 83, 84, 98, 101, 110, 112, 115, 
	116, 32, 61, 32, 32, 64, 84, 95, 
	116, 45, 46, 48, 57, 65, 90, 97, 
	122, 64, 80, 95, 112, 45, 46, 48, 
	57, 65, 90, 97, 122, 58, 64, 95, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	33, 41, 44, 46, 61, 63, 95, 126, 
	35, 57, 58, 59, 64, 90, 97, 122, 
	64, 84, 95, 116, 45, 46, 48, 57, 
	65, 90, 97, 122, 64, 84, 95, 116, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	64, 80, 95, 112, 45, 46, 48, 57, 
	65, 90, 97, 122, 58, 64, 83, 95, 
	115, 45, 46, 48, 57, 65, 90, 97, 
	122, 64, 65, 95, 97, 45, 46, 48, 
	57, 66, 90, 98, 122, 64, 73, 95, 
	105, 45, 46, 48, 57, 65, 90, 97, 
	122, 64, 76, 95, 108, 45, 46, 48, 
	57, 65, 90, 97, 122, 64, 84, 95, 
	116, 45, 46, 48, 57, 65, 90, 97, 
	122, 64, 79, 95, 111, 45, 46, 48, 
	57, 65, 90, 97, 122, 58, 64, 95, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	46, 48, 57, 65, 90, 97, 122, 46, 
	48, 57, 65, 90, 97, 122, 46, 48, 
	57, 65, 90, 97, 122, 46, 48, 57, 
	65, 90, 97, 122, 64, 86, 95, 118, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	64, 78, 95, 110, 45, 46, 48, 57, 
	65, 90, 97, 122, 91, 93, 123, 125, 
	0
};

static const char _wikitext_single_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 2, 
	1, 0, 1, 1, 1, 2, 2, 1, 
	2, 2, 2, 1, 2, 0, 1, 0, 
	1, 12, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 1, 2, 1, 2, 2, 
	2, 2, 2, 1, 2, 2, 1, 2, 
	2, 2, 2, 2, 1, 2, 1, 4, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	1, 1, 1, 2, 1, 2, 2, 2, 
	2, 2, 1, 2, 2, 1, 2, 2, 
	2, 2, 2, 1, 2, 1, 2, 2, 
	2, 1, 1, 1, 1, 1, 1, 0, 
	1, 1, 1, 1, 4, 8, 1, 2, 
	0, 1, 0, 1, 36, 1, 1, 4, 
	6, 3, 1, 1, 1, 1, 8, 8, 
	8, 8, 8, 8, 8, 8, 8, 8, 
	8, 8, 8, 8, 8, 8, 8, 8, 
	8, 8, 8, 8, 8, 8, 8, 1, 
	1, 1, 1, 6, 7, 8, 8, 2, 
	1, 2, 13, 2, 1, 1, 4, 4, 
	3, 8, 4, 4, 4, 5, 4, 4, 
	4, 4, 4, 3, 1, 1, 1, 1, 
	4, 4, 1, 1, 1, 1
};

static const char _wikitext_range_lengths[] = {
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 3, 3, 3, 1, 3, 3, 3, 
	3, 3, 3, 3, 4, 3, 3, 3, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 2, 
	2, 0, 0, 0, 5, 4, 4, 4, 
	3, 3, 3, 3, 9, 0, 0, 2, 
	2, 2, 0, 0, 0, 0, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 3, 
	3, 3, 3, 5, 5, 4, 4, 3, 
	4, 4, 0, 0, 0, 0, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 3, 3, 3, 3, 
	4, 4, 0, 0, 0, 0
};

static const short _wikitext_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 12, 
	16, 19, 23, 28, 33, 36, 42, 48, 
	53, 59, 65, 71, 76, 83, 87, 92, 
	96, 101, 114, 117, 120, 123, 126, 129, 
	132, 135, 138, 141, 143, 146, 148, 151, 
	154, 157, 160, 163, 165, 168, 171, 173, 
	176, 179, 182, 185, 188, 190, 193, 195, 
	200, 203, 206, 209, 212, 215, 218, 221, 
	224, 226, 228, 230, 233, 235, 238, 241, 
	244, 247, 250, 252, 255, 258, 260, 263, 
	266, 269, 272, 275, 277, 280, 282, 285, 
	288, 291, 293, 295, 297, 299, 301, 303, 
	306, 310, 312, 314, 316, 326, 339, 345, 
	352, 356, 361, 365, 370, 416, 418, 420, 
	427, 436, 442, 444, 446, 448, 450, 463, 
	476, 489, 502, 515, 528, 541, 554, 567, 
	580, 593, 606, 619, 632, 645, 658, 671, 
	684, 697, 710, 723, 736, 749, 762, 775, 
	780, 785, 790, 795, 807, 820, 833, 846, 
	852, 858, 865, 879, 882, 884, 886, 895, 
	904, 912, 925, 934, 943, 952, 962, 971, 
	980, 989, 998, 1007, 1015, 1020, 1025, 1030, 
	1035, 1044, 1053, 1055, 1057, 1059
};

static const unsigned char _wikitext_indicies[] = {
	0, 1, 2, 1, 3, 1, 4, 1, 
	5, 1, 6, 1, 9, 9, 8, 7, 
	10, 8, 7, 11, 11, 11, 7, 12, 
	11, 11, 11, 7, 14, 13, 15, 15, 
	7, 14, 13, 7, 14, 16, 13, 15, 
	15, 7, 14, 17, 13, 15, 15, 7, 
	18, 13, 15, 15, 7, 14, 19, 13, 
	15, 15, 7, 14, 20, 13, 15, 15, 
	7, 14, 21, 13, 15, 15, 7, 22, 
	13, 15, 15, 7, 25, 24, 24, 24, 
	24, 24, 23, 26, 26, 26, 23, 27, 
	26, 26, 26, 23, 26, 28, 28, 23, 
	27, 26, 29, 29, 23, 31, 32, 33, 
	34, 35, 36, 31, 32, 33, 34, 35, 
	36, 30, 37, 37, 30, 38, 38, 30, 
	39, 39, 30, 40, 40, 30, 41, 41, 
	30, 42, 42, 30, 43, 43, 30, 44, 
	44, 30, 45, 45, 30, 46, 30, 47, 
	47, 30, 48, 30, 49, 49, 30, 50, 
	50, 30, 51, 51, 30, 52, 52, 30, 
	53, 53, 30, 54, 30, 55, 55, 30, 
	56, 56, 30, 57, 30, 58, 58, 30, 
	59, 59, 30, 60, 60, 30, 61, 61, 
	30, 62, 62, 30, 63, 30, 64, 64, 
	30, 65, 30, 66, 67, 66, 67, 30, 
	68, 68, 30, 69, 69, 30, 70, 70, 
	30, 71, 71, 30, 72, 72, 30, 73, 
	73, 30, 74, 74, 30, 75, 75, 30, 
	76, 30, 77, 30, 78, 30, 79, 79, 
	30, 80, 30, 81, 81, 30, 82, 82, 
	30, 83, 83, 30, 84, 84, 30, 85, 
	85, 30, 86, 30, 87, 87, 30, 88, 
	88, 30, 89, 30, 90, 90, 30, 91, 
	91, 30, 92, 92, 30, 93, 93, 30, 
	94, 94, 30, 95, 30, 96, 96, 30, 
	97, 30, 87, 98, 30, 88, 99, 30, 
	100, 89, 30, 101, 30, 102, 30, 103, 
	30, 104, 30, 105, 30, 106, 30, 107, 
	107, 30, 108, 107, 107, 30, 109, 30, 
	111, 110, 112, 110, 113, 113, 113, 113, 
	113, 113, 113, 113, 113, 110, 115, 115, 
	115, 115, 113, 115, 113, 113, 113, 115, 
	113, 113, 114, 116, 116, 116, 116, 116, 
	110, 117, 116, 116, 116, 116, 116, 110, 
	118, 118, 118, 110, 119, 118, 118, 118, 
	23, 118, 120, 120, 23, 119, 118, 121, 
	121, 23, 126, 127, 128, 129, 130, 131, 
	133, 134, 135, 132, 136, 137, 138, 140, 
	141, 142, 132, 143, 144, 145, 146, 147, 
	132, 148, 132, 149, 150, 143, 144, 145, 
	146, 151, 152, 153, 132, 125, 122, 123, 
	124, 125, 132, 129, 139, 129, 139, 1, 
	155, 154, 157, 156, 129, 129, 129, 129, 
	129, 129, 158, 132, 132, 132, 132, 132, 
	132, 132, 132, 159, 161, 162, 163, 15, 
	15, 160, 165, 164, 166, 164, 167, 164, 
	168, 164, 132, 169, 132, 170, 132, 132, 
	149, 132, 132, 24, 24, 24, 159, 132, 
	171, 132, 170, 132, 132, 149, 132, 132, 
	24, 24, 24, 159, 132, 172, 132, 170, 
	132, 132, 149, 132, 132, 24, 24, 24, 
	159, 132, 174, 132, 170, 132, 132, 149, 
	132, 132, 24, 24, 24, 173, 132, 175, 
	132, 170, 132, 132, 149, 132, 132, 24, 
	24, 24, 173, 132, 176, 132, 170, 132, 
	132, 149, 132, 132, 24, 24, 24, 173, 
	132, 177, 132, 170, 132, 132, 149, 132, 
	132, 24, 24, 24, 173, 132, 178, 132, 
	170, 132, 132, 149, 132, 132, 24, 24, 
	24, 173, 132, 179, 132, 170, 132, 132, 
	149, 132, 132, 24, 24, 24, 173, 132, 
	180, 132, 170, 132, 132, 149, 132, 132, 
	24, 24, 24, 173, 132, 181, 132, 170, 
	132, 132, 149, 132, 132, 24, 24, 24, 
	173, 132, 182, 132, 170, 132, 132, 149, 
	132, 132, 24, 24, 24, 173, 132, 183, 
	132, 170, 132, 132, 149, 132, 132, 24, 
	24, 24, 173, 132, 184, 132, 170, 132, 
	132, 149, 132, 132, 24, 24, 24, 173, 
	132, 185, 132, 170, 132, 132, 149, 132, 
	132, 24, 24, 24, 173, 132, 186, 132, 
	170, 132, 132, 149, 132, 132, 24, 24, 
	24, 173, 132, 187, 132, 170, 132, 132, 
	149, 132, 132, 24, 24, 24, 173, 132, 
	188, 132, 170, 132, 132, 149, 132, 132, 
	24, 24, 24, 173, 132, 189, 132, 170, 
	132, 132, 149, 132, 132, 24, 24, 24, 
	173, 132, 190, 132, 170, 132, 132, 149, 
	132, 132, 24, 24, 24, 173, 132, 191, 
	132, 170, 132, 132, 149, 132, 132, 24, 
	24, 24, 173, 132, 192, 132, 170, 132, 
	132, 149, 132, 132, 24, 24, 24, 173, 
	132, 193, 132, 170, 132, 132, 149, 132, 
	132, 24, 24, 24, 173, 132, 194, 132, 
	170, 132, 132, 149, 132, 132, 24, 24, 
	24, 173, 132, 149, 132, 170, 132, 132, 
	149, 132, 132, 24, 24, 24, 23, 27, 
	26, 196, 196, 195, 27, 26, 197, 197, 
	195, 27, 26, 198, 198, 195, 27, 26, 
	26, 26, 195, 132, 132, 132, 132, 132, 
	132, 132, 26, 26, 132, 26, 159, 129, 
	129, 24, 137, 129, 25, 24, 129, 24, 
	129, 24, 24, 158, 132, 200, 132, 132, 
	132, 132, 200, 132, 132, 201, 201, 201, 
	199, 132, 200, 138, 132, 132, 132, 200, 
	132, 132, 201, 201, 201, 199, 202, 201, 
	201, 201, 201, 199, 201, 201, 201, 201, 
	201, 199, 25, 24, 24, 139, 139, 139, 
	203, 205, 206, 207, 208, 209, 210, 211, 
	206, 207, 208, 212, 210, 211, 204, 214, 
	141, 213, 214, 213, 216, 215, 25, 217, 
	24, 217, 24, 139, 139, 139, 203, 25, 
	218, 24, 218, 24, 139, 139, 139, 203, 
	219, 25, 24, 24, 139, 139, 139, 203, 
	115, 115, 115, 115, 113, 115, 113, 113, 
	113, 115, 113, 113, 220, 25, 221, 24, 
	221, 24, 139, 139, 139, 203, 25, 222, 
	24, 222, 24, 139, 139, 139, 203, 25, 
	223, 24, 223, 24, 139, 139, 139, 203, 
	219, 25, 218, 24, 218, 24, 139, 139, 
	139, 203, 25, 224, 24, 224, 24, 139, 
	139, 139, 203, 25, 225, 24, 225, 24, 
	139, 139, 139, 203, 25, 226, 24, 226, 
	24, 139, 139, 139, 203, 25, 227, 24, 
	227, 24, 139, 139, 139, 203, 25, 228, 
	24, 228, 24, 139, 139, 139, 203, 229, 
	25, 24, 24, 139, 139, 139, 203, 119, 
	118, 230, 230, 220, 119, 118, 231, 231, 
	220, 119, 118, 232, 232, 220, 119, 118, 
	118, 118, 220, 25, 233, 24, 233, 24, 
	139, 139, 139, 203, 25, 218, 24, 218, 
	24, 139, 139, 139, 203, 235, 234, 237, 
	236, 239, 238, 241, 240, 0
};

static const unsigned char _wikitext_trans_targs[] = {
	108, 0, 3, 108, 5, 6, 108, 108, 
	8, 9, 108, 10, 108, 12, 108, 11, 
	14, 15, 108, 17, 18, 19, 108, 108, 
	20, 21, 22, 23, 24, 143, 108, 26, 
	36, 38, 44, 47, 53, 27, 28, 29, 
	30, 31, 32, 33, 34, 35, 108, 37, 
	108, 39, 40, 41, 42, 43, 108, 45, 
	46, 108, 48, 49, 50, 51, 52, 108, 
	54, 108, 56, 65, 57, 58, 59, 60, 
	61, 62, 63, 64, 108, 66, 108, 68, 
	108, 70, 71, 72, 73, 74, 108, 76, 
	77, 108, 79, 80, 81, 82, 83, 108, 
	85, 108, 87, 88, 89, 90, 91, 92, 
	93, 94, 95, 96, 97, 108, 108, 99, 
	100, 161, 108, 101, 103, 104, 105, 106, 
	107, 172, 1, 2, 4, 108, 108, 109, 
	110, 111, 108, 108, 112, 113, 114, 108, 
	118, 148, 149, 153, 154, 155, 157, 158, 
	162, 166, 176, 178, 179, 142, 108, 180, 
	108, 181, 108, 108, 108, 110, 108, 108, 
	108, 7, 13, 16, 108, 115, 116, 117, 
	108, 119, 147, 120, 121, 108, 122, 123, 
	124, 125, 126, 127, 128, 129, 130, 131, 
	132, 133, 134, 135, 136, 137, 138, 139, 
	140, 141, 142, 108, 144, 145, 146, 108, 
	150, 151, 152, 108, 108, 25, 55, 67, 
	69, 75, 78, 84, 86, 108, 156, 108, 
	108, 159, 160, 98, 108, 163, 164, 165, 
	167, 168, 169, 170, 171, 102, 173, 174, 
	175, 177, 108, 108, 108, 108, 108, 108, 
	108, 108
};

static const unsigned char _wikitext_trans_actions[] = {
	122, 0, 0, 125, 0, 0, 128, 111, 
	0, 0, 63, 0, 61, 0, 59, 0, 
	0, 0, 57, 0, 0, 0, 55, 117, 
	0, 0, 0, 0, 0, 137, 113, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 23, 0, 
	33, 0, 0, 0, 0, 0, 13, 0, 
	0, 19, 0, 0, 0, 0, 0, 29, 
	0, 39, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 21, 0, 47, 0, 
	31, 0, 0, 0, 0, 0, 11, 0, 
	0, 15, 0, 0, 0, 0, 0, 27, 
	0, 37, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 17, 115, 0, 
	0, 9, 109, 0, 0, 0, 0, 0, 
	0, 134, 0, 0, 0, 119, 149, 3, 
	1, 0, 65, 43, 0, 9, 0, 45, 
	146, 140, 0, 143, 9, 1, 1, 143, 
	143, 143, 143, 0, 0, 146, 35, 0, 
	53, 0, 101, 71, 77, 0, 103, 107, 
	93, 0, 0, 0, 73, 0, 0, 0, 
	25, 146, 146, 146, 131, 79, 131, 131, 
	131, 131, 131, 131, 131, 131, 131, 131, 
	131, 131, 131, 131, 131, 131, 131, 131, 
	131, 131, 131, 85, 137, 137, 137, 87, 
	0, 0, 0, 105, 95, 0, 0, 0, 
	0, 0, 0, 0, 0, 81, 0, 75, 
	41, 143, 143, 0, 83, 143, 143, 143, 
	143, 143, 143, 143, 143, 0, 134, 134, 
	134, 143, 89, 49, 91, 51, 97, 67, 
	99, 69
};

static const unsigned char _wikitext_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 5, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const unsigned char _wikitext_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 7, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const short _wikitext_eof_trans[] = {
	0, 0, 0, 0, 0, 0, 0, 8, 
	8, 8, 8, 8, 8, 8, 8, 8, 
	8, 8, 8, 8, 24, 24, 24, 24, 
	24, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 111, 111, 111, 115, 111, 111, 
	111, 24, 24, 24, 0, 155, 157, 159, 
	160, 161, 165, 165, 165, 165, 160, 160, 
	160, 174, 174, 174, 174, 174, 174, 174, 
	174, 174, 174, 174, 174, 174, 174, 174, 
	174, 174, 174, 174, 174, 174, 24, 196, 
	196, 196, 196, 160, 159, 200, 200, 200, 
	200, 204, 205, 214, 214, 216, 204, 204, 
	204, 221, 204, 204, 204, 204, 204, 204, 
	204, 204, 204, 204, 221, 221, 221, 221, 
	204, 204, 235, 237, 239, 241
};

static const int wikitext_start = 108;
static const int wikitext_first_final = 108;
static const int wikitext_error = 0;

static const int wikitext_en_main = 108;


#line 495 "wikitext_ragel.rl"


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
    
#line 659 "wikitext_ragel.c"
	{
	cs = wikitext_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 537 "wikitext_ragel.rl"
    
#line 669 "wikitext_ragel.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _wikitext_actions + _wikitext_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 6:
#line 1 "NONE"
	{ts = p;}
	break;
#line 690 "wikitext_ragel.c"
		}
	}

	_keys = _wikitext_trans_keys + _wikitext_key_offsets[cs];
	_trans = _wikitext_index_offsets[cs];

	_klen = _wikitext_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _wikitext_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _wikitext_indicies[_trans];
_eof_trans:
	cs = _wikitext_trans_targs[_trans];

	if ( _wikitext_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _wikitext_actions + _wikitext_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 45 "wikitext_ragel.rl"
	{
        MARK();
    }
	break;
	case 1:
#line 50 "wikitext_ragel.rl"
	{
        out->code_point = *p & 0x7f;
    }
	break;
	case 2:
#line 55 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 1)) & 0x1f) << 6 |
            (*p & 0x3f);
    }
	break;
	case 3:
#line 61 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 2)) & 0x0f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
	break;
	case 4:
#line 68 "wikitext_ragel.rl"
	{
        out->code_point = ((uint32_t)(*(p - 3)) & 0x07) << 18 |
            ((uint32_t)(*(p - 2)) & 0x3f) << 12 |
            ((uint32_t)(*(p - 1)) & 0x3f) << 6 |
            (*p & 0x3f);
    }
	break;
	case 7:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 8:
#line 244 "wikitext_ragel.rl"
	{act = 20;}
	break;
	case 9:
#line 309 "wikitext_ragel.rl"
	{act = 23;}
	break;
	case 10:
#line 315 "wikitext_ragel.rl"
	{act = 24;}
	break;
	case 11:
#line 448 "wikitext_ragel.rl"
	{act = 45;}
	break;
	case 12:
#line 454 "wikitext_ragel.rl"
	{act = 46;}
	break;
	case 13:
#line 466 "wikitext_ragel.rl"
	{act = 47;}
	break;
	case 14:
#line 90 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_START);
            {p++; goto _out; }
        }}
	break;
	case 15:
#line 96 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_END);
            {p++; goto _out; }
        }}
	break;
	case 16:
#line 102 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; goto _out; }
        }}
	break;
	case 17:
#line 108 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; goto _out; }
        }}
	break;
	case 18:
#line 114 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_END);
            {p++; goto _out; }
        }}
	break;
	case 19:
#line 120 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_START);
            {p++; goto _out; }
        }}
	break;
	case 20:
#line 126 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_END);
            {p++; goto _out; }
        }}
	break;
	case 21:
#line 132 "wikitext_ragel.rl"
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
            {p++; goto _out; }
        }}
	break;
	case 22:
#line 150 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_START);
            {p++; goto _out; }
        }}
	break;
	case 23:
#line 156 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_END);
            {p++; goto _out; }
        }}
	break;
	case 24:
#line 162 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_START);
            {p++; goto _out; }
        }}
	break;
	case 25:
#line 168 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_END);
            {p++; goto _out; }
        }}
	break;
	case 26:
#line 174 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT);
            {p++; goto _out; }
        }}
	break;
	case 27:
#line 180 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_START);
            {p++; goto _out; }
        }}
	break;
	case 28:
#line 186 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_END);
            {p++; goto _out; }
        }}
	break;
	case 29:
#line 193 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; goto _out; }
        }}
	break;
	case 30:
#line 218 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(OL);
            else
                EMIT(PRINTABLE);
            {p++; goto _out; }
        }}
	break;
	case 31:
#line 231 "wikitext_ragel.rl"
	{te = p+1;{
            if (out->column_start == 1              ||
                last_token_type == OL               ||
                last_token_type == UL               ||
                last_token_type == BLOCKQUOTE       ||
                last_token_type == BLOCKQUOTE_START)
                EMIT(UL);
            else
                EMIT(PRINTABLE);
            {p++; goto _out; }
        }}
	break;
	case 32:
#line 250 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BR);
            {p++; goto _out; }
        }}
	break;
	case 33:
#line 327 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_START);
            {p++; goto _out; }
        }}
	break;
	case 34:
#line 333 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_END);
            {p++; goto _out; }
        }}
	break;
	case 35:
#line 339 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SEPARATOR);
            {p++; goto _out; }
        }}
	break;
	case 36:
#line 357 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 37:
#line 363 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(AMP_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 38:
#line 369 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NAMED_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 39:
#line 375 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(HEX_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 40:
#line 381 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DECIMAL_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 41:
#line 387 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT);
            {p++; goto _out; }
        }}
	break;
	case 42:
#line 411 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_START);
            {p++; goto _out; }
        }}
	break;
	case 43:
#line 417 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_END);
            {p++; goto _out; }
        }}
	break;
	case 44:
#line 435 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; goto _out; }
        }}
	break;
	case 45:
#line 486 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; goto _out; }
        }}
	break;
	case 46:
#line 132 "wikitext_ragel.rl"
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
            {p++; goto _out; }
        }}
	break;
	case 47:
#line 193 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
                EMIT(BLOCKQUOTE);
            else
            {
                REWIND();
                EMIT(GREATER);
            }
            {p++; goto _out; }
        }}
	break;
	case 48:
#line 206 "wikitext_ragel.rl"
	{te = p;p--;{
            if (out->column_start == 1 || last_token_type == BLOCKQUOTE)
            {
                REWIND();
                EMIT(PRE);
            }
            else
                EMIT(SPACE);
            {p++; goto _out; }
        }}
	break;
	case 49:
#line 244 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(HR);
            {p++; goto _out; }
        }}
	break;
	case 50:
#line 256 "wikitext_ragel.rl"
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
            {p++; goto _out; }
        }}
	break;
	case 51:
#line 309 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(URI);
            {p++; goto _out; }
        }}
	break;
	case 52:
#line 315 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(MAIL);
            {p++; goto _out; }
        }}
	break;
	case 53:
#line 321 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PATH);
            {p++; goto _out; }
        }}
	break;
	case 54:
#line 345 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_START);
            {p++; goto _out; }
        }}
	break;
	case 55:
#line 351 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_END);
            {p++; goto _out; }
        }}
	break;
	case 56:
#line 393 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(AMP);
            {p++; goto _out; }
        }}
	break;
	case 57:
#line 399 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LESS);
            {p++; goto _out; }
        }}
	break;
	case 58:
#line 423 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LEFT_CURLY);
            {p++; goto _out; }
        }}
	break;
	case 59:
#line 429 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(RIGHT_CURLY);
            {p++; goto _out; }
        }}
	break;
	case 60:
#line 435 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; goto _out; }
        }}
	break;
	case 61:
#line 448 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(SPECIAL_URI_CHARS);
            {p++; goto _out; }
        }}
	break;
	case 62:
#line 454 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(ALNUM);
            {p++; goto _out; }
        }}
	break;
	case 63:
#line 466 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PRINTABLE);
            {p++; goto _out; }
        }}
	break;
	case 64:
#line 309 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(URI);
            {p++; goto _out; }
        }}
	break;
	case 65:
#line 393 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(AMP);
            {p++; goto _out; }
        }}
	break;
	case 66:
#line 399 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(LESS);
            {p++; goto _out; }
        }}
	break;
	case 67:
#line 454 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(ALNUM);
            {p++; goto _out; }
        }}
	break;
	case 68:
#line 1 "NONE"
	{	switch( act ) {
	case 20:
	{{p = ((te))-1;}
            EMIT(HR);
            {p++; goto _out; }
        }
	break;
	case 23:
	{{p = ((te))-1;}
            EMIT(URI);
            {p++; goto _out; }
        }
	break;
	case 24:
	{{p = ((te))-1;}
            EMIT(MAIL);
            {p++; goto _out; }
        }
	break;
	case 45:
	{{p = ((te))-1;}
            EMIT(SPECIAL_URI_CHARS);
            {p++; goto _out; }
        }
	break;
	case 46:
	{{p = ((te))-1;}
            EMIT(ALNUM);
            {p++; goto _out; }
        }
	break;
	case 47:
	{{p = ((te))-1;}
            EMIT(PRINTABLE);
            {p++; goto _out; }
        }
	break;
	}
	}
	break;
#line 1348 "wikitext_ragel.c"
		}
	}

_again:
	_acts = _wikitext_actions + _wikitext_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 5:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 1361 "wikitext_ragel.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _wikitext_eof_trans[cs] > 0 ) {
		_trans = _wikitext_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 538 "wikitext_ragel.rl"
    if (cs == wikitext_error)
        rb_raise(eWikitextParserError, "failed before finding a token");
    else if (out->type == NO_TOKEN)
        rb_raise(eWikitextParserError, "failed to produce a token");
}
