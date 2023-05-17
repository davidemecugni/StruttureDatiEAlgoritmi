#include "tree.h"
#include <float.h>
void NumberOfNodes(const Node* t, int* n) {
	if (TreeIsEmpty(t)) {
		return;
	}
	*n += 1;
	NumberOfNodes(t->left, n);
	NumberOfNodes(t->right, n);
}
void MedianoRec(const Node *t, int* target, int* lev, double* res, int* count, bool dispari){
	if (TreeIsEmpty(t)) {
		return;
	}
	MedianoRec(t->left, target, lev, res, count, dispari);
	if (*lev == (*target)) {
		if (dispari) {
			*res = (double)t->value;
			*lev += 1;
			return;
		}
		else{
			if (*res == 0.0 || *count < 2) {
				*res = *res + (double)t->value;
				*target += 1;
				*count += 1;
				return;
			}
		}
	}

	


	MedianoRec(t->right, target, lev, res, count, dispari);
	*lev += 1;
}
double Mediano(const Node* t) {
	if (TreeIsEmpty(t)) {
		return DBL_MAX;
	}
	int n = 0;
	NumberOfNodes(t, &n);
	bool dispari = n % 2 == 1;
	n /= 2;
	int lev = 0;
	double res = 0.0;
	int count = 0;
	MedianoRec(t, &n, &lev, &res, &count, dispari);
	if (dispari) {
		return res;
	}
	return res / 2.0;
}