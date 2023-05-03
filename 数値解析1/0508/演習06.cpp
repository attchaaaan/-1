#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>

double func(double x) {

	return(x * x + 2 * x - 8);
}

double dfunc(double x) {

	return(2 * x + 2);
}

double newton(double x, double e) {

	double x_next = x;
	double x_old;

	do {
		x_old = x_next;
		x_next = x_old - func(x_old) / dfunc(x_old);
		printf("old_x=%lf-->new_x=%lf\n", x_old, x_next);
	} while (fabs(x_next - x_old) > e);

	return(x_next);
}
void main() {
	double e = 0.01, x = 4.0, result = 0.0;

	result = newton(x, e);

	printf("e=%lf, result=%lf\n", e, result);
}