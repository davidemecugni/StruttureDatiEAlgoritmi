#include "tree.h"

bool IsomorfiRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) ||  TreeIsEmpty(t2)) {
		return TreeIsEmpty(t1) && TreeIsEmpty(t2);
	}
	if (ElemCompare(&t1->value, &t2->value) == 0) {
		if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
			return TreeIsLeaf(t1) && TreeIsLeaf(t2);
		}
		return (IsomorfiRec(t1->left, t2->right) && IsomorfiRec(t1->right, t2->left)) ||
			(IsomorfiRec(t1->left, t2->left) && IsomorfiRec(t1->right, t2->right));
	}
	else {
		return false;
	}
}
extern bool Isomorfi(const Node* t1, const Node* t2) {
	return IsomorfiRec(t1, t2);
}