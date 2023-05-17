//Time 7m 22s
#include "tree.h"
bool EquivalentiRec(const Node* t1, const Node* t2) {
	//We check if both are empty
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return TreeIsEmpty(t1) && TreeIsEmpty(t2);
	}
	//If one is leaf
	if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
		//If both are leaves and one is multiple of the other
		if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
			return (t2->value % t1->value == 0) || (t1->value % t2->value == 0);
		}
		else {
			return false;
		}
	}
	//If it's not leaf, the value must be the same
	if (ElemCompare(&t1->value, &t2->value) == 0) {
		//We check if the sub-trees are equivalent
		return EquivalentiRec(t1->left, t2->left) && EquivalentiRec(t1->right, t2->right);
	}
	else {
		return false;
	}
}
extern bool Equivalenti(const Node* t1, const Node* t2) {
	return EquivalentiRec(t1, t2);
}