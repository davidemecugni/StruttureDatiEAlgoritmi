#include "list.h"
extern Item* PariDispari(Item* i);
int main(void) {
	Item* list = ListCreateEmpty();
	for (int i = 1; i < 12; i+=2) {
		list = ListInsertBack(list, &i);
	}
	for (int i = 1; i < 12; i += 1) {
		list = ListInsertBack(list, &i);
	}
	for (int i = 1, t = 0; i < 12; i += 1) {
		list = ListInsertBack(list, &t);
	}
	ListWriteStdout(list);
	list = PariDispari(list);
	ListWriteStdout(list);
}