#include<stdio.h>
#include<math.h>
#define N 4

//�s����o�͂���֐�
void print_matrixA(double A[][N + 1]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			printf("%lf ", A[i][j]);
		}
		printf(" \n");
	}
	printf(" \n");
}

void print_matrixX2(double X[]) {
	for (int i = 0; i < N; i++) {
		printf("%lf ", X[i]);
	}
	printf(" \n");
}

double check_err(double newX[], double X[]) {

	double max_err = 0.0;

	for (int i = 0; i < N; i++) {
		if (fabs(newX[i] - X[i]) > max_err)
			max_err = fabs(newX[i] - X[i]);
	}
	return(max_err);
}

void my_jacobi(double A[][N + 1], double X[], int kmax, double err) {
	double newX[N];

	int i, j;
	int k = 0;

	for (k = 0; k < kmax; k++) {
		printf("%d-->", k);//����ڂ��̌v�Z��
		print_matrixX2(X);//k��ڂ̌��ʂ��o��

		for (i = 0; i < N; i++) {

			newX[i] = A[i][N] / A[i][i];

			for (j = 0; j < N; j++) {

				//i��j�̑召�ŏꍇ����
				if (j < i)
					newX[i] = newX[i] - A[i][j] * X[j+1] / A[i][i];
				if (j > i)
					newX[i] = newX[i] - A[i][j] * X[j] / A[i][i];
			}
		}

		//���e�덷���Ŏ��܂������ǂ������f����
		if (check_err(newX, X) < err)
			k = kmax;

		for (i = 0; i < N; i++) {
			X[i] = newX[i];
		}
	}
}

void main() {

	//�s��̒l
	double A[N][N + 1] = { {8.0,1.0,2.0,1.0,40.0},
						   {2.0,4.0,1.0,-2.0,20.0},
						   {2.0,0.0,6.0,1.0,21.0},
						   {1.0,3.0,-2.0,8.0,17.0} };

	//������
	double X[N] = { 0,0,0,0 };

	//�֐����Ăяo��
	print_matrixA(A);
	my_jacobi(A, X, 100, 0.00001);
}