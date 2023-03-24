#include <stdint.h>
#if !defined SIZEMAX
#define SIZEMAX 65535
#endif
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
int SumArray(int* dati, int* set, size_t dim) {
	int res = 0;
	for (size_t i = 0; i < dim; i++) {
		res += dati[set[i]];
	}
	return res;
}
bool IsIn(int* dati, size_t len, int n) {
	for (size_t i = 0; i < len; i++) {
		if (n == dati[i]) {
			return true;
		}
	}
	return false;
}
int SumNotInArray(int* dati, int* set, size_t dim_dati, size_t dim_set) {
	int res = 0;
	for (size_t i = 0; i < dim_dati; i++) {
		if (!IsIn(set, dim_set, dati[i])) {
			res+=dati[i];
		}
	}
	return res;
}
void TiroAllaFuneRec(int* dati, size_t n, size_t i, size_t dim_a, size_t dim_b, int somma_a, int somma_b, int *set_a, int* best_set_a,  size_t *min_diff) {
	if (i == dim_a) {
		size_t diff = abs(somma_a - somma_b);
		if (diff < *min_diff) {
			*min_diff = diff;
			memcpy(best_set_a, set_a, sizeof(int) * dim_a);
		}
	}
	if (i > dim_a) {
		return;
	}
	for (int j = 0; (size_t)j < n; j++) {
		if (!IsIn(set_a, dim_a, j)) {
			set_a[i] = j;
			TiroAllaFuneRec(dati, n, i + 1, dim_a, dim_b, somma_a + dati[j], somma_b - dati[j], set_a, best_set_a, min_diff);
			set_a[i] = -1;
		}
		
	}
	
}
void TiroAllaFune(int* dati, size_t n) {
	size_t dim_a = n / 2, dim_b = n - n / 2;
	size_t min_diff = SIZEMAX;
	int* set_a = calloc(dim_a, sizeof(int));
	int* best_set_a = calloc(dim_a, sizeof(int));
	int totale = 0; //Somma dati in I
	for (size_t i = 0; i < n; i++) {
		totale += dati[i];
	}
	for (size_t i = 0; i < dim_a; i++) {
		set_a[i] = -1;
	}
	TiroAllaFuneRec(dati, n, 0, dim_a, dim_b, 0, totale,set_a, best_set_a, &min_diff);
	printf("{ ");
	for (size_t i= 0; i < dim_a -1; i++) {
		printf("%d, ", dati[best_set_a[i]]);
	}
	printf("%d }", dati[best_set_a[dim_a - 1]]);
	printf(", ");
	printf("{ ");
	for (size_t i = 0, in_b=0; i < n; i++) {
		if (!IsIn(best_set_a, dim_a, (int)i)) {
			in_b++;
			if (in_b == dim_b) {
				printf("%d }", dati[i]);
			}
			else {
				printf("%d, ", dati[i]);
			}
		}
		
	}
	return;
}
int main(int argc, char** argv) {
	if (argc == 1) {
		return -1;
	}
	int* dati = calloc((size_t)(argc - 1), sizeof(int));
	for (int i = 0; i < argc - 1; i++) {
		dati[i] = -1;
	}
	for (int i = 0; i < argc - 1; i++) {
		dati[i] = atoi(argv[i+1]);
	}
	TiroAllaFune(dati, (size_t)(argc - 1));
	
	return 0;
}