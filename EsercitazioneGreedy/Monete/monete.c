#include <stdlib.h>
int* Monete(const int* tagli, size_t tagli_size, int budget) {
	if (budget <= 0) {
		return NULL;
	}
	int *tagli_sol = calloc(tagli_size, sizeof(int));
	int indice_taglio = 0;
	while (budget > 0) {
		if (budget - tagli[indice_taglio]>=0) {
			budget -= tagli[indice_taglio];

			tagli_sol[indice_taglio] += 1;
		}
		else {
			++indice_taglio;
		}
	}
	return tagli_sol;
}