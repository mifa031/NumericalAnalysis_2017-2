#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main() {
	int n;
	double* x;
	double* y;
	double sum_x = 0;
	double sum_y = 0;
	double sum_xy = 0;
	double sum_x_square = 0, sum_y_square = 0;
	double x_bar, y_bar;
	double a0, a1, r;

	printf("Input number of samples : ");
	scanf("%d", &n);
	x = (double*)malloc(sizeof(double)*n);
	y = (double*)malloc(sizeof(double)*n);

	for (int i = 0; i < n; i++) {
		printf("Input x_value y_value : ");
		scanf("%lf %lf", &x[i], &y[i]);
	}

	for (int i = 0; i < n; i++) {
		sum_x += x[i];
		sum_y += y[i];
		sum_xy += (x[i] * y[i]);
		sum_x_square += pow(x[i],2);
		sum_y_square += pow(y[i],2);
	}
	x_bar = sum_x / n;
	y_bar = sum_y / n;
	
	a1 = (n*sum_xy - sum_x*sum_y) / (n*sum_x_square - pow(sum_x, 2));
	a0 = y_bar - a1*x_bar;
	r = (n*sum_xy - sum_x*sum_y) / (sqrt(n*sum_x_square - pow(sum_x, 2)) * sqrt(n*sum_y_square - pow(sum_y, 2)));

	printf("a0 : %.5f, a1 : %.5f, r : %.5f\n",a0,a1,r);
	printf("Regression Model : Y = %.5f + %.5f*X\n",a0,a1);
}