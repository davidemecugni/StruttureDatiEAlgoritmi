//Time 12m 00s
#include "list.h"
extern Item* CopiaDaN(const Item* i, int n);
int main(void) {
	Item* l = ListCreateEmpty();
	ElemType t;
	for (int i = 0; i < 10; i++) {
		t = i;
		l = ListInsertBack(l, &t);
	}
	Item* res = CopiaDaN(l, 8);
	return 0;
}