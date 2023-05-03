#include<stdio.h>
#include<math.h>

#define EPS 0.000001//臒l

/*�g�p����֐����`����֐�*/
double gfunc(double x, double y) {
	return(2.0 * x + 1);

}

double euler(double x_0, double y_0, double h, double x_n) {
	double x = x_0;
	double y = y_0;

	while (fabs(x - x_n) > EPS) {//臒l�ȏ�̎����[�v���J��Ԃ�
		y = y + gfunc(x, y) * h;//�l��ς���
		x = x + h;//�l��ς���
	}
	return(y);
}

/*���C���֐����Œl���`���Ă���*/
void main() {
	double h = 0.001;//�I�C���[�@�ɂ����鍏�ݕ�
	double y0 = 0.0;
	double x0 = 0.0;

	printf("result=%lf\n", euler(x0, y0, h, 5.0));
}