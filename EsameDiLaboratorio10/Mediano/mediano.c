#include "tree.h"
#include <float.h>
void NumberOfNodes(const Node* t, int* n) {
	//If we passed a leaf we return
	if (TreeIsEmpty(t)) {
		return;
	}
	//Otherwise we add the current element
	*n += 1;
	//We count the left and right sub-tree
	NumberOfNodes(t->left, n);
	NumberOfNodes(t->right, n);
}
void MedianoRec(const Node *t, int* target, int* lev, double* res, int* count, bool dispari){
	//If we passed a leaf
	if (TreeIsEmpty(t)) {
		return;
	}
	//We esplore the remaining sub-tree
	MedianoRec(t->left, target, lev, res, count, dispari);
	MedianoRec(t->right, target, lev, res, count, dispari);
	//We add the current element to the count
	*lev += 1;
	//If we reached the target element(aka the one in the middle)
	if (*lev == (*target)) {
		//If the total is odd, we just set the result as the central element
		if (dispari) {
			*res = (double)t->value;
			//To avoid setting the next elements as the middle one
			*lev += 1;
			return;
		}
		else {
			//If it's the first one we found, or is the second one
			if (*count < 2) {
				//Total to be halved for the mean
				*res = *res + (double)t->value;
				//Such as to trigger the next one
				*target += 1;
				//So that we don't find more than two elements
				*count += 1;
				return;
			}
		}
	}
}
double Mediano(const Node* t) {
	if (TreeIsEmpty(t)) {
		return DBL_MAX;
	}
	int n = 0;
	NumberOfNodes(t, &n);
	//If the tree has odd elements, we just find the central one
	bool dispari = n % 2 == 1;
	//The target element is in the middle(or middle + 1 for the second even element)
	n /= 2;
	int lev = 0;
	double res = 0.0;
	int count = 0;
	//The recursive function
	MedianoRec(t, &n, &lev, &res, &count, dispari);
	//If the elements are odd, we just return the central one
	if (dispari) {
		return res;
	}
	//We must calculate the avg if the elements are even
	return res / 2.0;
}