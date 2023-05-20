#include "tree.h"

extern Node* BstInsert(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}
	bool left = false;
	Node* copy = n;
	while (!TreeIsEmpty(copy)) {
		if (ElemCompare(e, &copy->value) <= 0) {
			left = true;
			if (copy->left == NULL) {
				break;
			}
			copy = copy->left;
		}
		else {
			left = false;
			if (copy->right == NULL) {
				break;
			}
			copy = copy->right;
		}
	}
	if (left) {
		copy->left = TreeCreateRoot(e, NULL, NULL);
	}
	else {
		copy->right = TreeCreateRoot(e, NULL, NULL);
	}
	return n;

}
extern Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}
	if (ElemCompare(e, &n->value) <= 0) {
		if (n->left == NULL) {
			n->left = TreeCreateRoot(e, NULL, NULL);
		}
		else {
			n->left = BstInsertRec(e, n->left);
		}
	}
	else {
		if (n->right == NULL) {
			n->right = TreeCreateRoot(e, NULL, NULL);
		}
		else {
			n->right = BstInsertRec(e, n->right);
		}
	}
	return n;
}