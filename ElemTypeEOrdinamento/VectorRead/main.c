#include "vettore.h"

int main(void) {
	Vector* v = VectorRead("input_int_01.txt");
	printf("Non sorted: ");
	for (int i = 0; i < v->size; i++) {
		ElemWriteStdout(&v->data[i]);
		printf(" ");
	}
	printf("\n\nSorted: ");
	v = VectorReadSorted("input_int_01.txt");
	for (int i = 0; i < v->size; i++) {
		ElemWriteStdout(&v->data[i]);
		printf(" ");
	}
	free(v->data);
	free(v);
	return 0;
}