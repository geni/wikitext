
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
	6, 1, 7, 1, 17, 1, 18, 1, 
	19, 1, 20, 1, 21, 1, 22, 1, 
	23, 1, 24, 1, 25, 1, 26, 1, 
	27, 1, 28, 1, 29, 1, 30, 1, 
	31, 1, 32, 1, 33, 1, 34, 1, 
	35, 1, 36, 1, 37, 1, 38, 1, 
	39, 1, 40, 1, 41, 1, 42, 1, 
	43, 1, 44, 1, 45, 1, 46, 1, 
	48, 1, 49, 1, 50, 1, 51, 1, 
	52, 1, 53, 1, 54, 1, 55, 1, 
	56, 1, 57, 1, 58, 1, 59, 1, 
	60, 1, 61, 1, 62, 1, 63, 1, 
	64, 1, 65, 1, 66, 1, 67, 1, 
	68, 1, 69, 1, 70, 1, 71, 1, 
	72, 2, 1, 47, 2, 2, 47, 2, 
	3, 47, 2, 4, 47, 2, 7, 8, 
	2, 7, 9, 2, 7, 10, 2, 7, 
	11, 2, 7, 12, 2, 7, 13, 2, 
	7, 14, 2, 7, 15, 2, 7, 16, 
	2, 46, 1
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
	216, 217, 229, 241, 250, 264, 266, 268, 
	270, 272, 287, 302, 311, 313, 314, 316, 
	318, 320, 322, 324, 325, 327, 329, 330, 
	332, 334, 336, 338, 340, 341, 343, 344, 
	346, 348, 350, 351, 352, 353, 354, 355, 
	356, 360, 365, 366, 367, 368, 382, 398, 
	407, 417, 423, 430, 436, 443, 497, 498, 
	499, 507, 517, 524, 525, 526, 527, 528, 
	544, 560, 576, 592, 608, 624, 640, 656, 
	672, 688, 704, 720, 736, 752, 768, 784, 
	800, 816, 832, 848, 864, 880, 896, 912, 
	928, 935, 942, 949, 956, 972, 989, 1005, 
	1021, 1029, 1038, 1048, 1061, 1070, 1079, 1094, 
	1096, 1097, 1098, 1110, 1122, 1133, 1149, 1161, 
	1173, 1185, 1198, 1210, 1222, 1234, 1246, 1258, 
	1269, 1276, 1283, 1290, 1297, 1309, 1321, 1322, 
	1323, 1324
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
	62, 32, 62, 9, 13, 33, 47, 58, 
	64, 91, 96, 123, 126, 32, 62, 9, 
	13, 33, 47, 58, 64, 91, 96, 123, 
	126, 62, 33, 47, 58, 64, 91, 96, 
	123, 126, 32, 62, 67, 99, 9, 13, 
	33, 47, 58, 64, 91, 96, 123, 126, 
	76, 108, 69, 101, 65, 97, 82, 114, 
	62, 33, 47, 48, 57, 58, 64, 65, 
	90, 91, 96, 97, 122, 123, 126, 62, 
	33, 47, 48, 57, 58, 64, 65, 90, 
	91, 96, 97, 122, 123, 126, 62, 33, 
	47, 58, 64, 91, 96, 123, 126, 77, 
	109, 62, 79, 111, 87, 119, 73, 105, 
	75, 107, 73, 105, 62, 82, 114, 69, 
	101, 62, 84, 116, 82, 114, 79, 111, 
	78, 110, 71, 103, 62, 84, 116, 62, 
	82, 114, 69, 101, 32, 62, 108, 97, 
	110, 103, 61, 34, 65, 90, 97, 122, 
	34, 65, 90, 97, 122, 62, 47, 47, 
	45, 61, 95, 126, 35, 40, 42, 43, 
	47, 57, 64, 90, 97, 122, 33, 41, 
	44, 46, 61, 63, 95, 126, 35, 57, 
	58, 59, 64, 90, 97, 122, 95, 45, 
	46, 48, 57, 65, 90, 97, 122, 64, 
	95, 45, 46, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 46, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	65, 90, 97, 122, 46, 48, 57, 65, 
	90, 97, 122, 10, 13, 32, 33, 34, 
	35, 38, 39, 42, 43, 45, 46, 47, 
	60, 61, 62, 64, 70, 72, 77, 83, 
	91, 92, 93, 94, 95, 96, 102, 104, 
	109, 115, 123, 124, 125, 126, 127, -62, 
	-33, -32, -17, -16, -12, 1, 31, 36, 
	37, 40, 44, 48, 57, 58, 63, 65, 
	122, 10, 32, 33, 44, 46, 63, 40, 
	41, 58, 59, 43, 45, 47, 64, 92, 
	126, 36, 37, 94, 95, 35, 97, 113, 
	65, 90, 98, 122, 39, 39, 39, 39, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	43, 45, 47, 64, 92, 94, 95, 126, 
	36, 37, 46, 57, 65, 90, 97, 122, 
	46, 48, 57, 65, 90, 97, 122, 46, 
	48, 57, 65, 90, 97, 122, 46, 48, 
	57, 65, 90, 97, 122, 46, 48, 57, 
	65, 90, 97, 122, 43, 45, 47, 64, 
	92, 126, 36, 37, 48, 57, 65, 90, 
	94, 95, 97, 122, 33, 44, 45, 46, 
	63, 64, 95, 40, 41, 48, 57, 58, 
	59, 65, 90, 97, 122, 43, 45, 47, 
	64, 92, 94, 95, 126, 36, 37, 46, 
	57, 65, 90, 97, 122, 43, 45, 47, 
	64, 92, 94, 95, 126, 36, 37, 46, 
	57, 65, 90, 97, 122, 47, 95, 45, 
	57, 65, 90, 97, 122, 95, 45, 46, 
	48, 57, 65, 90, 97, 122, 64, 95, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	47, 66, 69, 78, 80, 83, 84, 98, 
	101, 110, 112, 115, 116, 62, 33, 47, 
	58, 64, 91, 96, 123, 126, 62, 33, 
	47, 58, 64, 91, 96, 123, 126, 62, 
	33, 47, 48, 57, 58, 64, 65, 90, 
	91, 96, 97, 122, 123, 126, 32, 61, 
	32, 32, 64, 84, 95, 116, 45, 46, 
	48, 57, 65, 90, 97, 122, 64, 80, 
	95, 112, 45, 46, 48, 57, 65, 90, 
	97, 122, 58, 64, 95, 45, 46, 48, 
	57, 65, 90, 97, 122, 33, 41, 44, 
	46, 61, 63, 95, 126, 35, 57, 58, 
	59, 64, 90, 97, 122, 64, 84, 95, 
	116, 45, 46, 48, 57, 65, 90, 97, 
	122, 64, 84, 95, 116, 45, 46, 48, 
	57, 65, 90, 97, 122, 64, 80, 95, 
	112, 45, 46, 48, 57, 65, 90, 97, 
	122, 58, 64, 83, 95, 115, 45, 46, 
	48, 57, 65, 90, 97, 122, 64, 65, 
	95, 97, 45, 46, 48, 57, 66, 90, 
	98, 122, 64, 73, 95, 105, 45, 46, 
	48, 57, 65, 90, 97, 122, 64, 76, 
	95, 108, 45, 46, 48, 57, 65, 90, 
	97, 122, 64, 84, 95, 116, 45, 46, 
	48, 57, 65, 90, 97, 122, 64, 79, 
	95, 111, 45, 46, 48, 57, 65, 90, 
	97, 122, 58, 64, 95, 45, 46, 48, 
	57, 65, 90, 97, 122, 46, 48, 57, 
	65, 90, 97, 122, 46, 48, 57, 65, 
	90, 97, 122, 46, 48, 57, 65, 90, 
	97, 122, 46, 48, 57, 65, 90, 97, 
	122, 64, 86, 95, 118, 45, 46, 48, 
	57, 65, 90, 97, 122, 64, 78, 95, 
	110, 45, 46, 48, 57, 65, 90, 97, 
	122, 91, 93, 123, 125, 0
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
	1, 2, 2, 1, 4, 2, 2, 2, 
	2, 1, 1, 1, 2, 1, 2, 2, 
	2, 2, 2, 1, 2, 2, 1, 2, 
	2, 2, 2, 2, 1, 2, 1, 2, 
	2, 2, 1, 1, 1, 1, 1, 1, 
	0, 1, 1, 1, 1, 4, 8, 1, 
	2, 0, 1, 0, 1, 36, 1, 1, 
	4, 6, 3, 1, 1, 1, 1, 8, 
	8, 8, 8, 8, 8, 8, 8, 8, 
	8, 8, 8, 8, 8, 8, 8, 8, 
	8, 8, 8, 8, 8, 8, 8, 8, 
	1, 1, 1, 1, 6, 7, 8, 8, 
	2, 1, 2, 13, 1, 1, 1, 2, 
	1, 1, 4, 4, 3, 8, 4, 4, 
	4, 5, 4, 4, 4, 4, 4, 3, 
	1, 1, 1, 1, 4, 4, 1, 1, 
	1, 1
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
	0, 5, 5, 4, 5, 0, 0, 0, 
	0, 7, 7, 4, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	2, 2, 0, 0, 0, 5, 4, 4, 
	4, 3, 3, 3, 3, 9, 0, 0, 
	2, 2, 2, 0, 0, 0, 0, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	3, 3, 3, 3, 5, 5, 4, 4, 
	3, 4, 4, 0, 4, 4, 7, 0, 
	0, 0, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	3, 3, 3, 3, 4, 4, 0, 0, 
	0, 0
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
	224, 226, 234, 242, 248, 258, 261, 264, 
	267, 270, 279, 288, 294, 297, 299, 302, 
	305, 308, 311, 314, 316, 319, 322, 324, 
	327, 330, 333, 336, 339, 341, 344, 346, 
	349, 352, 355, 357, 359, 361, 363, 365, 
	367, 370, 374, 376, 378, 380, 390, 403, 
	409, 416, 420, 425, 429, 434, 480, 482, 
	484, 491, 500, 506, 508, 510, 512, 514, 
	527, 540, 553, 566, 579, 592, 605, 618, 
	631, 644, 657, 670, 683, 696, 709, 722, 
	735, 748, 761, 774, 787, 800, 813, 826, 
	839, 844, 849, 854, 859, 871, 884, 897, 
	910, 916, 922, 929, 943, 949, 955, 964, 
	967, 969, 971, 980, 989, 997, 1010, 1019, 
	1028, 1037, 1047, 1056, 1065, 1074, 1083, 1092, 
	1100, 1105, 1110, 1115, 1120, 1129, 1138, 1140, 
	1142, 1144
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
	76, 30, 78, 80, 77, 79, 79, 79, 
	79, 30, 77, 80, 77, 79, 79, 79, 
	79, 30, 80, 79, 79, 79, 79, 23, 
	77, 80, 81, 81, 77, 79, 79, 79, 
	79, 30, 82, 82, 30, 83, 83, 30, 
	84, 84, 30, 85, 85, 30, 87, 85, 
	86, 85, 86, 85, 86, 85, 23, 89, 
	88, 86, 88, 86, 88, 86, 88, 23, 
	89, 88, 88, 88, 88, 23, 90, 90, 
	30, 91, 30, 92, 92, 30, 93, 93, 
	30, 94, 94, 30, 95, 95, 30, 96, 
	96, 30, 97, 30, 98, 98, 30, 99, 
	99, 30, 100, 30, 101, 101, 30, 102, 
	102, 30, 103, 103, 30, 104, 104, 30, 
	105, 105, 30, 106, 30, 107, 107, 30, 
	108, 30, 98, 109, 30, 99, 110, 30, 
	111, 100, 30, 112, 30, 113, 30, 114, 
	30, 115, 30, 116, 30, 117, 30, 118, 
	118, 30, 119, 118, 118, 30, 120, 30, 
	122, 121, 123, 121, 124, 124, 124, 124, 
	124, 124, 124, 124, 124, 121, 126, 126, 
	126, 126, 124, 126, 124, 124, 124, 126, 
	124, 124, 125, 127, 127, 127, 127, 127, 
	121, 128, 127, 127, 127, 127, 127, 121, 
	129, 129, 129, 121, 130, 129, 129, 129, 
	23, 129, 131, 131, 23, 130, 129, 132, 
	132, 23, 137, 138, 139, 140, 141, 142, 
	144, 145, 146, 143, 147, 148, 149, 151, 
	152, 153, 143, 154, 155, 156, 157, 158, 
	143, 159, 143, 160, 161, 154, 155, 156, 
	157, 162, 163, 164, 143, 136, 133, 134, 
	135, 136, 143, 140, 150, 140, 150, 1, 
	166, 165, 168, 167, 140, 140, 140, 140, 
	140, 140, 169, 143, 143, 143, 143, 143, 
	143, 143, 143, 170, 172, 173, 174, 15, 
	15, 171, 176, 175, 177, 175, 178, 175, 
	179, 175, 143, 180, 143, 181, 143, 143, 
	160, 143, 143, 24, 24, 24, 170, 143, 
	182, 143, 181, 143, 143, 160, 143, 143, 
	24, 24, 24, 170, 143, 183, 143, 181, 
	143, 143, 160, 143, 143, 24, 24, 24, 
	170, 143, 185, 143, 181, 143, 143, 160, 
	143, 143, 24, 24, 24, 184, 143, 186, 
	143, 181, 143, 143, 160, 143, 143, 24, 
	24, 24, 184, 143, 187, 143, 181, 143, 
	143, 160, 143, 143, 24, 24, 24, 184, 
	143, 188, 143, 181, 143, 143, 160, 143, 
	143, 24, 24, 24, 184, 143, 189, 143, 
	181, 143, 143, 160, 143, 143, 24, 24, 
	24, 184, 143, 190, 143, 181, 143, 143, 
	160, 143, 143, 24, 24, 24, 184, 143, 
	191, 143, 181, 143, 143, 160, 143, 143, 
	24, 24, 24, 184, 143, 192, 143, 181, 
	143, 143, 160, 143, 143, 24, 24, 24, 
	184, 143, 193, 143, 181, 143, 143, 160, 
	143, 143, 24, 24, 24, 184, 143, 194, 
	143, 181, 143, 143, 160, 143, 143, 24, 
	24, 24, 184, 143, 195, 143, 181, 143, 
	143, 160, 143, 143, 24, 24, 24, 184, 
	143, 196, 143, 181, 143, 143, 160, 143, 
	143, 24, 24, 24, 184, 143, 197, 143, 
	181, 143, 143, 160, 143, 143, 24, 24, 
	24, 184, 143, 198, 143, 181, 143, 143, 
	160, 143, 143, 24, 24, 24, 184, 143, 
	199, 143, 181, 143, 143, 160, 143, 143, 
	24, 24, 24, 184, 143, 200, 143, 181, 
	143, 143, 160, 143, 143, 24, 24, 24, 
	184, 143, 201, 143, 181, 143, 143, 160, 
	143, 143, 24, 24, 24, 184, 143, 202, 
	143, 181, 143, 143, 160, 143, 143, 24, 
	24, 24, 184, 143, 203, 143, 181, 143, 
	143, 160, 143, 143, 24, 24, 24, 184, 
	143, 204, 143, 181, 143, 143, 160, 143, 
	143, 24, 24, 24, 184, 143, 205, 143, 
	181, 143, 143, 160, 143, 143, 24, 24, 
	24, 184, 143, 160, 143, 181, 143, 143, 
	160, 143, 143, 24, 24, 24, 23, 27, 
	26, 207, 207, 206, 27, 26, 208, 208, 
	206, 27, 26, 209, 209, 206, 27, 26, 
	26, 26, 206, 143, 143, 143, 143, 143, 
	143, 143, 26, 26, 143, 26, 170, 140, 
	140, 24, 148, 140, 25, 24, 140, 24, 
	140, 24, 24, 169, 143, 211, 143, 143, 
	143, 143, 211, 143, 143, 212, 212, 212, 
	210, 143, 211, 149, 143, 143, 143, 211, 
	143, 143, 212, 212, 212, 210, 213, 212, 
	212, 212, 212, 210, 212, 212, 212, 212, 
	212, 210, 25, 24, 24, 150, 150, 150, 
	214, 216, 217, 218, 219, 220, 221, 222, 
	217, 218, 219, 223, 221, 222, 215, 80, 
	79, 79, 79, 79, 224, 89, 88, 88, 
	88, 88, 225, 87, 85, 86, 85, 86, 
	85, 86, 85, 225, 227, 152, 226, 227, 
	226, 229, 228, 25, 230, 24, 230, 24, 
	150, 150, 150, 214, 25, 231, 24, 231, 
	24, 150, 150, 150, 214, 232, 25, 24, 
	24, 150, 150, 150, 214, 126, 126, 126, 
	126, 124, 126, 124, 124, 124, 126, 124, 
	124, 233, 25, 234, 24, 234, 24, 150, 
	150, 150, 214, 25, 235, 24, 235, 24, 
	150, 150, 150, 214, 25, 236, 24, 236, 
	24, 150, 150, 150, 214, 232, 25, 231, 
	24, 231, 24, 150, 150, 150, 214, 25, 
	237, 24, 237, 24, 150, 150, 150, 214, 
	25, 238, 24, 238, 24, 150, 150, 150, 
	214, 25, 239, 24, 239, 24, 150, 150, 
	150, 214, 25, 240, 24, 240, 24, 150, 
	150, 150, 214, 25, 241, 24, 241, 24, 
	150, 150, 150, 214, 242, 25, 24, 24, 
	150, 150, 150, 214, 130, 129, 243, 243, 
	233, 130, 129, 244, 244, 233, 130, 129, 
	245, 245, 233, 130, 129, 129, 129, 233, 
	25, 246, 24, 246, 24, 150, 150, 150, 
	214, 25, 231, 24, 231, 24, 150, 150, 
	150, 214, 248, 247, 250, 249, 252, 251, 
	254, 253, 0
};

