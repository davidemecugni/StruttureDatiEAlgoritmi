//Time 1hr

#include "list.h"
extern Item* PariDispari(Item* i) {
	if (i == NULL) {
		return NULL;
	}
	Item* cpy = i;
	Item* pari = i;
	Item* dispari = i;
	Item* cpy_pari = pari;
	Item* cpy_dispari = dispari;
	bool primo_pari = true;
	bool primo_dispari = true;
	bool last_pari;
	while (!ListIsEmpty(cpy)) {
		if (cpy->value % 2 == 0) {
			if (primo_pari) {
				primo_pari = false;
				pari = cpy;
				cpy_pari = pari;
			}
			else {
				cpy_pari->next = cpy;
				cpy_pari = ListGetTail(cpy_pari);
			}
			last_pari = true;
		}
		else {
			if (primo_dispari) {
				primo_dispari = false;
				dispari = cpy;
				cpy_dispari = dispari;
			}
			else {
				cpy_dispari->next = cpy;
				cpy_dispari = ListGetTail(cpy_dispari);
			}
			last_pari = false;
		}
		cpy = ListGetTail(cpy);
	}
	if (last_pari && !primo_dispari) {
		cpy_dispari->next = NULL;
	}
	else if(!primo_pari){
		cpy_pari->next = NULL;
	}
	cpy_pari = pari;
	while (cpy_pari->next != NULL) {
		cpy_pari = ListGetTail(cpy_pari);
	}
	if (primo_dispari != true && primo_pari != true) {
		cpy_pari->next = dispari;
	}
	if (primo_pari != true) {
		return pari;
	}
	else {
		return dispari;
	}
}
