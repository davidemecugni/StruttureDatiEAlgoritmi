#define _CRT_SECURE_NO_WARNINGS
#if !defined VETTORE_H
#define VETTORE_H
#include "elemtype.h"
#include <stdlib.h>
typedef struct {
	size_t capacity;
	size_t size;
	ElemType* data;
} Vector;
void VectorSort(Vector* v);

#endif /*VETTORE_H*/