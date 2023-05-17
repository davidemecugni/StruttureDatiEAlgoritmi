//Time 31m 50s
#include "tree.h"
//Checks whether a level exists in a tree
bool LevelExists(const Node* t, int level, int* current) {
	//If we passed a leaf before we reached any node, return false
	if (TreeIsEmpty(t)) {
		return false;
	}
	//If we reached an element
	if (level == *current) {
		return true;
	}
	bool tmp = false;
	tmp = LevelExists(t->left, level + 1, current);
	//If any sub-tree has the desired level(depth)
	return tmp || LevelExists(t->right, level + 1, current);
}
int Height(const Node* t) {
	int max_level = 0;
	//While a level exists, the max_level is increased
	for (max_level = 0; LevelExists(t, 0, &max_level); max_level++);
	return max_level;
}
//Simple max of three numbers
int Max(int a, int b, int c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b > c) {
			return b;
		}
		else {
			return c;
		}
	}
}


int DiameterRec(const Node* t) {
	//If the tree is empty it has 0 diameter
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int diam_left = DiameterRec(t->left);
	int diam_right = DiameterRec(t->right);
	//It returns the max of the diameters of the subtrees or
	//The height of the left one + the height of the right one
	//Plus the current node as a conjunction between the deepest path
	//On the left and the deepest of the right
	return Max(diam_left, diam_right, Height(t->left) + Height(t->right) + 1);
}
extern int Diameter(const Node* t) {
	return DiameterRec(t);
}