#include <stdio.h>
#define N 4//4�s4��̍s��̌v�Z

int count = 0;//�v�Z�񐔂��L�^����

//�v�Z�ߒ����o�͂���֐�
void print_matrixA(double A[][N + 1]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			printf("%lf", A[i][j]);

		}
		printf(" \n");
	}
	printf(" \n");
}

//�����o�͂���֐�
void print_matrix(double X[]) {
	for (int i = 0; i < N; i++) {
		printf("%lf\n", X[i]);
	}
	printf(" \n");
}

void my_gauss(double A[][N + 1], double X[]) {
	int i, j, h;

	//�O�i�������s��
	for (i = 0; i < N; i++) {
		for (j = N; j >= i; j--) {
			A[i][j] = A[i][j] / A[i][i];
			count = count + 1;
		}
		for (h = i + 1; h < N; h++) {
			for (j = N; j >= i; j--) {
				A[h][j] = A[h][j] - A[i][j] * A[h][i];
			}
		}
		print_matrixA(A);
	}
	//��ޑ�����s��
	X[3] = A[4][5];
	X[2] = A[3][5]-X[3]*A[3][4];
	X[1] = A[2][5]-X[3]*A[2][4]-X[2]*A[2][3];
	X[0] = A[1][5]-X[3]*A[1][4]-X[2]*A[1][3]-X[1]*A[1][2];
	
	double aih;

	
	for (i = N - 1; i >= 0; i--) {
		for (h = i - 1; h >= 0; h--) {
			aih = A[h][i];
			for (j = 0; j <= N; j++) {
				A[h][j] = A[h][j] - A[i][j] * aih;
			}
		}
		print_matrixA(A);
		X[i] = A[i][N];
	}
	print_matrix(X);
		printf("Total count=%d\n", count);//�v�Z�񐔂�\������
}

void main() {

	double A[N][N + 1] = { {4.0,1.0,-3.0,0.0,0.0},
		{2.0,0.0,3.0,-2.0,0.0},
		{0.0,-1.0,3.0,2.0,25.0},
		{10.0,-4.0,0.0,-3.0,5.0} };//�s��

	double X[N] = { 0.0,0.0,0.0,0.0 };//��������s��
	
	print_matrixA(A);
	my_gauss(A, X);
}