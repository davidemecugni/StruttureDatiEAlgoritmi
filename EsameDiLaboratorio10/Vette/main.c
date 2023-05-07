#include "list.h"
extern int ContaVette(const Item* i);
int main(void) {
	Item* list = ListCreateEmpty();
	for (int i = 10; i -->0;) {
		list = ListInsertBack(list, &i);
	}
	int res = ContaVette(list);
	return 0;
}