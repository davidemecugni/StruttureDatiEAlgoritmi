#include "list.h"

extern Item* Rotate(Item* i, int n);
int main(void) {
	Item *list = ListCreateEmpty();
	ElemType e;
	e = 1;
	list = ListInsertBack(list, &e);
	e = 2;
	list = ListInsertBack(list, &e);
	/*
	e = 3;
	list = ListInsertBack(list, &e);
	e = 4;
	list = ListInsertBack(list, &e);
	e = 5;
	list = ListInsertBack(list, &e);
	*/
	ListWriteStdout(list);
	Item* res = Rotate(list, 1);
	ListWriteStdout(res);
	ListDelete(res);
	return 0;
}