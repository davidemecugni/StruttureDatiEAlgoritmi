#include "list.h"
extern Item* BucketSort(Item* l);
int main(void) {
	int t = 5;
	Item* l = ListCreateEmpty();
	l = ListInsertBack(l, &t);
	t = 24;
	l = ListInsertBack(l, &t);
	t = 37;
	l = ListInsertBack(l, &t);
	t = 6;
	l = ListInsertBack(l, &t);
	l = BucketSort(l);
	return 0;
}