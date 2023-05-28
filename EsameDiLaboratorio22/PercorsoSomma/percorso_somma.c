//Time 10m 47s
#include "tree.h"
bool PercorsoSommaRec(Node* t, const ElemType* target, ElemType sum) {
	if (TreeIsLeaf(t)) {
		if (ElemCompare(target, &sum) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	if (ElemCompare(target, &sum) < 0) {
		return false;
	}
	bool l = false, r = false;
	if (!TreeIsEmpty(TreeLeft(t))) {
		l = PercorsoSommaRec(TreeLeft(t), target, sum + TreeLeft(t)->value);

	}
	if (!TreeIsEmpty(TreeRight(t))) {
		r = PercorsoSommaRec(TreeRight(t), target, sum + TreeRight(t)->value);
	}
	return l || r;
}
bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	return PercorsoSommaRec(t, target, t->value);
}