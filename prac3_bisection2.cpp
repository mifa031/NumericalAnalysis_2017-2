#include <stdio.h>
#include <math.h>

const double eps_abs = 0.001;
const double eps_step = 0.001;
const int N = 100;

double a = 3;
double b = 4;
double c = 0;
int n = 0;

double func(double);
void main() {

	printf("%6s %6s %11s %8s %6s %11s %9s %6s\n", "a", "b", "f(a)", "f(b)", "c", "f(c)", "update", "b-a");
	while (fabs(b - a) >= eps_step && (fabs(func(a)) >= eps_abs && fabs(func(b)) >= eps_abs) && n < N) {
		n++;
		printf("%-8.5lf %-8.5lf %-8.5lf %-10.5lf ", a, b, func(a), func(b));
		c = (a + b) / 2;
		printf("%-8.5lf %-10.5lf ", c, func(c));
		if (func(c) > 0) {
			printf("%-6s", "a=c ");
		}
		else {
			printf("%-6s", "b=c ");
		}
		if (func(c) == 0)
			break;
		else if (func(a)*func(c)<0) {
			b = c;
		}
		else {
			a = c;
		}
		printf("%-8.5lf\n", fabs(b - a));
	}
}



double func(double x) {
	return exp(-x) * (3.2*sin(x) - 0.5*cos(x));
}
