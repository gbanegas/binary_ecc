//
// Created by obiwan on 12/06/24.
//

#ifndef BIN_THOMAS_BIN_ECC_OP_H
#define BIN_THOMAS_BIN_ECC_OP_H

#include "params.h"
#define BIN_233 1


#ifdef BIN_233
#include "arith_233/ff_2_233.h"
#elif BIN_283
#include "arith_283/ff_2_283.h"
#endif

typedef  struct {
    ff_element A;
    ff_element x;
} ec;

typedef struct {
    ff_element x;
} point;


void point_add(point *c, point const *a, point const *b); //c = a+b

void point_double(point *c, point const *a); //c = 2*a

void point_double_inplace(point *a); //a = 2*a

void point_sub(point *c, point const *a, point const *b); //c = a-b

void point_neg(point *a); //a = -a



#endif //BIN_THOMAS_BIN_ECC_OP_H
