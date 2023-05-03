#define _USE_MATH_DEFINES//円周率を表すM_PIを使えるようにする
#include<stdio.h>
#include<math.h>//数学関数を取り込む

double func(double x) {
	return(4.0 * sqrt(1.0 - x * x));//sqrt()は平方根を返す
}

void main() {
	double h = 0.0001, b = 1.0, a = 0.0, result = 0.0, t,r;
	long cycle = (b - a) / h;

	for (long i = 0; i < cycle; i++) {

		t = a + (double)i * h;

		/*第4回の講義内容の式を参照*/
		result = result + (func(t) + func(t + h) + 4.0 * func(t + h / 2.0)) * h / 6.0;
	}
	printf("h=%lf,result=%lf\n", h, result);

	/*誤差の相対的な割合を求める*/
	r = fabs((result - M_PI) / M_PI);//fabs()は絶対値を求める

	printf("円周率に対する誤差の相対的な割合は%.10lf\n", r);//小数点以下の表示桁数を増やす

}