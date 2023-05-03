#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

double func(double x) {
	return(3.0*x*x*x*x-3.0*x*x*x+2.0*x*x+8.0*x-3.0);
}

void main() {
	double h = 0.1, b = 3.0, a = 0.0, result = 0.0, t,r;
	long cycle = (b - a) / h;

	for (long i = 0; i < cycle; i++) {

		t = a + (double)i * h;
		result = result+(func(t)+func(t+h)+4.0*func(t+h/2.0))*h/6.0;
	}
	printf("h=%lf,result=%lf\n", h, result);

	r = result - M_PI;
	printf("%lf\n", r);
}