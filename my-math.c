/******************************************************************************
 * my-math.c
 * AUTHOR: Murray Estes
 * Description: Basic math operations that are found in math library.
 *              Implemented so as to not have to link math library. Also good
 *              practice. More operations will be added if I think of them.
 *              Decided to use doubles since that allows greatest versatility
 *              without implementing different versions for each data type.
 *              User must cast all parameters to double.
 ******************************************************************************
 * Usage:
 * my_abs(x): Absolute value [fabs(x)]
 * 	int a = (int) my_abs((double) x);
 * 	float f = (float) my_abs((double) x);
 * 	double d = my_abs(x);
 *
 * my_ceil(x): Rounds a decimal to the next integer [ceil(x)]
 * 	int c = my_ceil((double) x);
 *
 * my_floor(x): Rounds a decimal down to the next integer [floor(x)]
 * 	int f = my_floor((double) x);
 *
 * my_trunc(x): Truncates a decimal [trunc(x)]
 * 	int t = my_trunc((double) x);
 *
 * my_max(a, b) / my_min(a, b): Returns the max/min respectively
 * 	int m = (int) my_max((double) a, (double) b);
 * 	float f = (float) my_min((double) a, (double) b);
 * 	double d = my_min(a, b);
 ******************************************************************************/

#include "my-math.h"

double my_abs(double x){return x > 0 ? x : -x;}
double my_max(double a, double b){return a > b ? a : b;}
double my_min(double a, double b){return a < b ? a : b;}
int my_trunc(double x){return x;}
void my_pow(double *x, int exp){

	double origin = *x;
	if(exp == 0) *x = 1;
	else if(exp < 0){
		*x = 1.0 / *x;
		for(int i = 2; i < -exp; i++) *x = *x * (1.0 / origin);
	}
	else
		for(int i = 1; i < exp; i++) *x = *x * origin;

}

int my_floor(double x){

	if(x > 0) return x;
	else return x / (int) x == 1 ? x : x - 1;

}

int my_ceil(double x){

	if(x > 0) return x / (int) x == 1 ? x : x + 1;
	else return x;

}
