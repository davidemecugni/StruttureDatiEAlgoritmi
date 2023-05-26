#include "list.h"
extern Item* Intersect(const Item* i1, const Item* i2);
int main(void) {
	ElemType i1[] = { 3, 4, 2, 0, 45, 1, 3 };
	ElemType i2[] = {8, 5, 2, 3, 45, 7};
	Item* i_1 = ListCreateEmpty();
	Item* i_2 = ListCreateEmpty();
	for (int i = 0; i < sizeof(i1) / sizeof(ElemType); i++) {
		i_1 = ListInsertBack(i_1, i1 + i);
	}
	for (int i = 0; i < sizeof(i2) / sizeof(ElemType); i++) {
		i_2 = ListInsertBack(i_2, i2 + i);
	}
	ListWriteStdout(i_1);
	ListWriteStdout(i_2);
	ElemType* res = Intersect(i_1, i_2);
	ListWriteStdout(res);
	return 0;
}