static const unsigned char _wikitext_trans_targs[] = {
	117, 0, 3, 117, 5, 6, 117, 117, 
	8, 9, 117, 10, 117, 12, 117, 11, 
	14, 15, 117, 17, 18, 19, 117, 117, 
	20, 21, 22, 23, 24, 152, 117, 26, 
	36, 38, 44, 47, 53, 27, 28, 29, 
	30, 31, 32, 33, 34, 35, 117, 37, 
	117, 39, 40, 41, 42, 43, 117, 45, 
	46, 117, 48, 49, 50, 51, 52, 117, 
	54, 117, 56, 65, 57, 58, 59, 60, 
	61, 62, 63, 64, 117, 66, 68, 67, 
	164, 69, 70, 71, 72, 73, 74, 166, 
	75, 165, 77, 117, 79, 80, 81, 82, 
	83, 117, 85, 86, 117, 88, 89, 90, 
	91, 92, 117, 94, 117, 96, 97, 98, 
	99, 100, 101, 102, 103, 104, 105, 106, 
	117, 117, 108, 109, 173, 117, 110, 112, 
	113, 114, 115, 116, 184, 1, 2, 4, 
	117, 117, 118, 119, 120, 117, 117, 121, 
	122, 123, 117, 127, 157, 158, 162, 163, 
	167, 169, 170, 174, 178, 188, 190, 191, 
	151, 117, 192, 117, 193, 117, 117, 117, 
	119, 117, 117, 117, 7, 13, 16, 117, 
	124, 125, 126, 117, 128, 156, 129, 130, 
	117, 131, 132, 133, 134, 135, 136, 137, 
	138, 139, 140, 141, 142, 143, 144, 145, 
	146, 147, 148, 149, 150, 151, 117, 153, 
	154, 155, 117, 159, 160, 161, 117, 117, 
	25, 55, 76, 78, 84, 87, 93, 95, 
	117, 117, 117, 168, 117, 117, 171, 172, 
	107, 117, 175, 176, 177, 179, 180, 181, 
	182, 183, 111, 185, 186, 187, 189, 117, 
	117, 117, 117, 117, 117, 117, 117
};

