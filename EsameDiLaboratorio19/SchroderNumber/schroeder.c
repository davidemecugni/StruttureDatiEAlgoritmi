//Time 7min
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Schroeder(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}
	int first_half = ((6 * n - 3) * Schroeder(n - 1)) / (n + 1);
	int second_half = (( n - 2 ) * Schroeder(n - 2)) / (n + 1);
	return first_half - second_half;
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n = -1;
	int res = sscanf(argv[1], "%d", &n);
	if (res == 0 || n < 0) {
		return 1;
	}
	printf("%d", Schroeder(n));
	return 0;
}