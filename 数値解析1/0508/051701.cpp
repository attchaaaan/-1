#include<stdio.h>
void main() {
	int i;
	float a = 0.0;
	double b = 0.0;
	float m;
	double n;
	printf("Input m\n");
	scanf("%f", &m);
	printf("Input n\n");
	scanf("%lf", &n);

	for (i = 0; i <= 1000000000; i++) {

		a = a + m;
		b = b + n;

		if (i == 1000 || i == 1000000 || i == 1000000000)
			printf("float a=%f, double b=%lf \n", a, b);
	}
}