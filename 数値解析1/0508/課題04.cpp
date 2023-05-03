#define _USE_MATH_DEFINES//�~������\��M_PI���g����悤�ɂ���
#include<stdio.h>
#include<math.h>//���w�֐�����荞��

double func(double x) {
	return(4.0 * sqrt(1.0 - x * x));//sqrt()�͕�������Ԃ�
}

void main() {
	double h = 0.0001, b = 1.0, a = 0.0, result = 0.0, t,r;
	long cycle = (b - a) / h;

	for (long i = 0; i < cycle; i++) {

		t = a + (double)i * h;

		/*��4��̍u�`���e�̎����Q��*/
		result = result + (func(t) + func(t + h) + 4.0 * func(t + h / 2.0)) * h / 6.0;
	}
	printf("h=%lf,result=%lf\n", h, result);

	/*�덷�̑��ΓI�Ȋ��������߂�*/
	r = fabs((result - M_PI) / M_PI);//fabs()�͐�Βl�����߂�

	printf("�~�����ɑ΂���덷�̑��ΓI�Ȋ�����%.10lf\n", r);//�����_�ȉ��̕\�������𑝂₷

}