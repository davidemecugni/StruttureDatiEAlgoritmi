#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool Felice(int n) {
	int somma = 0;
	while (n > 0) {
		somma += (n % 10) * (n % 10);
		n /= 10;
	}
	if (somma == 1) {
		return true;
	}
	if (somma == 0 || somma == 4) {
		return false;
	}
	return Felice(somma);
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int res, n;
	res = sscanf(argv[1], "%d", &n);
	if (res != 1 || n < 0) {
		return 1;
	}
	printf("%s", Felice(n) ? "Felice" : "Infelice");
	return 0;
}