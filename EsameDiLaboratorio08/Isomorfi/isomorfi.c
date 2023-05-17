#include "tree.h"

bool IsomorfiRec(const Node* t1, const Node* t2) {
	//If one is empty or the other, we check if both are empty than they are isomorfic
	if (TreeIsEmpty(t1) ||  TreeIsEmpty(t2)) {
		return TreeIsEmpty(t1) && TreeIsEmpty(t2);
	}
	//If the root value is the same
	if (ElemCompare(&t1->value, &t2->value) == 0) {
		//If we reach the leaf of one, we check if both are leaves
		if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
			return TreeIsLeaf(t1) && TreeIsLeaf(t2);
		}
		//Otherwise the check if they are simmetrically isomorfic or if the right branch
		//Of one in isomorfic to the left branch of the other
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