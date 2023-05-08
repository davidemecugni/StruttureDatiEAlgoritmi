//Time 10min 00s
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void RecBin(int n) {
	if (n == 0) {
		return;
	}
	RecBin(n / 2);
	if (n % 2 == 1) {
		printf("1");
	}
	else {
		printf("0");
	}
}
int main(int argv, char* argc[]) {
	if (argv != 2) {
		return 1;
	}
	int n;
	int res = sscanf(argc[1], "%d", &n);
	if (res != 1 || n < 0) {
		return 1;
	}
	if (n == 0) {
		printf("0");
		return 0;
	}
	RecBin(n);
	return 0;

}