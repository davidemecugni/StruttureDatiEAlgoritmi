#include "tree.h"

Node* CopyTree(const Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
	n->left = CopyTree(TreeLeft(t));
	n->right = CopyTree(TreeRight(t));
	return n;
}
extern Node* MergeTree(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return NULL;
	}
	else if (TreeIsEmpty(t1)) {
		return CopyTree(t2);
	}
	else if (TreeIsEmpty(t2)) {
		return CopyTree(t1);
	}
	ElemType sum = *(TreeGetRootValue(t1)) + *(TreeGetRootValue(t2));
	return TreeCreateRoot(&sum, MergeTree(TreeLeft(t1), TreeLeft(t2)), MergeTree(TreeRight(t1), TreeRight(t2)));
}