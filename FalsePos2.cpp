#include <stdio.h>
#include <math.h>

const double eps_abs = 0.001;
const double eps_step = 0.001;
const int N = 100;

double a = 3;
double b = 4;
double c = 0;
int n = 0;
double old_pos;

double f(double);

void main() {
	printf("%6s %6s %11s %8s %6s %10s %10s %11s\n", "a", "b", "f(a)", "f(b)", "c", "f(c)", "update", "step_size");


	while (fabs(b - a) >= eps_step && fabs(f(a)) >= eps_abs && fabs(f(b)) >= eps_abs && n < N) {
		n++;
		printf("%-8.5lf %-8.5lf %-9.5lf %-8.5lf ", a, b, f(a), f(b));

		c = (a*f(b) - b*f(a)) / (f(b) - f(a));
		printf("%-8.5lf %-11.5lf ", c, f(c));

		if (f(a) < 0) {
			printf("%-8s", "a=c ");
		}
		else {
			printf("%-8s", "b=c ");
		}

		if (f(c) == 0)
			break;
		else if (f(a)*f(c) < 0) {
			old_pos = b;
			b = c;
		}
		else {
			old_pos = a;
			a = c;
		}

		printf("%-9.5lf\n", fabs(old_pos - c));
	}
}

double f(double x) {
	return exp(-x) * (3.2*sin(x) - 0.5*cos(x));
}