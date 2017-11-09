#include<stdio.h>

#define SIZE 3

double A[3][3] = { { 150,-100,0 },{ -100,150,-50 },{0,-50,50} };
double L[3][3];
double U[3][3];
double B[3][1] = { {588.6},{686.7},{784.8} };

void main() {
	U[0][0] = A[0][0]; 
	U[0][1] = A[0][1];
	U[0][2] = A[0][2];

	double c1 = A[1][0] / A[0][0];
	U[1][0] = 0; 
	U[1][1] = A[1][1] - (c1)*A[0][1];
	U[1][2] = A[1][2] - (c1)*A[0][2];
	
	double c2 = A[2][0] / A[0][0];
	U[2][0] = 0;
	U[2][1] = A[2][1] - (c2)*A[0][1];
	U[2][2] = A[2][2] - (c2)*A[0][2];
	
	double c3 = U[2][1] / U[1][1];
	U[2][0] = 0;
	U[2][1] = 0;
	U[2][2] = U[2][2] - (c3)*U[1][2];

	L[0][0] = 1; 
	L[0][1] = 0;
	L[0][2] = 0;

	L[1][0] = c1; 
	L[1][1] = 1;
	L[1][2] = 0;

	L[2][0] = c2;
	L[2][1] = c3;
	L[2][2] = 1;

	printf("L \n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%11.5f ", L[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("U \n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%11.5f ", U[i][j]);
		}
		printf("\n");
	}

}