static const unsigned char _wikitext_trans_actions[] = {
	124, 0, 0, 127, 0, 0, 130, 113, 
	0, 0, 61, 0, 59, 0, 57, 0, 
	0, 0, 55, 0, 0, 0, 53, 119, 
	0, 0, 0, 0, 0, 145, 115, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 23, 0, 
	33, 0, 0, 0, 0, 0, 13, 0, 
	0, 19, 0, 0, 0, 0, 0, 29, 
	0, 39, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 21, 0, 0, 0, 
	139, 0, 0, 0, 0, 0, 0, 136, 
	0, 136, 0, 31, 0, 0, 0, 0, 
	0, 11, 0, 0, 15, 0, 0, 0, 
	0, 0, 27, 0, 37, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	17, 117, 0, 0, 9, 111, 0, 0, 
	0, 0, 0, 0, 142, 0, 0, 0, 
	121, 160, 3, 1, 0, 63, 43, 0, 
	9, 0, 45, 157, 151, 0, 154, 148, 
	1, 1, 154, 154, 154, 154, 0, 0, 
	157, 35, 0, 51, 0, 103, 69, 75, 
	0, 105, 109, 95, 0, 0, 0, 71, 
	0, 0, 0, 25, 157, 157, 157, 133, 
	77, 133, 133, 133, 133, 133, 133, 133, 
	133, 133, 133, 133, 133, 133, 133, 133, 
	133, 133, 133, 133, 133, 133, 87, 145, 
	145, 145, 89, 0, 0, 0, 107, 97, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	81, 79, 83, 0, 73, 41, 154, 154, 
	0, 85, 154, 154, 154, 154, 154, 154, 
	154, 154, 0, 142, 142, 142, 154, 91, 
	47, 93, 49, 99, 65, 101, 67
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
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 5, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0
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
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 7, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0
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
	31, 31, 31, 24, 31, 31, 31, 31, 
	31, 24, 24, 24, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 31, 31, 31, 31, 31, 
	31, 31, 31, 122, 122, 122, 126, 122, 
	122, 122, 24, 24, 24, 0, 166, 168, 
	170, 171, 172, 176, 176, 176, 176, 171, 
	171, 171, 185, 185, 185, 185, 185, 185, 
	185, 185, 185, 185, 185, 185, 185, 185, 
	185, 185, 185, 185, 185, 185, 185, 24, 
	207, 207, 207, 207, 171, 170, 211, 211, 
	211, 211, 215, 216, 225, 226, 226, 227, 
	227, 229, 215, 215, 215, 234, 215, 215, 
	215, 215, 215, 215, 215, 215, 215, 215, 
	234, 234, 234, 234, 215, 215, 248, 250, 
	252, 254
};

