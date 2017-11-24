#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double A[2][2];
double C[2][2];
double X[2][1] = { { 1.0 },{ 1.0 } };
double V[2][1];
double EigenVector[2][1];
double Dominant_EigenValue;

int main(void) {
	double temp1[2][1];
	double temp2=0.0;
	double temp3;
	double sum;
	int iter;
	int count = 1;

	printf("A배열을 입력하세요 : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%lf", &A[i][j]);
			C[i][j] = A[i][j];
		}
	}
	printf("Iterator number : \n");
			scanf("%d",&iter);
	printf("|Iterator     Value1        Value2\n");
	while (count<=iter) {
		for (int i = 0; i < 2; i++) {
			sum = 0;
			for (int j = 0; j < 2; j++) {
				sum=sum+A[i][j] * X[j][0];
			}
			V[i][0] = sum;
		}
	printf("%2d %17.5f %13.5f\n",count,V[0][0],V[1][0]);
	X[0][0] = V[0][0];
	X[1][0] = V[1][0];
	count++;
	}
	if (V[0][0] >= V[1][1]) {
		for (int i = 0; i < 2; i++) {
			EigenVector[i][0] = V[i][0] / V[0][0];
		}
	}else{
		for (int i = 0; i < 2; i++) {
			EigenVector[i][0] = V[i][0] / V[1][0];
		}
	}

	for (int i = 0; i < 2; i++) {
		sum = 0;
		for (int j = 0; j < 2; j++) {
			sum = sum + A[i][j] * EigenVector[j][0];
		}
		temp1[i][0] = sum;
	}
	for (int i = 0; i < 2; i++) {
		temp2 = temp2+temp1[i][0] * EigenVector[i][0];
	}


	temp3 = EigenVector[0][0] * EigenVector[0][0] + EigenVector[1][0] * EigenVector[1][0];
	
	Dominant_EigenValue = temp2 / temp3;
	printf("\nDominant_EigenValue : %.5f \n",Dominant_EigenValue);
	printf("Dominant_EigenVector1 : %.5f, Dominant_EigenVector2 : %.5f \n", EigenVector[0][0],EigenVector[1][0]);
	return 0;
}