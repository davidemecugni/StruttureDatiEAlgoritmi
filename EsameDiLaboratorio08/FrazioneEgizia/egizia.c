#include <stdio.h>
//22m 36s
/*
void Swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}
int MaxCommonDivider(int a, int b) {
	if (a < b) {
		Swap(&a, &b);
	}
	if (a - b < 0) {
		return 1;
	}
	if (a % b == 0) {
		return b;
	}
	MaxCommonDivider(a - b, a);
}
int MinCommonMultiplier(int a, int b) {
	if (a % b == 0) {
		return a;
	}
	if (b % a == 0) {
		return b;
	}
	return a * b / MaxCommonDivider(a, b);

}
*/
void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}
	//  1/den
	int den = d / n + (d%n!=0);
	printf("1/%d", den);

	if (d % n != 0) {
		printf(" + ");
		FrazioneEgizia(n * den - d, d * den);
	}
}