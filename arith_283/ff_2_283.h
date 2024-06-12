/*
    This file is part of the Binary Finite Field Library Version 0.02
    Copyright (C) 2001 Antonio Bellezza

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
/*
       Finite field with 2^283 elements with a polynomial base
       generated by x^283 + x^12 + x^7 + x^5 + x^0
*/



#ifndef FF_2_283_H
#define FF_2_283_H


#include "../params.h"

#define FFBITS 283
#define BLOCKS ( (FFBITS + sizeof(ff_block)*8-1) / (sizeof(ff_block)*8) )

#define ff_mul(a, b, c) ff_mul_lrcomb_w4(a,b,c)
#define ff_sub(a, b, c) ff_add(a,b,c)


struct ff_element_struct {
    ff_block data[BLOCKS];
};

typedef struct ff_element_struct ff_element[1];


extern ff_element ff_one, ff_zero;


void ff_add(ff_element a, ff_element b, ff_element c); // c <- a + b
void ff_square(ff_element a, ff_element b); // b <- a^2
void ff_mul_rlcomb(ff_element a, ff_element b, ff_element c);

void ff_mul_lrcomb(ff_element a, ff_element b, ff_element c);

void ff_mul_lrcomb_w4(ff_element a, ff_element b, ff_element c);

void ff_inv(ff_element a, ff_element b); // b <- 1/a
void ff_div(ff_element a, ff_element b, ff_element c); // c <- a / b

void ff_copy(ff_element a, ff_element b); // b <- a

void ff_set(ff_element a, ff_block b[BLOCKS]);

void ff_rand(ff_element a);

void ff_read(ff_element a); // Set a from stdin
void ff_sread(const char *s, ff_element a); // Set a from string s
void ff_print(ff_element a); // Print a

int ff_eq(ff_element a, ff_element b); // a==b


#endif
