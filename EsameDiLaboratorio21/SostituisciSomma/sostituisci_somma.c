//Time 4m
#include "tree.h"
int SostituisciSommaRec(Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	if (TreeIsLeaf(t)) {
		return t->value;
	}
	t->value += SostituisciSommaRec(TreeLeft(t)) + SostituisciSommaRec(TreeRight(t));
	return t->value;
}
extern void SostituisciSomma(Node* t) {
	if (t == NULL) {
		return;
	}
	SostituisciSommaRec(t);
}