//Time 19m
#include "tree.h"
bool TreeIsMirrorRec(Node* left, Node* right) {
	if (TreeIsEmpty(left) || TreeIsEmpty(right)) {
		return (TreeIsEmpty(left) && TreeIsEmpty(right));
	}
	if (TreeIsLeaf(left) || TreeIsLeaf(right)) {
		bool ll = TreeIsLeaf(left);
		bool lr = TreeIsLeaf(right);
		bool both_leaves = ( ll && lr);
		int res = ElemCompare(&left->value, &right->value);
		return  both_leaves && ( res == 0);
	}
	bool same = (ElemCompare(&left->value, &right->value) == 0);
	return same && (TreeIsMirrorRec(left->right, right->left) && TreeIsMirrorRec(left->left, right->right));
}
bool TreeIsMirror(const Node* t) {
	if (TreeIsEmpty(t)) {
		return true;
	}
	return TreeIsMirrorRec(t->left, t->right);
}