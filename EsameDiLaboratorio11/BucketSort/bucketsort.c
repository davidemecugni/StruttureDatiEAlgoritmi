//Time 1hr 30min

#include "list.h"
#include <stdlib.h>
Item* BucketSort(Item* l) {
	if (l == NULL) {
		return NULL;
	}
	int len = 0, min, max;
	{
		Item* tmp = l;
		while (!ListIsEmpty(tmp)) {
			++len;
			tmp = ListGetTail(tmp);
		}
	}
	GetMinMaxSize(l, &min, &max, &len);
	if (max == min) {
		return l;
	}
	Item** bucket = calloc(len, sizeof(Item*));
	for (int i = 0; i < len; i++) {
		bucket[i] = ListCreateEmpty();
	}
	{
		Item* tmp = l;
		int b = 0;
		ElemType c;
		while (!ListIsEmpty(tmp)) {
			b = ((len - 1) * (tmp->value - min)) / (max - min);
			c = ElemCopy(&tmp->value);
			bucket[b] = ListInsertHead(&c, bucket[b]);
			tmp = ListGetTail(tmp);
		}
	}
	Item* res = ListCreateEmpty();
	for (int i = 0; i < len; i++) {
		Item* sorted = BucketSort(bucket[i]);
		res = ConcatList(res, sorted);
	}
	Item* tmp = l;
	ElemType c;
	while (!ListIsEmpty(res)) {
		c = ElemCopy(&res->value);
		tmp->value = c;
		res = ListGetTail(res);
		tmp = ListGetTail(tmp);
	}
	ListDelete(res);
	free(bucket);
	return l;
}