#define _USE_MATH_DEFINES  //�~����M_PI���g����悤�ɂ���
#include<stdio.h>
#include<math.h>

double func(double x) { //�^����ꂽx�ɑ΂������Ԃ��֐�
	return(4.0 * sqrt(1.0 - x * x)); //sqrt()�͕����������߂�
}

void main() {
	double h = 0.1, b = 1.0, a = 0.0, result = 0.0, t, r;
	long cycle = (b - a) / h;

	for (long i = 0; i < cycle; i++) {
		t = a + (double)i * h;
		result = result + (func(t + h) + func(t)) * h / 2;
	}

	printf("h=%lf,result=%lf\n", h, result);

/*�덷�̑��ΓI�Ȋ��������߂�*/
	r = fabs((result - M_PI) / M_PI); //fabs()�͐�Βl�����߂�

	printf("�~�����ɑ΂���덷�̑��ΓI�Ȋ�����%.10lf\n", r);
}
