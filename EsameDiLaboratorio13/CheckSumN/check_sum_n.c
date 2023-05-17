#include "tree.h"
//Time 23m 02s
//Simple is in function(checks whether the value n in the value in any node
//in the tree)
bool *IsIn(const Node* t, const int n, const ElemType* val) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	//If is the same
	ElemType tmp = n;
	if (ElemCompare(&t->value, &tmp) == 0) {
		//The value found must not be the same as the conjugate(a+a is not permitted
		//We are searching for a + b)
		return val != &t->value;
	}
	//Checks the subtrees
	return IsIn(t->left, n, val) || IsIn(t->right, n, val);
}
bool CheckSumNRec(const Node* t, const int n, const Node* full_tree) {
	//If the tree is empty, returns false
	if (TreeIsEmpty(t)) {
		return false;
	}
	//Checks whether there is a number in the full tree such as
	//t.value + value_in_the_subtrees = n
	bool complementary = IsIn(full_tree, n - t->value, &t->value);
	return complementary || CheckSumNRec(t->left, n, full_tree) || CheckSumNRec(t->right, n, full_tree);
}
bool CheckSumN(const Node* t, int n) {
	return CheckSumNRec(t, n, t);
}