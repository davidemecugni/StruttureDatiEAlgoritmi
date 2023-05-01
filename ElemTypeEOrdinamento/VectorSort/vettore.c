#include "vettore.h"
void QuickSort(Vector* v, int start, int stop) {
	//Controllo per impedire la chiamata continua anche quando dim=1
	if (start < stop) {
		int sinistra = start, destra = stop;
		//Il pivot viene scelto come media dei due vettori(si presume che sia vicina alla mediana)
		int pivot = (v->data[start] + v->data[stop]) / 2 ;
		do {
			while (v->data[sinistra] < pivot) sinistra++;
			while (v->data[destra] > pivot) destra--;
			if (sinistra <= destra) {
				ElemSwap(&v->data[sinistra], &v->data[destra]);
				sinistra++;
				destra--;
			}
		} while (sinistra <= destra);
		QuickSort(v, start, destra);
		QuickSort(v, sinistra, stop);
	}


}
void VectorSort(Vector* v) {
	if (v == NULL) {
		return;
	}
	QuickSort(v, 0, v->size - 1);
}