//Time 8m
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
double Concentrazione(int n, double cn) {

	if (n == 1) {
		return cn;
	}
	cn = 0.3 * cn + 0.2;
	return Concentrazione(n - 1, cn);
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n;
	int res = sscanf(argv[1], "%d", &n);
	if (res != 1 || n < 1) {
		return 1;
	}
	printf("%lf", Concentrazione(n, 0));
	return 0;
}