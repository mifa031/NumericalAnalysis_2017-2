#include<stdio.h>
#include<math.h>
double f(double x);
double f_prime(double x);
double newton_raphson(double xi);

void main() {
	double x0 = 3.8;
	double xi = x0;
	while (fabs(f(xi)) > 0.001) {
		xi = newton_raphson(xi);
	}
	printf("root of x : %f\n", xi);
}

double f(double x) {
	return 0.6*pow(x, 4) - 7.533333*pow(x, 3) + 29.9*pow(x, 2) - 37.966667*x + 5;
}

double f_prime(double x) {
	return 2.4*pow(x, 3) - 22.599999*pow(x, 2) + 59.8*x - 37.966667;
}

double newton_raphson(double xi) {
	return xi - (f(xi) / f_prime(xi));
}