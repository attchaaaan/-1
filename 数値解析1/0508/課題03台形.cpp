#define _USE_MATH_DEFINES  //円周率M_PIを使えるようにする
#include<stdio.h>
#include<math.h>

double func(double x) { //与えられたxに対する解を返す関数
	return(4.0 * sqrt(1.0 - x * x)); //sqrt()は平方根を求める
}

void main() {
	double h = 0.1, b = 1.0, a = 0.0, result = 0.0, t, r;
	long cycle = (b - a) / h;

	for (long i = 0; i < cycle; i++) {
		t = a + (double)i * h;
		result = result + (func(t + h) + func(t)) * h / 2;
	}

	printf("h=%lf,result=%lf\n", h, result);

/*誤差の相対的な割合を求める*/
	r = fabs((result - M_PI) / M_PI); //fabs()は絶対値を求める

	printf("円周率に対する誤差の相対的な割合は%.10lf\n", r);
}
