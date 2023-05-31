//Time 18min
#include "tree.h"
void InvertRec(Node* t) {
	Node* l = TreeLeft(t);
	Node* r = TreeRight(t);
	t->left = r;
	t->right = l;
	if (!TreeIsEmpty(t->left)) {
		InvertRec(t->left);
	}
	if (!TreeIsEmpty(t->right)) {
		InvertRec(t->right);
	}
}
Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) {
		return TreeCreateEmpty();
	}
	InvertRec(t);
	return t;
}