//Time 13min
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <math.h>
double Factorial(double n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * Factorial(n - 1);
}
double SinRec(double x, int i, int count, double partial_sum) {
	double numerator = 1;
	if (count % 2 == 1) {
		numerator = -1;
	}
	partial_sum += (numerator / Factorial(2 * (double)count + 1)) * pow(x, 2 * count + 1);
	if (i == count) {
		return partial_sum;
	}
	return SinRec(x, i, count + 1, partial_sum);
}
int main(int argc, char** argv) {
	if (argc != 3) {
		return 1;
	}
	int res, i;
	double x;
	res = sscanf(argv[1], "%lf", &x);
	if (res != 1) {
		return 1;
	}
	res = sscanf(argv[2], "%d", &i);
	if (res != 1 || i<0) {
		return 1;
	}
	printf("%lf", SinRec(x, i, 0,0));
	return 0;
}