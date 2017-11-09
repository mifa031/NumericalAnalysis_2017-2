#include<stdio.h>
#include<stdlib.h>

#define SIZE 2

int A[2][2] = { { 3,1 },{ -6,-4 } };
int L[2][2];
int U[2][2];

void main() {
	U[0][0] = A[0][0]; 
	U[0][1] = A[0][1];
	U[1][0] = 0; 
	U[1][1] = A[1][1] - (A[1][0] / A[0][0])*A[0][1];
	double c = A[1][0] / A[0][0];

	L[0][0] = 1; 
	L[0][1] = 0;
	L[1][0] = c; 
	L[1][1] = 1;

	printf("L \n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", L[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("U \n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", U[i][j]);
		}
		printf("\n");
	}

}