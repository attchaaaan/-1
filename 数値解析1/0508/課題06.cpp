#include<math.h>
#include<stdio.h>

/*利用する関数の解を返す*/
double kansu(double x) {

	return(x*x-54);
}

/*与えられたxに対する関数の傾きを返す*/
double katamuki(double x) {

	return(2 * x);
}

double newton(double x, double e) {

	double x_new = x;//xの初期値を代入する
	double x_old;

	do {
		x_old = x_new;
		x_new = x_old - kansu(x_old) / katamuki(x_old);
		printf("old_x=%lf-->new_x=%lf\n", x_old, x_new);
	} while (fabs(x_new - x_old) > e);//x座標の差がeよりも小さい時に繰り返しを終了する

	return(x_new);
}

void main() {
	double e = 0.001;//閾値
	double x = 54.0;//x座標の初期値
	double result = 0.0;//最終的な結果を代入する

	result = newton(x, e);//閾値とx座標の初期値を関数に渡す

	printf("e=%lf, result=%lf\n", e, result);
}