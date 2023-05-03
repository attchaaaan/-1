#define _USE_MATH_DEFINES//M_PIを使えるようにする
#include<stdio.h>
#include<math.h>

double func(double x) {
	double d = 0.5;
	return(d-sin(x));
}

double bisection(double xs, double xl, double EPS) {
	double xm;

	do {
		xm = (xs + xl) * 0.5;
		printf("xs=%lf,xl=%lf\n", xs, xl);
		if ((func(xs)) * (func(xm)) < 0)//この時正の値と負の値をとる
			xl = xm;
		else
			xs = xm;
		
	} while (fabs((xs - xl) * 0.5) > EPS);//epsより大きい時ループを繰り返す
	printf("xs=%lf,xl=%lf\n", xs, xl);
	return((xs + xl) * 0.5);
}

void main() {
	double eps = 0.001;
	double xl = 0.5*M_PI;//解探索区間の最大値
	double xs =-0.5*M_PI ;//解探索区間の最小値
	double result = 0.0;
	

	result = bisection(xs, xl, eps);

	printf("epsを%lfとしたときxの値は%lf\n", eps, result);
}