#define _USE_MATH_DEFINES//M_PI���g����悤�ɂ���
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
		if ((func(xs)) * (func(xm)) < 0)//���̎����̒l�ƕ��̒l���Ƃ�
			xl = xm;
		else
			xs = xm;
		
	} while (fabs((xs - xl) * 0.5) > EPS);//eps���傫�������[�v���J��Ԃ�
	printf("xs=%lf,xl=%lf\n", xs, xl);
	return((xs + xl) * 0.5);
}

void main() {
	double eps = 0.001;
	double xl = 0.5*M_PI;//��T����Ԃ̍ő�l
	double xs =-0.5*M_PI ;//��T����Ԃ̍ŏ��l
	double result = 0.0;
	

	result = bisection(xs, xl, eps);

	printf("eps��%lf�Ƃ����Ƃ�x�̒l��%lf\n", eps, result);
}