static const int wikitext_start = 117;
static const int wikitext_first_final = 117;
static const int wikitext_error = 0;

static const int wikitext_en_main = 117;


#line 502 "wikitext_ragel.rl"


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
    
#line 702 "wikitext_ragel.c"
	{
	cs = wikitext_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 544 "wikitext_ragel.rl"
    
#line 712 "wikitext_ragel.c"
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
#line 733 "wikitext_ragel.c"
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
#line 251 "wikitext_ragel.rl"
	{act = 21;}
	break;
	case 10:
#line 257 "wikitext_ragel.rl"
	{act = 22;}
	break;
	case 11:
#line 316 "wikitext_ragel.rl"
	{act = 24;}
	break;
	case 12:
#line 322 "wikitext_ragel.rl"
	{act = 25;}
	break;
	case 13:
#line 406 "wikitext_ragel.rl"
	{act = 39;}
	break;
	case 14:
#line 455 "wikitext_ragel.rl"
	{act = 46;}
	break;
	case 15:
#line 461 "wikitext_ragel.rl"
	{act = 47;}
	break;
	case 16:
#line 473 "wikitext_ragel.rl"
	{act = 48;}
	break;
	case 17:
#line 90 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_START);
            {p++; goto _out; }
        }}
	break;
	case 18:
