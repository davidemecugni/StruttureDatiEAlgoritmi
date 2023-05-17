//Time 7m 22s
#include "tree.h"
bool EquivalentiRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return TreeIsEmpty(t1) && TreeIsEmpty(t2);
	}
	if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
		if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
			return (t2->value % t1->value == 0) || (t1->value % t2->value == 0);
		}
		else {
			return false;
		}
	}
	if (ElemCompare(&t1->value, &t2->value) == 0) {
		return EquivalentiRec(t1->left, t2->left) && EquivalentiRec(t1->right, t2->right);
	}
	else {
		return false;
	}
}
extern bool Equivalenti(const Node* t1, const Node* t2) {
	return EquivalentiRec(t1, t2);
}