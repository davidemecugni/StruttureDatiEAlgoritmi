//Time 24min 50s
#include "tree.h"
#include <stdlib.h>
//Simple find max function
int Max(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		return -1;
	}
	int max = 0;
	for (int i = 1; i < (int)v_size; i++) {
		if (ElemCompare(&v[max], &v[i]) < 0) {
			max = i;
		}
	}
	return max;
}
Node* CreateMaxBinTreeRec(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		return NULL;
	}
	int index_max = Max(v, v_size);
	//Finds the size for the left/right subtrees
	size_t left_size = index_max;
	size_t right_size = (int)v_size - index_max - 1;
	ElemType* v_left = NULL;
	ElemType* v_right = NULL;
	if (left_size != 0) {
		v_left = calloc(left_size, sizeof(ElemType));
	}
	if (right_size != 0) {
		v_right = calloc(right_size, sizeof(ElemType));
	}
	//Copies the values for the left, right one
	for (int i = 0; i < index_max; i++) {
		v_left[i] = v[i];
	}
	for (int i = 0; i < (int)v_size - index_max - 1; i++) {
		v_right[i] = v[i + index_max + 1];
	}
	//Recursive call, the root is the max, the left subtree is composed of elements on the left
	//of the max in the vector, the right subtree is composed of the elements to the right of the max in the vector
	Node* res =  TreeCreateRoot(&v[index_max], CreateMaxBinTreeRec(v_left, left_size), CreateMaxBinTreeRec(v_right, right_size));
	//Frees the sub arrays
	free(v_left);
	free(v_right);
	return res;
}
Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	//Simple controls
	if (v == NULL || v_size == 0) {
		return NULL;
	}
	return CreateMaxBinTreeRec(v, v_size);
}


