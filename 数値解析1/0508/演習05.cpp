#include<stdio.h>
#include<math.h>

double func(double x) {
	return(x * x - 10);
}

double bisection(double xs, double xl, double EPS) {
	double xm;

	do {
		xm = (xs + xl) * 0.5;

		if (func(xs) * func(xm) < 0)
			xl = xm;
		else
			xs = xm;
	} while (fabs((xs - xl) * 0.5) > EPS);

	return((xs + xl) * 0.5);
}

void main() {
	double eps = 0.01;
	double xl = 4.0;
	double xs = 0.0;
	double result = 0.0;

	result = bisection(xs, xl, eps);

	printf("dx=%lf,result=%lf\n", eps, result);
}