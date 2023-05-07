#include "list.h"
extern Item* Sum(const Item* i1, const Item* i2);
int main(void) {
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	ElemType tmp = 7;
	i1 = ListInsertBack(i1, &tmp);
	tmp = 2;
	i1 = ListInsertBack(i1, &tmp);
	tmp = 5;
	i1 = ListInsertBack(i1, &tmp);
	tmp = 4;
	i1 = ListInsertBack(i1, &tmp);
	tmp = 4;
	i1 = ListInsertBack(i1, &tmp);
	tmp = 3;
	i2 = ListInsertBack(i2, &tmp);
	tmp = 2;
	i2 = ListInsertBack(i2, &tmp);
	tmp = 5;
	i2 = ListInsertBack(i2, &tmp);
	ListWriteStdout(i1);
	ListWriteStdout(i2);
	ListWriteStdout(Sum(i1, i2));
	return 0;
}