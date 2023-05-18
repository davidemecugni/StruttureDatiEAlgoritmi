//Time 10m 55s
#include "tree.h"
#include <stdlib.h>
//Finds the minimum element in the v array
int FindMinIndex(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return -1;
	}
	int min = 0;
	for (int i = 0; i < (int)v_size; i++) {
		if (ElemCompare(&v[i], &v[min]) < 0) {
			min = i;
		}
	}
	return min;
}
extern Node* CreateMinBinTreeRec(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return NULL;
	}
	int min_index = FindMinIndex(v, v_size);
	//Sets the size and copies the left and right sub arrays
	size_t left_size = min_index;
	size_t right_size = v_size - min_index - 1;
	ElemType* left = NULL;
	ElemType* right = NULL;
	if (left_size > 0) {
		left = calloc(left_size, sizeof(ElemType));
	}
	if (right_size > 0) {
		right = calloc(right_size, sizeof(ElemType));
	}
	for (int i = 0; i < (int)left_size; i++) {
		left[i] = v[i];
	}
	for (int i = 0; i < (int)right_size; i++) {
		right[i] = v[i + min_index + 1];
	}
	//Creates recursively a tree with the minimum value as the root, the
	//left sub tree as the elements to the left of the minimum in the array
	//and the right subtree as the elements to the right of the minimum in the array
	Node* res = TreeCreateRoot(&v[min_index], CreateMinBinTreeRec(left, left_size), CreateMinBinTreeRec(right, right_size));
	//Frees the tmp arrays
	free(left);
	free(right);
	return res;
}
extern Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	return CreateMinBinTreeRec(v, v_size);
}
