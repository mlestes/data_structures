#ifndef __MY_MATH__
#define __MY_MATH__

#include <stdio.h>
#include <stdlib.h>

//To use: cast int/float to double

//absolute value
double my_abs(double x);

//rounds a double up to the next integer
int my_ceil(double x);

//rounds a double down to the next integer
int my_floor(double x);

//truncate
int my_trunc(double x);

//determines the maximum value
double my_max(double a, double b);

//determines the minimum value
double my_min(double a, double b);

//raises a value to a power
void my_pow(double *x, int exp);
#endif
