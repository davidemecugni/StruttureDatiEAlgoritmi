#include "gioielli.h"
Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	*ret_size = 0;
	size_t size = 0;
	Gioiello* sol = calloc(1, sizeof(Gioiello));
	Gioiello* gioielli_file = calloc(1, sizeof(Gioiello));
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		free(sol);
		free(gioielli_file);
		return NULL;
	}
	int codice;
	float peso, prezzo;
	while (!feof(f)) {
		int letti = fscanf(f, "%d%f%f\n", &codice, &peso, &prezzo);
		if (letti != 3) {
			break;
		}
		size += 1;
		gioielli_file[size - 1].codice = codice;
		gioielli_file[size - 1].peso = peso;
		gioielli_file[size - 1].prezzo = prezzo;
		gioielli_file = realloc(gioielli_file, sizeof(Gioiello) * (size + 1));
		}
	gioielli_file = realloc(gioielli_file, sizeof(Gioiello) * (size));
	size_t size_originale = size;
	while (budget > 0 && size_originale != *ret_size) {
		float lowest_prezzo_peso = FLT_MAX;
		int min_index;
		for (size_t i = 0; i < size; i++) {
			float rapporto = gioielli_file[i].prezzo / gioielli_file[i].peso;
			if ( rapporto < lowest_prezzo_peso && budget-gioielli_file[i].prezzo>=0) {
				lowest_prezzo_peso = rapporto;
				min_index = i;
			}
		}
		budget -= gioielli_file[min_index].prezzo;
		if (lowest_prezzo_peso == FLT_MAX) {
			break;
		}
		*ret_size += 1;
		memcpy(&sol[*ret_size - 1], &gioielli_file[min_index], sizeof(Gioiello));
		sol = realloc(sol, sizeof(Gioiello) * (*ret_size + 1));
		for (size_t i = min_index; i < size - 1; i++) {
			memcpy(&gioielli_file[i], &gioielli_file[i+1], sizeof(Gioiello));
		}
		size -= 1;
		gioielli_file = realloc(gioielli_file, sizeof(Gioiello) * size);
	}
	sol = realloc(sol, sizeof(Gioiello) * (*ret_size));
	if (*ret_size == 0) {
		free(sol);
		return NULL;
	}
	free(gioielli_file);
	fclose(f);
	return sol;
}
