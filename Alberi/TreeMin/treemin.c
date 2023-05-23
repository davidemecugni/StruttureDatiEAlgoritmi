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
const ElemType* FindMinRec(const Node* tree, int lvl, int *max_min, int* best_min) {
	if (tree == NULL) {
		return NULL;
	}
	if (TreeIsLeaf(tree)) {
		if (tree->value < *best_min) {
			*best_min = tree->value;
			return &tree->value;
		}
		return NULL;
	}
	const ElemType* min_left = NULL;
	if (tree->left != NULL) {
		min_left = FindMinRec(tree->left, lvl + 1, max_min, best_min);
	}
	const ElemType* min_right = NULL;
	if (tree->right != NULL) {
		min_right = FindMinRec(tree->right, lvl + 1, max_min, best_min);
	}
	if (min_left == NULL || min_right == NULL) {
		if (min_left == NULL && min_right == NULL) {
			return NULL;
		}
		if ((min_right == NULL) && (ElemCompare(&tree->value, min_left) >= 0)) {
			if (*min_left < *best_min) {
				*best_min = *min_left;
				return  min_left;
			}
			else {
				return NULL;
			}
			
		}
		else {
			if (tree->value < *best_min) {
				*best_min = tree->value;
				return  &tree->value;
			} 
			else {
				return NULL;
			}
		}
		if (min_left == NULL && (ElemCompare(&tree->value, min_right) >= 0)) {
			if (*min_right < *best_min) {
				*best_min = *min_right;
				return  min_right;
			}
			else {
				return NULL;
			}
		}
		else {
			if (tree->value < *best_min) {
				*best_min = tree->value;
				return  &tree->value;
			}
			else {
				return NULL;
			}
		}
	}
	if ((ElemCompare(&tree->value, min_left) < 0) && (ElemCompare(&tree->value, min_right) < 0)) {
		if (tree->value < *best_min) {
			*best_min = tree->value;
			return  &tree->value;
		}
		else {
			return NULL;
		}
	}
	if (ElemCompare(min_left, min_right) < 0) {
		if (*min_left < *best_min) {
			*best_min = *min_left;
			return  min_left;
		}
		else {
			return NULL;
		}
	}
	if (*min_right < *best_min) {
		*best_min = *min_right;
		return  min_right;
	}
	return NULL;
}
const ElemType* TreeMin(const Node* n) {
	if (n == NULL) {
		return NULL;
	}
	int max_min_index = 0;
	int best_min = n->value;
	return FindMinRec(n, 0 ,&max_min_index, &best_min);
}