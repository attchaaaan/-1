#include<math.h>
#include<stdio.h>

/*���p����֐��̉���Ԃ�*/
double kansu(double x) {

	return(x*x-54);
}

/*�^����ꂽx�ɑ΂���֐��̌X����Ԃ�*/
double katamuki(double x) {

	return(2 * x);
}

double newton(double x, double e) {

	double x_new = x;//x�̏����l��������
	double x_old;

	do {
		x_old = x_new;
		x_new = x_old - kansu(x_old) / katamuki(x_old);
		printf("old_x=%lf-->new_x=%lf\n", x_old, x_new);
	} while (fabs(x_new - x_old) > e);//x���W�̍���e�������������ɌJ��Ԃ����I������

	return(x_new);
}

void main() {
	double e = 0.001;//臒l
	double x = 54.0;//x���W�̏����l
	double result = 0.0;//�ŏI�I�Ȍ��ʂ�������

	result = newton(x, e);//臒l��x���W�̏����l���֐��ɓn��

	printf("e=%lf, result=%lf\n", e, result);
}