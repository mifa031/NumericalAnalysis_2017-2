#include <stdio.h>
#include <math.h>


const double eps_step = 0.00001;
double eps_approx = 100;
int n = 0;
double x0 = 0;
double x1 = 2.2;
double x2;


double f(double x);
double secant(double x0, double x1);

void main() {
	printf("%3s %12s %10s %12s %12s %14s\n", "N", "Xn-1", "Xn", "Xn+1", "f(Xn+1)", "eps_approx");

	while (eps_approx > eps_step) {
		n++;
		x2 = secant(x0, x1);
		eps_approx = fabs((x2 - x1) / x2 * 100);
		printf("%3d %12.5lf %12.5lf %12.5lf %12.5lf %12.5lf\n", n, x0, x1, x2, f(x2), eps_approx);
		x0 = x1;
		x1 = x2;
	}
	printf("\nThe root of x = %.5lf\n\n", x2);
}

double f(double x) {
	return 3 * x + sin(x) - exp(x);
}
double secant(double x0, double x1) {
	return x1 - f(x1)*((x1 - x0) / (f(x1) - f(x0)));
}