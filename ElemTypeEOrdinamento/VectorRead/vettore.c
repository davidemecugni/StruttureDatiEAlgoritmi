#include "vettore.h"

Vector* VectorRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Vector* v = calloc(sizeof(Vector), 1);
	v->data = calloc(sizeof(ElemType), 1);
	v->size = 0;
	v->capacity = 1;
	int res;
	while (1) {
		res = ElemRead(f, &v->data[v->size]);
		if (res <= 0) {
			break;
		}
		++(v->size);
		v->data = realloc(v->data, sizeof(ElemType) * ++(v->capacity));
	}
	v->data = realloc(v->data, sizeof(ElemType) * (v->size));
	v->capacity = v->size;
	fclose(f);
	return v;
}
Vector* VectorReadSorted(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Vector* v = calloc(sizeof(Vector), 1);
	v->data = calloc(sizeof(ElemType), 1);
	v->size = 0;
	v->capacity = 1;
	int res, pos;
	ElemType tmp;
	while (1) {
		res = ElemRead(f, &tmp);
		if (res <= 0) {
			break;
		}
		pos = -1;
		for (size_t j = 0; j < v->size; j++) {
			if (ElemCompare(&v->data[j], &tmp) == 1 || ElemCompare(&v->data[j], &tmp) == 0) {
				pos = j;
				break;
			}
		}
		if (pos == -1) {
			v->data[v->size] = ElemCopy(&tmp);
		}
		else {
			for (int j = v->size; j > pos; j--) {
				ElemSwap(&v->data[j], &v->data[j - 1]);
			}
			v->data[pos] = ElemCopy(&tmp);
		}
		++(v->size);
		v->data = realloc(v->data, sizeof(ElemType) * ++(v->capacity));
	}
	v->data = realloc(v->data, sizeof(ElemType) * (v->size));
	v->capacity = v->size;
	fclose(f);
	return v;
}