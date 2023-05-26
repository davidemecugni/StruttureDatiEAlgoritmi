//Time 44min
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int IndexOfUnordered(const int* un, int val,size_t size) {
	for (int i = 0; i < (int)size; i++) {
		if (un[i] == val) {
			return i;
		}
	}
	return -1;
}
int Compare(const void* a, const void* b) {
	const int* aa = a;
	const int* bb = b;
	if (*aa == *bb) {
		return 0;
	}
	else if (*aa < *bb) {
		return -1;
	}
	return 1;
}
void PrintMoney(int* v_curr, size_t m_size) {
	for (int i = 0; i < (int)m_size - 1; i++) {
		printf("%d ", v_curr[i]);
	}
	printf("%d\n", v_curr[(int)m_size - 1]);
}
void CombinaMoneteRec(int b, const int* m, size_t m_size, int* v_curr, int* total, int start,int* ord) {
	if (b == 0) {
		*total += 1;
		PrintMoney(v_curr, m_size);
		return;
	}
	for (int i = start; i<(int)m_size && b >= ord[i]; i++) {
		v_curr[IndexOfUnordered(m, ord[i],m_size)] += 1;
		CombinaMoneteRec(b - ord[i], m, m_size, v_curr, total, start, ord);
		v_curr[IndexOfUnordered(m, ord[i], m_size)] -= 1;
		start++;
	}
	return;
}
int CombinaMonete(int b, const int* m, size_t m_size) {
	int* ord = calloc(m_size, sizeof(int));
	memcpy(ord, m, m_size * sizeof(int));
	qsort(ord, m_size, sizeof(int), &Compare);
	int* v_curr = calloc(m_size, sizeof(int));
	int total = 0;
	CombinaMoneteRec(b, m, m_size, v_curr, &total, 0, ord);
	free(v_curr);
	free(ord);
	return total;
}