#include "domino.h"
void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, Placing* tmp, Placing* res, int lvl, int len_tmp) {
	//If the tmp solution is better than the best found
	if (len_tmp > (int)*ret_size) {
		res = memcpy(res, tmp, sizeof(Placing) * t_size);
		*ret_size = (size_t)len_tmp;
	}
	//If we reach the end of the vector
	if (lvl == (int)t_size) {
		return;
	}
	//Past element not flipped
	if (len_tmp == 0 || ( t[lvl].val1 == t[tmp[len_tmp - 1].indice].val2 && !tmp[len_tmp - 1].flipped)) {
		tmp[len_tmp].flipped = false;
		tmp[len_tmp].indice = lvl;
		DominoRec(t, t_size, ret_size, tmp, res, lvl + 1, len_tmp + 1);
		tmp[len_tmp].indice = 0;
		tmp[len_tmp].flipped = false;
	}
	if (len_tmp == 0 || ( t[lvl].val2 == t[tmp[len_tmp - 1].indice].val2 && !tmp[len_tmp - 1].flipped)) {
		tmp[len_tmp].flipped = true;
		tmp[len_tmp].indice = lvl;
		DominoRec(t, t_size, ret_size, tmp, res, lvl + 1, len_tmp + 1);
		tmp[len_tmp].indice = 0;
		tmp[len_tmp].flipped = false;
	}
	//Flipped past element
	if (len_tmp > 0 && tmp[len_tmp - 1].flipped && t[lvl].val1 == t[tmp[len_tmp - 1].indice].val1) {
		tmp[len_tmp].flipped = false;
		tmp[len_tmp].indice = lvl;
		DominoRec(t, t_size, ret_size, tmp, res, lvl + 1, len_tmp + 1);
		tmp[len_tmp].indice = 0;
		tmp[len_tmp].flipped = false;
	}
	if (len_tmp > 0 && tmp[len_tmp - 1].flipped && t[lvl].val2 == t[tmp[len_tmp - 1].indice].val1) {
		tmp[len_tmp].flipped = true;
		tmp[len_tmp].indice = lvl;
		DominoRec(t, t_size, ret_size, tmp, res, lvl + 1, len_tmp + 1);
		tmp[len_tmp].indice = 0;
		tmp[len_tmp].flipped = false;
	}
	DominoRec(t, t_size, ret_size, tmp, res, lvl + 1, len_tmp);
}
Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {
	*ret_size = 0;
	if (t == NULL) {
		return NULL;
	}
	Placing* tmp = calloc(sizeof(Placing), t_size);
	Placing* res = calloc(sizeof(Placing), t_size);
	DominoRec(t, t_size, ret_size, tmp, res, 0, 0);
	free(tmp);
	return res;
}