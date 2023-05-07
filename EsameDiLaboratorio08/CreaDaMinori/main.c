#include "list.h"

extern Item* CreaDaMinori(const Item* i, int v);
int main(void) {
	Item* test = ListCreateEmpty();
	for (int i = 0; i < 10; i++) {
		test = ListInsertBack(test, &i);
	}
	Item* res = CreaDaMinori(test, 5);
	return 0;
}