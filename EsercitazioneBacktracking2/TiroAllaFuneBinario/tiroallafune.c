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
void TiroAllaFuneRec(int* dati, size_t n, size_t i, size_t dim_a, int somma_a, int somma_b, bool* set, bool* best_set, size_t* min_diff) {
	if (i == dim_a) {
		size_t diff = (size_t)abs(somma_a - somma_b);
		if (diff < *min_diff) {
			*min_diff = diff;
			memcpy(best_set, set, sizeof(bool) * n);
		}
	}
	if (i > dim_a) {
		return;
	}
	for (size_t j = i; (size_t)j < n; j++) {
		if (!set[j]) {
			set[j] = true;
			TiroAllaFuneRec(dati, n, i + 1, dim_a, somma_a + dati[j], somma_b - dati[j], set, best_set, min_diff);
			set[j] = false;
		}

	}

}
void TiroAllaFune(int* dati, size_t n) {
	size_t dim_a = n / 2;
	size_t min_diff = SIZEMAX;
	bool* set = calloc(n, sizeof(bool));
	bool* best_set = calloc(n, sizeof(bool));
	int totale = 0; //Somma dati in I
	for (size_t i = 0; i < n; i++) {
		totale += dati[i];
	}
	TiroAllaFuneRec(dati, n, 0, dim_a, 0, totale, set, best_set,  &min_diff);
	if (min_diff == SIZEMAX) {
		printf("{ }, { }");
		return -1;
	}
	printf("{ ");
	for (size_t i = 0, a = 0; i < n; i++) {
		if (a < dim_a- 1 && best_set[i]) {
			printf("%d, ", dati[i]);
			++a;
		}
		else if(a==dim_a-1 && best_set[i]){
			printf("%d }", dati[i]);
			printf(", ");
			printf("{ ");
			break;
		}	
	}
	for (size_t i = 0, b = 0; i < n; i++) {
		if (b < n - dim_a - 1 && !best_set[i]) {
			printf("%d, ", dati[i]);
			b++;
		}
		else if (b == n- dim_a - 1 && !best_set[i]) {
			printf("%d }", dati[i]);
			break;
		}
	}
	free(set);
	free(best_set);
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
		dati[i] = atoi(argv[i + 1]);
	}
	TiroAllaFune(dati, (size_t)(argc - 1));

	return 0;
}