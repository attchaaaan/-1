#include<stdio.h>
#include<math.h>

#define EPS 0.000001//閾値

/*使用する関数を定義する関数*/
double gfunc(double x, double y) {
	return(2.0 * x + 1);

}

double euler(double x_0, double y_0, double h, double x_n) {
	double x = x_0;
	double y = y_0;

	while (fabs(x - x_n) > EPS) {//閾値以上の時ループを繰り返す
		y = y + gfunc(x, y) * h;//値を変える
		x = x + h;//値を変える
	}
	return(y);
}

/*メイン関数内で値を定義しておく*/
void main() {
	double h = 0.001;//オイラー法における刻み幅
	double y0 = 0.0;
	double x0 = 0.0;

	printf("result=%lf\n", euler(x0, y0, h, 5.0));
}