#line 96 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NO_WIKI_END);
            {p++; goto _out; }
        }}
	break;
	case 19:
#line 102 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; goto _out; }
        }}
	break;
	case 20:
#line 108 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_START);
            {p++; goto _out; }
        }}
	break;
	case 21:
#line 114 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(PRE_END);
            {p++; goto _out; }
        }}
	break;
	case 22:
#line 120 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_START);
            {p++; goto _out; }
        }}
	break;
	case 23:
#line 126 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(BLOCKQUOTE_END);
            {p++; goto _out; }
        }}
	break;
	case 24:
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
	case 25:
#line 150 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_START);
            {p++; goto _out; }
        }}
	break;
	case 26:
#line 156 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(STRONG_END);
            {p++; goto _out; }
        }}
	break;
	case 27:
#line 162 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_START);
            {p++; goto _out; }
        }}
	break;
	case 28:
#line 168 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(EM_END);
            {p++; goto _out; }
        }}
	break;
	case 29:
#line 174 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT);
            {p++; goto _out; }
        }}
	break;
	case 30:
#line 180 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_START);
            {p++; goto _out; }
        }}
	break;
	case 31:
#line 186 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(TT_END);
            {p++; goto _out; }
        }}
	break;
	case 32:
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
	case 33:
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
	case 34:
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
	case 35:
