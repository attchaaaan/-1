#include<stdio.h>
#include<math.h>

#define EPS 0.00001//閾値をプログラム全体で使えるように定義する
#define G 9.8066//重力加速度を定義

double gfunc(double t, double v) {
	return(-G);//鉛直上向きに運動するので重力加速度にマイナスをつける
}

double euler(double t_0, double v_0, double h, double t_n) {
	double t = t_0;
	double v = v_0;
	double t0;

	/*物体が上昇から下降に変わる瞬間の時間を求める*/
	t0 = v / G;
	printf("物体が上昇から下降に変わる瞬間の時間はt=%lf\n", t0);
	
	while (fabs(t - t_n) > EPS) {
		v = v + gfunc(t, v) * h;
		t = t + h;
	}
	return(v);//t=4.0のときのvをメイン関数に返す
}

void main() {
	double h = 0.001;//刻み幅
	double v = 54.0;//初速
	double t = 4;//時間

	printf("result=%lf[m/s]\n", euler(0.0, v, h, t));//各値をeuler関数に渡して結果を出力する
}