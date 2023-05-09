//Time 10m 45s
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
bool IsPrimeRec(int n, int div) {
	//Base cases
	if (n == 0 || n == 1) {
		return false;
	}
	//If there's a divisor, which isn't the number itself
	//(the latter is only for small numbers)
	if (n % div == 0 && n != div) {
		return false;
	}
	//If we already passed the sqrt of n, we
	//Can be sure it is prime
	if (div * div > n) {
		return true;
	}
	//New divisor
	return IsPrimeRec(n, div + 1);
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n;
	int res = sscanf(argv[1], "%d", &n);
	if (n < 0 || res != 1) {
		return 1;
	}
	if (IsPrimeRec(n, 2)) {
		printf("true");
	}
	else {
		printf("false");
	}
	return 0;
}