#line 334 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_START);
            {p++; goto _out; }
        }}
	break;
	case 36:
#line 340 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(LINK_END);
            {p++; goto _out; }
        }}
	break;
	case 37:
#line 346 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(SEPARATOR);
            {p++; goto _out; }
        }}
	break;
	case 38:
#line 364 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 39:
#line 370 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(AMP_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 40:
#line 376 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(NAMED_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 41:
#line 382 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(HEX_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 42:
#line 388 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DECIMAL_ENTITY);
            {p++; goto _out; }
        }}
	break;
	case 43:
#line 394 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(QUOT);
            {p++; goto _out; }
        }}
	break;
	case 44:
#line 418 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_START);
            {p++; goto _out; }
        }}
	break;
	case 45:
#line 424 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(IMG_END);
            {p++; goto _out; }
        }}
	break;
	case 46:
#line 442 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; goto _out; }
        }}
	break;
	case 47:
#line 493 "wikitext_ragel.rl"
	{te = p+1;{
            EMIT(DEFAULT);
            out->column_stop = out->column_start + 1;
            {p++; goto _out; }
        }}
	break;
	case 48:
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
	case 49:
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
	case 50:
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
	case 51:
#line 244 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(HR);
            {p++; goto _out; }
        }}
	break;
	case 52:
