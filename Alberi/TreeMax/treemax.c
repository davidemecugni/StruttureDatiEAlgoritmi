//Time >30min
#include "tree.h"
const ElemType* BstTreeMax(const Node* n) {
	if (n == NULL) {
		return NULL;
	}
	const Node* copy = n;
	while (copy->right != NULL) {
		copy = copy->right;
	}
	return &copy->value;
}
const ElemType* FindMaxRec(const Node* tree) {
	if (tree == NULL) {
		return NULL;
	}
	if (TreeIsLeaf(tree)) {
		return &tree->value;
	}
	const ElemType* max_left = NULL;
	if (tree->left != NULL) {
		max_left = FindMaxRec(tree->left);
	}
	const ElemType* max_right = NULL;
	if (tree->right != NULL) {
		max_right = FindMaxRec(tree->right);
	}
	if (max_left == NULL && max_right == NULL) {
		return &tree->value;
	}
	if (max_left == NULL || max_right == NULL) {
		if ((max_right == NULL) && (ElemCompare(&tree->value, max_left) >= 0)) {
			return &tree->value;
		}
		else {
			return max_left;
		}
		if (max_left == NULL && (ElemCompare(&tree->value, max_right) >= 0)) {
			return &tree->value;
		}
		else {
			return max_right;
		}
	}
	if ((ElemCompare(&tree->value, max_right) >= 0) && (ElemCompare(&tree->value, max_right) >= 0)) {
		return &tree->value;
	}
	if (ElemCompare(max_left, max_right) >= 0) {
		return max_left;
	}
	return max_right;
}
const ElemType* TreeMax(const Node* n) {
	if (n == NULL) {
		return NULL;
	}
	return FindMaxRec(n);
}