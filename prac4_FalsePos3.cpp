#include <stdio.h>
#include <math.h>

double f(double);
double roundof(double, int);

const double eps_abs = 0.001;
const double eps_step = 0.001;
const int N = 100;

double a = 2;
double b = 3;
double c = 0;
int n = 0;
double old_pos = (f(a)<0)?a:b;

void main() {
	printf("%-2s %5s %7s %11s %8s %6s %10s\n", "N", "a", "b", "f(a)", "f(b)", "c", "f(c)");

	while ((roundof(old_pos,3) != roundof(c,3)) && n < N) {
		n++;
		printf("%-2d %-8.5lf %-8.5lf %-9.5lf %-8.5lf ", n, a, b, f(a), f(b));

		c = (a*f(b) - b*f(a)) / (f(b) - f(a));
		printf("%-8.5lf %-11.5lf\n", c, f(c));

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
	}
}

double f(double x) {
	return x * log10(x) - 1;
}

double roundof(double x, int digit)
{
	return (floor((x)* pow(float(10), digit) + 0.5f) / pow(float(10), digit));
}
