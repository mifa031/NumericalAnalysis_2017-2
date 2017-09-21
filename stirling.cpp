#include <stdio.h>
#include <math.h>

const double pi = 3.14159265358979;
const double e = 2.71828182845905;

double stirling_approx(int);
int facto(int);
double abs_error(double true_val, double approx_val);
double relative_error(double true_val, double approx_val);

void main() {
	printf("%2s %8s %21s %16s %16s\n","n", "n!", "Stirling's approx","Absolute err","Relative err");
	for (int i = 1; i <= 10; i++) {
		printf("%2d %8d %21.6lf %15.6lf %15.6lf \n", 
			i, facto(i), stirling_approx(i),
			abs_error(facto(i), stirling_approx(i)),
			relative_error(facto(i), stirling_approx(i)));
	}
}

double stirling_approx(int n) {
	double result;
	result = sqrt(2 * pi * n) * pow(n/e,n);
	return result;
}


int facto(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * facto(n - 1);
	}
}

double abs_error(double true_val, double approx_val) {
	return true_val - approx_val;
}

double relative_error(double true_val, double approx_val) {
	return (true_val - approx_val) / true_val;
}