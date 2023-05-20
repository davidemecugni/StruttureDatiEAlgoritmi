//Time 20min
#include "tree.h"
bool IsDominant(const Node *tree ){
	if (TreeIsLeaf(tree)) {
		return false;
	}
	ElemType sum = 0;
	if ((tree->left != NULL) && (tree->right != NULL)) {
		sum += tree->left->value + tree->right->value;
	}
	else if (tree->left != NULL) {
		sum += tree->left->value;
	}
	else {
		sum += tree->right->value;
	}
	return ElemCompare(&tree->value, &sum) > 0;

}
void CountDominantRec(const Node* t, int *sum) {
	*sum += IsDominant(t);
	if (t->left != NULL) {
		CountDominantRec(t->left, sum);
	}
	if (t->right != NULL) {
		CountDominantRec(t->right, sum);
	}
	return;
}
extern int CountDominant(const Node* t) {
	int sum = 0;
	if (!TreeIsEmpty(t)) {
		CountDominantRec(t, &sum);
	}
	return sum;
}