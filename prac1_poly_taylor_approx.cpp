#include <stdio.h>
#include <math.h>

#define MAX_TERM 4
#define TAYLOR_ORDER 3

typedef struct polynomial {
	int degree;
	double coef;
} polynomial;

polynomial poly[MAX_TERM];

void diffrential(polynomial* poly, int th);
int facto(int n);

void main() {
	poly[0].degree = 0;
	poly[0].coef = -88;
	poly[1].degree = 1;
	poly[1].coef = 7;
	poly[2].degree = 2;
	poly[2].coef = -6;
	poly[3].degree = 3;
	poly[3].coef = 25;
	double fxi1 = 0;
	double fxi = 0;
	int xi1 = 3;
	int xi = 1;
	double et = 0;
	double ea = 0;

	for (int i = 0; i <= TAYLOR_ORDER; i++) {
		diffrential(poly, i);
		for (int j = 0; j < MAX_TERM; j++) {
			fxi1 += (poly[j].coef * pow(xi, j) / facto(i) * pow(xi1 - xi, i));
		}
		et = fabs(((554.0 - fxi1) / 554.0)) * 100;
		ea = fabs(((fxi1 - fxi) / fxi1)) * 100;

		if (i == 0) {
			printf("n = %d  f(x) = %3.0f  Et = %6.6lf\n", i, fxi1, et);
		} else {
			printf("n = %d  f(x) = %3.0f  Et = %6.6lf  Ea = %.6lf\n", i, fxi1, et, ea);
		}

		fxi = fxi1;
	}

}

void diffrential(polynomial* poly, int th) {
	if (th <= 0) {

	} else {
		int i = 0;
		for (; i < MAX_TERM - th; i++) {
			poly[i].coef = poly[i + 1].coef * poly[i + 1].degree;
		}
		poly[i].degree = NULL;
		poly[i].coef = NULL;
	}
}

int facto(int n) {
	if (n == 0 || n == 1) {
		return 1;
	} else {
		return n * facto(n - 1);
	}
}
