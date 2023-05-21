//Time 9m 15s
#include "tree.h"
bool TreeIsMirrorRec(Node* left, Node* right) {
	//If one is empty
	if (TreeIsEmpty(left) || TreeIsEmpty(right)) {
		//Both must be empty(leaf)
		return TreeIsEmpty(left) && TreeIsEmpty(right);
	}
	//If it's not leaf the values must be the same
	if (ElemCompare(&left->value, &right->value) != 0) {
		return false;
	}
	//Check is the subtrees are mirrored
	return TreeIsMirrorRec(left->left, right->right) && TreeIsMirrorRec(left->right,right->left);
}
bool TreeIsMirror(Node* t) {
	//If the tree is empty or is a leaf return true
	//As per assignment
	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return true;
	}
	return TreeIsMirrorRec(t->left, t->right);
}