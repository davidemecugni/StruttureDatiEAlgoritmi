#include "tree.h"
bool IsIn(const Node* t, const Node* val) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	if (ElemCompare(&t->value, &val->value) && t == val) {
		return true;
	}
	return IsIn(TreeLeft(t), val) || IsIn(TreeRight(t), val);
}
const Node* LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, int *og_lvl) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	const Node* l = NULL;
	int og = *og_lvl;
	if (IsIn(TreeLeft(t), n1) && IsIn(TreeLeft(t), n2)) {
		l = LowestCommonAncestorRec(TreeLeft(t), n1, n2, og_lvl);
	}
	int l_lvl = *og_lvl;
	*og_lvl = og;
	const Node* r = NULL;
	if (IsIn(TreeRight(t), n1) && IsIn(TreeRight(t), n2)) {
		r = LowestCommonAncestorRec(TreeRight(t), n1, n2, og_lvl);
	}
	int r_lvl = *og_lvl;
	if (!TreeIsEmpty(l) && !TreeIsEmpty(r)) {
		if (l_lvl < r_lvl) {
			return r;
		}
		else {
			return l;
		}
	}
	if (!TreeIsEmpty(l)) {
		return l;
	}
	if (!TreeIsEmpty(r)) {
		return r;
	}
	if (IsIn(t, n1) && IsIn(t, n2)) {
		return t;
	}
	else {
		return TreeCreateEmpty();
	}
}
extern const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	int i = 0;
	return LowestCommonAncestorRec(t, n1, n2, &i);
}