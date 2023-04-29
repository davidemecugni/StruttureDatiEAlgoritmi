#include "vettore.h"

int VectorLowerBound(const Vector* v, const ElemType* e, size_t start, size_t stop) {
	//Test per controllare che non si sia giunti ad un singolo elemento
	while (start < stop) {
		size_t mid = (start + stop) / 2;
		int middle = v->data[mid];
		//Se l'elemento mid e' quello minore di quello cercato
		if (ElemCompare(&middle, e) == -1) {
			start = mid + 1;
		}
		//Se l'elemento mid e' quello minore di quello cercato
		else {
			stop = mid;
		}
	}
	//Se start = stop e' una posizione prima dell'elemento cercato
	if (start == stop && ElemCompare(&v->data[start], e) == -1) {
		start++;
	}

	// Ritorno l'indice di lower_bound
	if (start == stop) {
		return start;
	}
	// lower_bound non trovato		
	else {
		return -1;
	}

	
}
int VectorFind(const Vector* v, const ElemType* e) {
	if (v == NULL || e== NULL || v->data == NULL || v->size == 0 || v->data == 0) {
		return -1;
	}
	return VectorBinarySearch(v, e, 0, v->size - 1);
}