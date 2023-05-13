#include "list.h"
extern Item* Reverse(Item* i);
int main(void) {
	Item* list = ListCreateEmpty();
	for (int i = 0; i < 4; i++) {
		list = ListInsertBack(list, &i);
	}
	ListWriteStdout(list);
	Item* res = Reverse(list);
	printf("Res: ");
	ListWriteStdout(res);
	ListDelete(list);
	return 0;
}