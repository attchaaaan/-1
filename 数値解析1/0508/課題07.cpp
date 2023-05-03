#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>

double func(double x) {
	double d = 0.5;
	return(x*x-54);
}

double dfunc2(double x) {//刻み幅dhを定義しxを与えられた場合の解を返す
	double dh = 0.001;
	return((func(x + dh) - func(x-dh)) / (2*dh));//前進差分法
}

double newton(double x, double e) {

	double x_next = x;
	double x_old;

	do {
		x_old = x_next;
		x_next = x_old - func(x_old) / dfunc2(x_old);
		printf("old_x=%lf-->new_x=%lf\n", x_old, x_next);
	} while (fabs(x_next - x_old) > e);

	return(x_next);
}
void main() {
	double e = 0.001, x = 54.0, result = 0.0;

	result = newton(x, e);

	printf("e=%lf, result=%lf\n", e, result);
}