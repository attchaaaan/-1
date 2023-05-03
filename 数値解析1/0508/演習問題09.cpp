#include<stdio.h>
#include<math.h>
double student(double t, double y, double v) {
	
	double k = 10.0, m = 20.0, c = 0.0,result;

	result = -k / m * y;
	return(result);
}

double location(double y_0, double v_0, double t_0, double t_n, double h) {

	double t = t_0, y = y_0, v = v_0, t_new, y_new, v_new;

	while (t < t_n) {
		
		if ((int)(t / h) % 100 == 0)
			printf("%lf,%lf,%lf\n", t, y, v);
		t_new = t + h;
		v_new = v + h * student(t, y, v);
		y_new = y + h * v;

		t = t_new;
		v = v_new;
		y = y_new;

	}

	return(y);

}

void main() {
	double h = 0.001, t_0 = 0.0, v_0 = sqrt(54), y_0 = 0.05, t_n = 12.0;

	printf("result=%lf[m]\n", location(y_0, v_0, t_0, t_n, h));
}