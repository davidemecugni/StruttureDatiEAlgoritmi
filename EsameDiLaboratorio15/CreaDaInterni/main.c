#include "list.h"
extern Item* CreaDaInterni(const Item* i, double r);
int main(void) {
	Item* l = ListCreateEmpty();
	ElemType tmp = { .x = 1, .y = 2 };
	l = ListInsertBack(l, &tmp);
	tmp.x = 5;
	tmp.y = 1;
	l = ListInsertBack(l, &tmp);
	tmp.x = 6;
	tmp.y = 1;
	l = ListInsertBack(l, &tmp);
	tmp.x = 5;
	tmp.y = 5;
	l = ListInsertBack(l, &tmp);
	Item* res = CreaDaInterni(l, (double)6);
	ListDelete(res);
	return 0;
}