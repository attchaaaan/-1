#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

double func(double x) {
	return(3.0 * x * x + 2.0 * x + 2);
}

void main() {
	double h = 0.1, b = 4.0, a = 0.0, result = 0.0, t;
	long cycle = (b - a) / h;

	for (long i = 0; i < cycle; i++) {
		t = a + (double)i * h;
		result = result + h * func(t);
	}

	printf("h=%lf,result=%lf\n", h, result);
}