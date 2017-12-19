#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double roundDouble5(double num);

void main() {
	int n, mode;
	double* x;
	double* trans_x;
	double* y;
	double* trans_y;
	double sum_x = 0;
	double sum_y = 0;
	double sum_xy = 0;
	double sum_x_square = 0, sum_y_square = 0;
	double x_bar, y_bar;
	double a0, a1, origin_a0;

	printf("Power Regression(y = A*x^B form)\n\n");
	printf("Input number of samples : ");
	scanf("%d", &n);
	x = (double*)malloc(sizeof(double)*n);
	trans_x = (double*)malloc(sizeof(double)*n);
	y = (double*)malloc(sizeof(double)*n);
	trans_y = (double*)malloc(sizeof(double)*n);

     
	for (int i = 0; i < n; i++) {               // input values;
		printf("%d.Input x_value y_value : ",i+1);
		scanf("%lf %lf", &x[i], &y[i]);
	}

	sel:
	printf("\nchoose ln or log10 based(ln:1, log10:2): ");
	scanf("%d", &mode);
	if ((mode != 1) && (mode != 2))
		goto sel;
	switch (mode) {
	case 1:
		for (int i = 0; i < n; i++) {
			trans_x[i] = roundDouble5(log(x[i]));
			trans_y[i] = roundDouble5(log(y[i]));
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			trans_x[i] = roundDouble5(log10(x[i]));
			trans_y[i] = roundDouble5(log10(y[i]));
		}
		break;
	}

	for (int i = 0; i < n; i++) {
		sum_x += trans_x[i];
		sum_y += trans_y[i];
		sum_xy += roundDouble5(trans_x[i] * trans_y[i]);
		sum_x_square += roundDouble5(pow(trans_x[i], 2));
		sum_y_square += roundDouble5(pow(trans_y[i], 2));
	}
	x_bar = roundDouble5(sum_x / n);
	y_bar = roundDouble5(sum_y / n);

	a1 = roundDouble5((roundDouble5(n*sum_xy) - roundDouble5(sum_x*sum_y)) / (roundDouble5(n*sum_x_square) - roundDouble5(pow(sum_x, 2))));
	a0 = roundDouble5(y_bar) - roundDouble5(a1*x_bar);
	switch (mode) {
	case 1:
		origin_a0 = roundDouble5(exp(a0));
		printf("\nln(A) : %.5f, A : %.5f, B : %.5f\n\n", a0, origin_a0, a1);
		break;
	case 2:
		origin_a0 = roundDouble5(pow(10,a0));
		printf("\nlog10(A) : %.5f, A : %.5f, B : %.5f\n\n", a0, origin_a0, a1);
		break;
	}
	printf("Regression Model : y = %.5f * x^%.5f\n\n", origin_a0, a1);
}

double roundDouble5(double num) {
	return roundf(num * 100000) / 100000;
}