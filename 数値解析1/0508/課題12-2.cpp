#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#define G 9.8066;//�d�͉����x

//x�ɂ��Ă̊֐�
double syahoux(double x, double vx, double vy) {
	double p = 1.184, S = 0.166, C = 0.19, result, M = 1460;

	result = (-vx / sqrt(vx * vx + vy * vy) * 1 / 2 * p * (vx * vx + vy * vy) * S * C) / M;

	return(result);
}


//y�ɂ��Ă̊֐�
double syahouy(double y, double vx, double vy) {
	double p = 1.184, S = 0.166, C = 0.19, result, M = 1460;

	result = (-vy / sqrt(vx * vx + vy * vy) * 1 / 2 * p * (vx * vx + vy * vy) * S * C) / M - G;

	return(result);
}

double ball(double x_0, double vx_0, double ax_0, double y_0, double vy_0, double ay_0, double t_0, double h) {
	//�e�l�̐錾
	double x = x_0, vx = vx_0, ax = ax_0;
	double y = y_0, vy = vy_0, ay = ay_0;
	double t = t_0, x_new, vx_new, ax_new, y_new, vy_new, ay_new, t_new;
	double vxm = 0, vym = 0, axm = 0, aym = 0;

	while (y >= 0) {//�n�ʂɗ�����܂Ń��[�v�𑱂���

		//�V�O�}�̍����v�Z����
		vxm = vxm + vx;
		vym = vym + vy;
		axm = axm + ax;
		aym = aym + ay;

		t_new = t + h;
		ax_new = syahoux(x, vx, vy);
		ay_new = syahouy(y, vx, vy);
		vx_new = vx_0 + axm * h;
		vy_new = vy_0 + aym * h;
		x_new = x_0 + vxm * h;
		y_new = y_0 + vym * h;

		//�l�����ւ���
		t = t_new;
		x = x_new;
		y = y_new;
		vx = vx_new;
		vy = vy_new;
		ax = ax_new;
		ay = ay_new;
	}
	return(x);
}

void main() {
	int i;
	double h = 0.1, x_0 = 0.0, vx_0, ax_0 = 0.0, y_0 = 0.0, vy_0 , ay_0 = -9.8066, t_0 = 0.0,V=780,K,L=0;
	
	for(i=0;L<30050;i++){//30050m�𒴂���܂Ń��[�v
		K = M_PI / 2 * i / 100;//K�͋p
		vx_0 = V * cos(K);//������x��������
		vy_0 = V * sin(K);//������y��������
		L = ball(x_0, vx_0, ax_0, y_0, vy_0, ay_0, t_0, h);
	} 
	printf("�Ƃ�ׂ��p��%lf\n", K);
}