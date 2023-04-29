#include "vettore.h"

int main(void) {
	int v_int[] = { -2, 1, 3, 3, 4, 4, 4, 5, 12, 34 };
	Vector* v = calloc(sizeof(Vector), 1);
	v->capacity = v->size = 10;
	v->data = v_int;
	ElemType elem = 3;
	printf("Elemento %d in pos : %d", elem, VectorFind(v,&elem));
	return 0;
}