#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_TERM 3

typedef struct polynomial {
	double coef;
} polynomial;

polynomial poly[MAX_TERM][MAX_TERM];

/*double A[3][3] = { { -8,1,-2 },
{ -3,-1,7 },
{ 2,-6,-1 } };*/ // not diagonal dominance

double A[MAX_TERM][MAX_TERM] = { { -8,1,-2 },
{ 2,-6,-1 },
{ -3,-1,7 } }; // diagonal dominance

			   /*double B[MAX_TERM] = { -20,-34,-38 };*/ // not diagonal dominance  
double B[MAX_TERM] = { -20,-38,-34 }; // diagonal dominance

double ea[MAX_TERM] = { 100,100,100 };

double maxEa = 100;

double lambda = 1.2;

void set_x(polynomial poly[][MAX_TERM], double A[][MAX_TERM], double* B);
double x1(double x2, double x3, polynomial poly[][MAX_TERM]);
double x2(double x1, double x3, polynomial poly[][MAX_TERM]);
double x3(double x1, double x2, polynomial poly[][MAX_TERM]);
double rounding(double x, int digit);
double relax(double new_x, double old_x, double lambda);

void main() {
	if (fabs(A[0][0]) < fabs(A[0][1]) + fabs(A[0][2]) ||
		fabs(A[1][1]) < fabs(A[1][0]) + fabs(A[1][2]) ||
		fabs(A[2][2])< fabs(A[2][0]) + fabs(A[2][1])) {
		printf("not diagonal dominance\n");
	}
	else {
		set_x(poly, A, B);
		int iter = 0;
		double x[MAX_TERM] = { 0,0,0 };
		double new_x[MAX_TERM] = { 0,0,0 };
		double relax_x[MAX_TERM] = { 0,0,0 };

		printf("%s %10s %10s %16s %10s %14s\n", "Iteration", "unknown", "value", "relaxation", "ea", "max_ea");
		for (int i = 1; i <= 3; i++) {
			if (i == 2)
				printf("%5d %11s %14.5f %13.5f\n", iter, "x2", x[i - 1], 0);
			else
				printf("%s %15s%d %14.5f %13.5f\n", "", "x", i, x[i - 1], 0);
		}
		printf("\n\n");
		while (maxEa > 5) {
			for (int i = 0; i < MAX_TERM; i++) {
				new_x[0] = rounding(x1(relax_x[1], relax_x[2], poly), 5);
				relax_x[0] = rounding(relax(new_x[0], x[0], lambda),5);
				new_x[1] = rounding(x2(relax_x[0], relax_x[2], poly), 5);
				relax_x[1] = rounding(relax(new_x[1], x[1], lambda), 5);
				new_x[2] = rounding(x3(relax_x[0], relax_x[1], poly), 5);
				relax_x[2] = rounding(relax(new_x[2], x[2], lambda), 5);
				for (int j = 0; j < MAX_TERM; j++) {
					ea[j] = fabs(((relax_x[j] - x[j]) / relax_x[j]) * 100);
				}

				maxEa = ea[0];
				for (int j = 1; j < MAX_TERM; j++) {
					if (maxEa < ea[j])
						maxEa = ea[j];
				}

				for (int j = 1; j <= 3; j++) {
					if (j == 2)
						printf("%5d %11s %14.5f %13.5f %13.2f%% %12.2f%%\n", ++iter, "x2", new_x[j - 1], relax_x[j-1], ea[j - 1], maxEa);
					else
						printf("%s %15s%d %14.5f %13.5f %13.2f%%\n", "", "x", j, new_x[j - 1], relax_x[j-1], ea[j - 1]);
				}
				printf("\n\n");

				for (int j = 0; j < MAX_TERM; j++) {
					x[j] = relax_x[j];
				}
			}
		}
		printf("The approximated solution is\nx1 = %.5f\nx2 = %.5f\nx3 = %.5f\n", relax_x[0], relax_x[1], relax_x[2]);
	}
}

void set_x(polynomial poly[][MAX_TERM], double A[][MAX_TERM], double* B) {
	for (int i = 0; i < MAX_TERM; i++) {
		poly[i][0].coef = B[i] / A[i][i];
		int k = -1;
		for (int j = 1; j < MAX_TERM; j++) {
			while (k < MAX_TERM) {
				k++;
				if (i != k) {
					poly[i][j].coef = -A[i][k] / A[i][i];
					break;
				}
			}
		}
	}
}

double x1(double x2, double x3, polynomial poly[][MAX_TERM]) {
	return (poly[0][0].coef + (poly[0][1].coef * x2) + (poly[0][2].coef * x3));
}

double x2(double x1, double x3, polynomial poly[][MAX_TERM]) {
	return (poly[1][0].coef + (poly[1][1].coef * x1) + (poly[1][2].coef*x3));
}

double x3(double x1, double x2, polynomial poly[][MAX_TERM]) {
	return (poly[2][0].coef + (poly[2][1].coef * x1) + (poly[2][2].coef*x2));
}

double rounding(double x, int digit) {
	return (floor((x)* pow(float(10), digit) + 0.5f) / pow(float(10), digit));
}

double relax(double new_x, double old_x, double lambda) {
	return lambda*new_x + (1 - lambda)*old_x;
}