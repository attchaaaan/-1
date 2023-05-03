#include<stdio.h>
void main() {
	short u;
	unsigned short v;

	u = 32767;
	v = 65535;

	printf("SHORT_MAX=%d\n", u);
	printf("USHORT_MAX=%d\n", v);

	u = u + 1;
	v = v + 1;

	printf("SHORT_MAX+1=%d\n", u);
	printf("USHORT_MAX+1=%d\n", v);

	u = u - 1;
	v = v - 1;

	printf("SHORT_MAX+1-1=%d\n", u);
	printf("USHORT_MAX+1-1=%d\n", v);
}