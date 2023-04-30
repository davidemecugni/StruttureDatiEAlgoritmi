//Time 50m
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Same as (value in v) in Python
bool IsIn(int* v, size_t dim, int value) {
	for (size_t i = 0; i < dim; i++) {
		if (value == v[i]) {
			return true;
		}
	}
	return false;
}
//Recursive backtrack function
void CacciatorePredaRec(const char* v, size_t v_size, int u, int liv, int *ris, int nr_cacciatori, int exp_pos, int *ris_def, int *best_cacciatori_disoccupati) {
	//If the current number of free hunters in lower(better) than the best yet found
	if (nr_cacciatori<*best_cacciatori_disoccupati) {
		memcpy(ris_def, ris, v_size * sizeof(int));
		*best_cacciatori_disoccupati = nr_cacciatori;
		//If all hunters have found a pray
		if (nr_cacciatori == 0) {
			return;
		}
	}
	for (int pos = exp_pos; pos < (int)v_size; pos++) {
		//From a hunter we try to find a free pray
		if (v[pos] == 'c' || v[pos] == 'C') {
			//After the hunter
			for (int from_c = pos+1; from_c <= pos + u  && pos < v_size; from_c++) {
				if ((v[from_c] == 'p' || v[from_c] == 'P') && !IsIn(ris, v_size, from_c )) {
					ris[from_c] = -2;
					ris[pos] = from_c;
					CacciatorePredaRec(v, v_size, u, liv+1, ris, nr_cacciatori-1, pos+1, ris_def, best_cacciatori_disoccupati);
					//Reset
					ris[from_c] = -1;
					ris[pos] = -1;
				}
			}
			//Before the hunter
			for (int from_c = pos-1; from_c >= pos - u && pos >=0; from_c--) {
				if ((v[from_c] == 'p' || v[from_c] == 'P') && !IsIn(ris, v_size, from_c)) {
					ris[from_c] = -2;
					ris[pos] = from_c;
					CacciatorePredaRec(v, v_size, u, liv + 1, ris, nr_cacciatori - 1, pos + 1, ris_def, best_cacciatori_disoccupati);
					//Reset
					ris[from_c] = -1;
					ris[pos] = -1;
				}
			}
		}
	}
}
int* CacciatorePreda(const char* v, size_t v_size, int u) {
	if (v == NULL) {
		return NULL;
	}
	//Ris is used for temporary solutions, ris_def for the best one yet found
	int* ris = calloc(v_size, sizeof(int));
	int* ris_def = calloc(v_size, sizeof(int));
	int nr_cacciatori = 0;
	//Initialises the vector as if no hunter found any pray
	for (int i = 0; i < (int)v_size; i++) {
		if (v[i] == 'C' || v[i] == 'c') {
			nr_cacciatori++;
		}
		ris[i] = -1;
		ris_def[i] = -1;
	}
	//Best number of free hunters(this has to be minimized)
	int best = (int)v_size;
	//Recursive call
	CacciatorePredaRec(v, v_size, u, 0, ris, nr_cacciatori, 0, ris_def, &best);
	free(ris);
	return ris_def;
}

int main(void) {
	// {1, -2, -1, 4, -2, -1}
	char r[] = {'C',  'P',  'C',  'C',  'P',  'P'};
	int* res = CacciatorePreda(r, 6, 1); 
	return 0;
}
