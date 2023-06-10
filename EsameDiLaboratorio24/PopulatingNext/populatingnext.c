//Time 38min
#include "tree.h"
Node* LeftMost(Node* t) {
	while (!TreeIsEmpty(TreeLeft(t))) {
		t = TreeLeft(t);
	}
	return t;
}
Node* PopulatingNextRec(Node* t, Node* father, bool right) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	if (TreeIsLeaf(t)) {
		if (!right) {
			t->next = father;
			return NULL;
		}
		return t;
	}
	Node* l = PopulatingNextRec(TreeLeft(t), t, false);
	if (l != NULL) {
		l->next = t;
	}
	t->next = LeftMost(TreeRight(t));
	Node* r = PopulatingNextRec(TreeRight(t), t, true);
	if (TreeIsEmpty(TreeRight(t))) {
		return t;
	}
	return r;
}
void PopulatingNext(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	PopulatingNextRec(t, NULL, false);
}