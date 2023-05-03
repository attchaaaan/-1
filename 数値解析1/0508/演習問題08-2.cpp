#include<stdio.h>
#include<math.h>

#define EPS 0.00001//臒l���v���O�����S�̂Ŏg����悤�ɒ�`����
#define G 9.8066//�d�͉����x���`

double gfunc(double t, double v) {
	return(-G);//����������ɉ^������̂ŏd�͉����x�Ƀ}�C�i�X������
}

double euler(double t_0, double v_0, double h, double t_n) {
	double t = t_0;
	double v = v_0;
	double t0;

	/*���̂��㏸���牺�~�ɕς��u�Ԃ̎��Ԃ����߂�*/
	t0 = v / G;
	printf("���̂��㏸���牺�~�ɕς��u�Ԃ̎��Ԃ�t=%lf\n", t0);
	
	while (fabs(t - t_n) > EPS) {
		v = v + gfunc(t, v) * h;
		t = t + h;
	}
	return(v);//t=4.0�̂Ƃ���v�����C���֐��ɕԂ�
}

void main() {
	double h = 0.001;//���ݕ�
	double v = 54.0;//����
	double t = 4;//����

	printf("result=%lf[m/s]\n", euler(0.0, v, h, t));//�e�l��euler�֐��ɓn���Č��ʂ��o�͂���
}