//Time 6min
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Hailstone(int n, int* total) {
	if (n != 1) {
		printf("%d, ", n);
	}
	else {
		printf("%d", n);
	}
	if (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = 3 * n + 1;
		}
		*total += 1;
		Hailstone(n, total);
	}
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return -1;
	}
	int n, total;
	sscanf(argv[1], "%d", &n);
	if (n <= 0) {
		return 0;
	}
	Hailstone(n, &total);
	return total+1;
}