#line 251 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(BR_CLEAR);
            {p++; goto _out; }
        }}
	break;
	case 53:
#line 257 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(BR);
            {p++; goto _out; }
        }}
	break;
	case 54:
#line 263 "wikitext_ragel.rl"
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
	case 55:
#line 316 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(URI);
            {p++; goto _out; }
        }}
	break;
	case 56:
#line 322 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(MAIL);
            {p++; goto _out; }
        }}
	break;
	case 57:
#line 328 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PATH);
            {p++; goto _out; }
        }}
	break;
	case 58:
#line 352 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_START);
            {p++; goto _out; }
        }}
	break;
	case 59:
#line 358 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(EXT_LINK_END);
            {p++; goto _out; }
        }}
	break;
	case 60:
#line 400 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(AMP);
            {p++; goto _out; }
        }}
	break;
	case 61:
#line 406 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LESS);
            {p++; goto _out; }
        }}
	break;
	case 62:
#line 430 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(LEFT_CURLY);
            {p++; goto _out; }
        }}
	break;
	case 63:
#line 436 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(RIGHT_CURLY);
            {p++; goto _out; }
        }}
	break;
	case 64:
#line 442 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(CRLF);
            out->column_stop = 1;
            out->line_stop++;
            {p++; goto _out; }
        }}
	break;
	case 65:
