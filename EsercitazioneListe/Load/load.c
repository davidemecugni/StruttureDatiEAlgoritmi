#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
Item* ListLoad(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return ListCreateEmpty();
	}
	Item* list = ListCreateEmpty();
	ElemType tmp;
	int ele_read=0;
	while (!feof(f)) {
		ele_read = fscanf(f, "%d", &tmp);
		if (ele_read != 1) {
			break;
		}
		list = ListInsertHead(&tmp, list);
	}
	fclose(f);
	return list;
}