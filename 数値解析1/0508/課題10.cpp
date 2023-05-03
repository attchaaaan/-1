#include<stdio.h>
#include<math.h>

double gfunc(double t, double v, double y) {

	/*値の宣言*/
	double k = 10.0;
	double m = 20.0;
	double c = 0.0;
	double result;

	result = v;
	return(result);
}

double ffunc(double t, double v, double y) {

	/*値の宣言*/
	double k = 10.0;
	double m = 20.0;
	double c = 0.0;
	double result;

	result = -k / m * y;
	return(result);
}

double rungeKutta2(double y_0, double v_0, double t_0, double t_n, double h) {

	/*値の宣言*/
	double t = t_0;
	double y = y_0;
	double v = v_0;
	double t_new;
	double y_new;
	double v_new;
	double k1, k2, k3, k4, l1, l2, l3, l4;

	while (t < t_n) {

		if ((int)(t / h) % 100 == 0)
			printf("%lf	%lf	%lf\n", t, y, v);

		k1 = gfunc(t,y,v);
		l1 = ffunc(t,y,v);
		k2 = gfunc(t+0.5*h,y+0.5*h*l1,v+0.5*h*k1);
		l2 = ffunc(t + 0.5 * h, y + 0.5 * h * l1, v + 0.5 * h * k1);
		k3 = gfunc(t + 0.5 * h, y + 0.5 * h * l2, v + 0.5 * h * k2);
		l3 = ffunc(t + 0.5 * h, y + 0.5 * h * l2, v + 0.5 * h * k2);
		k4 = gfunc(t + h, y + h *l3, v + h * k3);
		l4 = ffunc(t + h, y + h *l3, v + h * k3);

		/*値の入れ替え*/
		t_new = t + h;
		v_new = v+h*(k1+2*k2+2*k3+k4)/6;
		y_new=y+h*(l1+2*l2+2*l3+l4)/6;

		t = t_new;
		v = v_new;
		y = y_new;
	}

	return(y);
}

void main() {
	/*値の宣言*/
	double h = 0.1;
	double t_0 = 0.0;
	double v_0 = sqrt(54);
	double y_0 = 0.05;
	double t_n = 12.0;

	printf("result=%lf[m]\n", rungeKutta2(y_0, v_0, t_0, t_n, h));
}