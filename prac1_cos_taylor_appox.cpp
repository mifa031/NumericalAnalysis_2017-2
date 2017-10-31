#include <stdio.h>
#include <math.h>

void main() {
	int i;
	int j = 1; // terms counter
	double pi = 3.1415926535;
	double x = 0.3*pi;
	double cosi;
	double cosn;
	int fact;
	double ea = 0;
	double es = 0.0000001;

	cosi = 1;
	fact = 1;
	cosn = cosi;
	printf("j = %d cos(x) = %0.10lf\n", j, cosn);
	while (1) {
		j = j + 1;
		i = 2 * j - 2;
		fact = fact * i * (i - 1);
		cosn = cosi + pow(-1, j + 1) * (pow(x, i) / fact);
		ea = fabs((cosn - cosi) / cosn);
		printf("j = %d cos(x) = %0.10lf ea = %0.1e\n", j, cosn, ea);
		if (ea < es)
			break;
		cosi = cosn;
	}
}
