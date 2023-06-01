//Time 45min
#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <ctype.h>
Node* PopulateTree(Node* tree, FILE* f) {
	bool leaf = false;
	char c;
	fscanf(f, " %c", &c);
	if (c == '.') {
		fscanf(f, " %c", &c);
		leaf = true;
	}
	
	ElemType val = c;
	tree = TreeCreateRoot(&val, NULL, NULL);
	if (leaf) {
		return tree;
	}
	if (!feof(f)) {
		tree->left = PopulateTree(tree->left, f);
		}
	if (!feof(f)) {
		tree->right = PopulateTree(tree->right, f);
	}
	return tree;
}
extern Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Node* tree = NULL;
	tree = PopulateTree(tree, f);
	fclose(f);
	return tree;
}