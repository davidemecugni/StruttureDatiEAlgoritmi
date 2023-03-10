#include "vettore.h"
extern void Push(struct vettore* v, int d) {
	v->size += 1;
	v->data = realloc(v->data, v->size* 4);
	v->data[v->size - 1] = d;
}
extern int Pop(struct vettore* v) {
	int res = v->data[0];
	int* temp = calloc(v->size - 1, sizeof(int));
	memcpy(temp, v->data + 1, (v->size - 1)*4);
	free(v->data);
	v->data = temp;
	v->size -= 1;
	return res;
}