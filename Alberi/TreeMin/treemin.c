//Time >30min
#include "tree.h"
const ElemType* BstTreeMin(const Node* n) {
	if (n == NULL) {
		return NULL;
	}
	const Node* copy = n;
	while (copy->left != NULL) {
		copy = copy->left;
	}
	return &copy->value;
}
const ElemType* FindMinRec(const Node* tree) {
	if (tree == NULL) {
		return NULL;
	}
	if (TreeIsLeaf(tree)) {
		return &tree->value;
	}
	const ElemType* min_left = NULL;
	if (tree->left != NULL) {
		min_left = FindMinRec(tree->left);
	}
	const ElemType* min_right = NULL;
	if (tree->right != NULL) {
		min_right = FindMinRec(tree->right);
	}
	if (min_left == NULL || min_right == NULL) {
		if ((min_right == NULL) && (ElemCompare(&tree->value, min_left) >= 0)) {
			return  min_left;
		}
		else {
			return &tree->value;
		}
		if (min_left == NULL && (ElemCompare(&tree->value, min_right) >= 0)) {
			return min_right;
		}
		else {
			return &tree->value;
		}
	}
	if ((ElemCompare(&tree->value, min_left) < 0) && (ElemCompare(&tree->value, min_right) < 0)) {
		return &tree->value;
	}
	if (ElemCompare(min_left, min_right) < 0) {
		return min_left;
	}
	return min_right;
}
const ElemType* TreeMin(const Node* n) {
	if (n == NULL) {
		return NULL;
	}
	return FindMinRec(n);
}