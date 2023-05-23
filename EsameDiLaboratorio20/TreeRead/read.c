//Time 45 min
#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <ctype.h>
Node* TreeCreateRec(FILE* f) {
	if (f == NULL) {
		return NULL;
	}
	ElemType c = '\n';
	int res = 0;
	while (!isalnum(c) && (c != '.') ){
		res = fscanf(f, "%c", &c);
		if (res == 0) {
			break;
		}
	}
	if (res == 0) {
		return NULL;
	}
	if (c == '.') {
		while (!isalnum(c)) {
			res = fscanf(f, "%c", &c);
			if (res == 0) {
				break;
			}
		}
		if (res == 0) {
			return NULL;
		}
		return TreeCreateRoot(&c, NULL, NULL);
	}
	else {
		Node* left = TreeCreateRec(f);
		Node* right = TreeCreateRec(f);
		return TreeCreateRoot(&c, left, right);
	}
}

Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Node* res =  TreeCreateRec(f);
	fclose(f);
	return res;
}