#include "torrecartoni.h"
bool IsIn(int* torre, size_t n, size_t indice) {
	for (size_t i = 0; i < n; i++) {
		if ((size_t)torre[i] == indice) {
			return true;
		}
	}
	return false;
}
void TorreCartoniRec(const Cartone* c, size_t n, size_t i, int* current_torre, size_t somma_pesi,int somma_altezza, int *max_altezza, int* best_torre, size_t* nr_pacchi) {
	if (somma_altezza > *max_altezza) {
		memcpy(best_torre, current_torre, n * sizeof(int));
		*nr_pacchi = i;
		*max_altezza = somma_altezza;
	}
	if (i == n) {
		return;
	}
	for (size_t j = 0; j < n; j++) {
		if (!IsIn(current_torre, n, j) && somma_pesi <= c[j].l) {
			current_torre[i] = j;
			TorreCartoniRec(c, n, i + 1, current_torre, somma_pesi + c[j].p,somma_altezza+ c[j].a, max_altezza, best_torre, nr_pacchi);
		}
	}
}
void TorreCartoni(const Cartone* c, size_t n) {
	int max_altezza = 0;
	size_t nr_pacchi = 0;
	int *current_torre = calloc(n, sizeof(int));
	for (size_t i = 0; i < n; i++) {
		current_torre[i] = -1;
	}
	int *best_torre = calloc(n, sizeof(int));
	TorreCartoniRec(c, n, 0, current_torre, 0,0, &max_altezza, best_torre, &nr_pacchi);
	free(current_torre);
	best_torre = realloc(best_torre, sizeof(int) * nr_pacchi);
	for (size_t i = 0; i < nr_pacchi; i++) {
		printf("%d\n", best_torre[i]);
	}
	printf("Altezza: %d cm", max_altezza);
	free(best_torre);
	return;
}