#include<stdio.h>
#include<math.h>
#define G 9.8066;//重力加速度

//xについての関数
double syahoux(double x,double vx,double vy) {
	double p = 1.184, S = 0.00418, C = 0.4,result,M=0.14;

	result = (-vx / sqrt(vx * vx + vy * vy) * 1 / 2 * p * (vx * vx + vy * vy) * S * C) / M;

	return(result);
}


//yについての関数
double syahouy( double y, double vx, double vy) {
	double p = 1.184, S = 0.00418, C = 0.4, result, M = 0.14;

	result = (-vy / sqrt(vx * vx + vy * vy) * 1 / 2 * p * (vx * vx + vy * vy) * S * C) / M-G;

	return(result);
}

double ball(double x_0, double vx_0, double ax_0, double y_0, double vy_0, double ay_0, double t_0,  double h) {
	//各値の宣言
	double x = x_0, vx = vx_0, ax = ax_0;
	double y = y_0, vy = vy_0, ay = ay_0;
	double t = t_0, x_new, vx_new, ax_new, y_new, vy_new, ay_new, t_new;
	double vxm=0, vym=0, axm=0, aym=0;

	while (y >= 0) {//地面に落ちるまでループを続ける
		if ((int)(t / h) % 5 == 0)//5回ごとに位置を出力
			printf("%lf	%lf	%lf\n", t, x,y);

		//シグマの項を計算する
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

		//値を入れ替える
		t = t_new;
		x = x_new;
		y = y_new;
		vx = vx_new;
		vy = vy_new;
		ax = ax_new;
		ay = ay_new;
	}
	return(0);
}

void main() {
	//vx_0とvy_0は初速にcos45°とsin45°をかけた数値
	double h = 0.01, x_0 = 0.0, vx_0 = 28.284, ax_0 = 0.0, y_0 = 0.0, vy_0 = 28.284, ay_0 = -9.8066, t_0 = 0.0;
	ball(x_0, vx_0, ax_0, y_0, vy_0, ay_0, t_0, h);
}