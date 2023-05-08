//Time: embarrassingly more than 2 hours
//Done 2 implementations wrong
#include "domino.h"
/*
//Conflicts with the builtin function in OLJ
void PrintDomino(const Tessera* t, const Placing *p, size_t n) {
	if (n == 0) {
		return;
	}
	for (size_t i = 0; i < n; i++) {
		if (!p[i].flipped) {
			printf("[ %1d %1d ] ", t[p[i].indice].val1, t[p[i].indice].val2);
		}
		else {
			printf("[ %1d %1d ] ", t[p[i].indice].val2, t[p[i].indice].val1);
		}
		
	}
	printf("\n");
}
*/
//Returns if the placing is well done(the rules are followed)
bool IsCorrect(const Tessera* t, const Placing* p, size_t n) {
	if (n == 0 ) {
		return true;
	}
	for (size_t i = 1; i < n; i++){
		//For every 2 tiles touching there are 4(2bit) possibilities, here tested
		if (!p[i].flipped) {
			if ((p[i - 1].flipped && t[p[i - 1].indice].val1 != t[p[i].indice].val1) || (!p[i - 1].flipped && t[p[i - 1].indice].val2 != t[p[i].indice].val1)) {
				return false;
			}
			
		}
		else {
			if ((p[i - 1].flipped && t[p[i - 1].indice].val1 != t[p[i].indice].val2) || (!p[i - 1].flipped && t[p[i - 1].indice].val2 != t[p[i].indice].val2)) {
				return false;
			}
		}
	}
	return true;
}
//Returns if an element is already in the placing array
bool IsIn(const Placing* p, int index, size_t t_size) {
	for (int i = 0; i < (int)t_size; i++) {
		if (index == (int)p[i].indice) {
			return true;
		}
	}
	return false;
}
//tmp is used for the temporary solution, res for the final one, lvl is just to avoid over selecting
//len_tmp is how many tiles has it found for the current solution
void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, Placing* tmp, Placing* res, int lvl, int len_tmp) {
	//If the current solution isn't well-built
	if (!IsCorrect(t, tmp, len_tmp)) {
		return;
	}
	//If the tmp solution is better than the best found
	if (len_tmp > (int)*ret_size) {
		res = memcpy(res, tmp, sizeof(Placing) * t_size);
		*ret_size = (size_t)len_tmp;
		
	}
	//If we reach the end of the vector
	if (lvl == (int)t_size) {
		return;
	}
	//We try to fit every element as a candidate
	for (int i = 0; i < (int)t_size; i++) {
		//But only if it isn't already present
		if (!IsIn(tmp, i, t_size)) {
			//Taking it not flipped
			tmp[len_tmp].flipped = false;
			tmp[len_tmp].indice = i;
			DominoRec(t, t_size, ret_size, tmp, res, lvl + 1, len_tmp + 1);
			//Taking it flipped
			tmp[len_tmp].flipped = true;
			tmp[len_tmp].indice = i;
			DominoRec(t, t_size, ret_size, tmp, res, lvl + 1, len_tmp + 1);
			//Just useless in this implementation
			tmp[len_tmp].indice = -1;
		}
	}
}
Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {
	*ret_size = 0;
	if (t == NULL) {
		return NULL;
	}
	Placing* tmp = calloc(sizeof(Placing), t_size);
	//Used not to conflict with the 0 case
	for (size_t i = 0; i < t_size; i++) {
		tmp[i].indice = 0xFF;
	}
	//Best solution
	Placing* res = calloc(sizeof(Placing), t_size);
	DominoRec(t, t_size, ret_size, tmp, res, 0, 0);
	//The temporary one has to be freed
	free(tmp);
	return res;
}