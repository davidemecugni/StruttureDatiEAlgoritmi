#include <stdio.h>
extern int TempoTrasporto(int n, const int* t, int p);
int main(void) {
	int t[] = { 3,2,4 };

	printf("Tempo: %d", TempoTrasporto(4,t,5));
}