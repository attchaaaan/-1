#include<stdio.h>
#include<math.h>

double student(double t, double y, double v) {
	/*各値を宣言する*/
	double k = 10.0, m = 20.0, c = 4.0, result;

	/*ダンパーがあるときの微分方程式を利用*/
	result = -k / m * y - c / m * v;//
	return(result);
}

double location(double y_0, double v_0, double t_0, double t_n, double h) {

	/*各値を宣言する*/
	double t = t_0, y = y_0, v = v_0, t_new, y_new, v_new;

	while (t < t_n) {

		if ((int)(t / h) % 100 == 0)
			printf("%lf	%lf	%lf\n", t, y, v);
		t_new = t + h;
		v_new = v + h * student(t, y, v);
		y_new = y + h * v;

		/*値を入れ替える*/
		t = t_new;
		v = v_new;
		y = y_new;

	}

	return(y);

}

void main() {
	/*各値を宣言する*/
	double h = 0.001, t_0 = 0.0, v_0 = sqrt(54), y_0 = 0.05, t_n = 25.0;
	//sqrt()で平方根を返す
	printf("result=%lf[m]\n", location(y_0, v_0, t_0, t_n, h));
}