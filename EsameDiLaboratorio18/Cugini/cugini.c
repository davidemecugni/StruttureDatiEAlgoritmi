//Time 26min 08s
#include "tree.h"

const Node* FindValue(const Node* t, int n, const Node* father, int depth, int* depth_res) {
	//If the element is no found
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	//If we find the element, we set the depth and return the father
	if (t->value == n) {
		*depth_res = depth;
		return father;
	}
	father = t;
	const Node* left = FindValue(t->left, n, father, depth + 1, depth_res);
	const Node* right = FindValue(t->right, n, father, depth + 1, depth_res);
	//If the element is found on the left
	if (left != NULL) {
		return left;
	}
	//If the element is found on the right
	else if (right != NULL) {
		return right;
	}
	return NULL;
}
bool Cugini(const Node* t, int a, int b) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	int depth_a = -1;
	int depth_b = -1;
	const Node* father_a = NULL;
	//Sets the depth and the father for a
	father_a = FindValue(t, a, father_a, 0, &depth_a);
	const Node* father_b = NULL;
	//Sets the depth and the father for b
	father_b = FindValue(t, b, father_b, 0, &depth_b);
	if (depth_a == -1 || depth_b == -1) {
		return false;
	}
	//Is a and b father the same
	bool same_father = (father_a == father_b);
	//Is a and b at the same depth
	bool same_depth = (depth_a == depth_b);
	return  same_depth && !same_father;

}