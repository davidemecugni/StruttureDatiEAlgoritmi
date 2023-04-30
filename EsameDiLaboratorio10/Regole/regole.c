//Time 23min
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool IsIn(int* v, const int len, int val) {
	for (int i = 0; i < len; i++) {
		if (v[i] == val) {
			return true;
		}
	}
	return false;
}
void Print(int* r, int len) {
	for (int i = 0; i < len-1; i++) {
		printf("%d ", r[i]);
	}
	printf("%d\n", r[len - 1]);
}

void RegoleRec(const char* r, int* res, int pos, const int len) {
	if (pos == len) {
		Print(res, len);
		return;
	}
	for (int i = 1; i < len+1; i++) {
		if (!IsIn(res, len, i)) {
			if (pos == 0) {
				res[pos] = i;
				RegoleRec(r, res, pos + 1, len);
				res[pos] = 0;
			}
			else {
				if ((r[pos-1] == 'i' || r[pos-1] == 'I') && i > res[pos - 1]) {
					res[pos] = i;
					RegoleRec(r, res, pos + 1, len);
					res[pos] = 0;
				}
				if ((r[pos-1] == 'd' || r[pos-1] == 'D') && i < res[pos - 1]) {
					res[pos] = i;
					RegoleRec(r, res, pos + 1, len);
					res[pos] = 0;
				}
			}
		}
	}

}
void Regole(const char* r) {
	if (strcmp(r, "") == 0) {
		printf("1");
		return;
	}
	int len = (int)strlen(r) + 1;
	int* res = calloc(len , sizeof(int));
	RegoleRec(r, res, 0, len);
	free(res);
}