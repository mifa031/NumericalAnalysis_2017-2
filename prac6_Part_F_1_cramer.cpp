#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 3  // SIZE by SIZE matrix 

double det(double **matrix, int size);
double cofactor(double **matrix, int row, int col, int size);
void cramer(double** A, double* B, double* X, int size);

void main() {
	double** A; // A in AX = B
	A = (double**)calloc(SIZE, sizeof(double*));
	for (int i = 0; i<SIZE; i++) {
		A[i] = (double*)calloc(SIZE,sizeof(double));
	}
	A[0][0] = 1; A[0][1] = 1; A[0][2] = 1; // Initialize A
	A[1][0] = 2.8; A[1][1] = 3; A[1][2] = 3.2;
	A[2][0] = 1; A[2][1] = 0; A[2][2] = -2;

	double* B; // B in AX = B
	B = (double*)calloc(SIZE, sizeof(double));
	B[0] = 3900; B[1] = 11460; B[2] = 0;           // Initialize B

	double* X; // X in AX = B
	X = (double*)calloc(SIZE, sizeof(double));

	cramer(A, B, X, SIZE);                  // Get X by Cramer's rule
	for (int i = 0; i < SIZE; i++)
		printf("X%d = %lf\n", i + 1, X[i]);

	for (int i = 0; i < SIZE; i++)
		free(A[i]);
	free(A);
	free(B);
	free(X);
}

void cramer(double** A, double* B, double* X, int size) {
	double** temp;
	temp = (double**)calloc(size, sizeof(double*));
	for (int i = 0; i<size; i++) {
		temp[i] = (double*)calloc(size, sizeof(double));
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			temp[i][j] = A[i][j];
	
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++)
			temp[i][j] = B[i];
		X[j] = det(temp, size) / det(A, size);
		for (int i = 0; i < size; i++)
			temp[i][j] = A[i][j];
	}

	for (int i = 0; i < size; i++)
		free(temp[i]);
	free(temp);
}

double det(double** matrix, int size) {
	int p = 0, q = 0;
	double det = 0;

	if (size == 1) {
		return matrix[0][0];
	}
	else if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		for (q = 0, det = 0; q<size; q++) {
			det = det + matrix[0][q] * cofactor(matrix, 0, q, size);
		}
		return det;
	}
	return 0;
}

double cofactor(double** matrix, int row, int col, int size) {
	int i = 0, j = 0;
	int x = 0, y = 0;
	double **cmat;
	double cofactor = 0;

	cmat = (double**)malloc(sizeof(double*) * (size - 1));
	for (i = 0; i<(size - 1); i++) {
		cmat[i] = (double*)malloc(sizeof(double) * (size - 1));
	}

	for (i = 0, x = 0; i<size; i++) {
		if (i != row) {
			for (j = 0, y = 0; j<size; j++) {
				if (j != col) {
					cmat[x][y] = matrix[i][j];
					y++;
				}
			}
			x++;
		}
	}

	cofactor = pow(-1, row)*pow(-1, col)*det(cmat, size - 1);

	for (i = 0; i<(size - 1); i++) {
		free(cmat[i]);
	}
	free(cmat);

	return cofactor;
}