#line 455 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(SPECIAL_URI_CHARS);
            {p++; goto _out; }
        }}
	break;
	case 66:
#line 461 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(ALNUM);
            {p++; goto _out; }
        }}
	break;
	case 67:
#line 473 "wikitext_ragel.rl"
	{te = p;p--;{
            EMIT(PRINTABLE);
            {p++; goto _out; }
        }}
	break;
	case 68:
#line 316 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(URI);
            {p++; goto _out; }
        }}
	break;
	case 69:
#line 400 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(AMP);
            {p++; goto _out; }
        }}
	break;
	case 70:
#line 406 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(LESS);
            {p++; goto _out; }
        }}
	break;
	case 71:
#line 461 "wikitext_ragel.rl"
	{{p = ((te))-1;}{
            EMIT(ALNUM);
            {p++; goto _out; }
        }}
	break;
	case 72:
#line 1 "NONE"
	{	switch( act ) {
	case 20:
	{{p = ((te))-1;}
            EMIT(HR);
            {p++; goto _out; }
        }
	break;
	case 21:
	{{p = ((te))-1;}
            EMIT(BR_CLEAR);
            {p++; goto _out; }
        }
	break;
	case 22:
	{{p = ((te))-1;}
            EMIT(BR);
            {p++; goto _out; }
        }
	break;
	case 24:
	{{p = ((te))-1;}
            EMIT(URI);
            {p++; goto _out; }
        }
	break;
	case 25:
	{{p = ((te))-1;}
            EMIT(MAIL);
            {p++; goto _out; }
        }
	break;
	case 39:
	{{p = ((te))-1;}
            EMIT(LESS);
            {p++; goto _out; }
        }
	break;
	case 46:
	{{p = ((te))-1;}
            EMIT(SPECIAL_URI_CHARS);
            {p++; goto _out; }
        }
	break;
	case 47:
	{{p = ((te))-1;}
            EMIT(ALNUM);
            {p++; goto _out; }
        }
	break;
	case 48:
	{{p = ((te))-1;}
            EMIT(PRINTABLE);
            {p++; goto _out; }
        }
	break;
	}
	}
	break;
#line 1428 "wikitext_ragel.c"
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
#line 1441 "wikitext_ragel.c"
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

#line 545 "wikitext_ragel.rl"
    if (cs == wikitext_error)
        rb_raise(eWikitextParserError, "failed before finding a token");
    else if (out->type == NO_TOKEN)
        rb_raise(eWikitextParserError, "failed to produce a token");
}
