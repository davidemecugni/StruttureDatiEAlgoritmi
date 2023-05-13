#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
bool IsIn(const int* array, int value, size_t s_array) {
	for (size_t i = 0; i < s_array; i++) {
		if (value == array[i]) {
			return true;
		}
	}
	return false;
}
void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, int lvl, int pos, char* tmp, char* res) {
	if (pos<0 || lvl==(int)n || IsIn(f, pos, f_size)) {
		return;
	}
	if (pos == h){
		if (lvl < (int)*ret_size) {

			//res = memcpy(res, tmp, n*sizeof(char));
			for (int i = 0; i < n; i++) {
				res[i] = tmp[i];
			}
			*ret_size = lvl;
		}
		return;
	}
	tmp[lvl] = 'a';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, lvl + 1, pos + a, tmp, res);
	tmp[lvl] = 0;
	if (lvl == 0 || tmp[lvl-1]!='b') {
		tmp[lvl] = 'b';
		GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, lvl + 1, pos - b, tmp, res);
	}
	tmp[lvl] = 0;
}
char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {
	if (f == NULL) {
		return NULL;
	}
	char* res = calloc((size_t)n, sizeof(char));
	char* tmp = calloc((size_t)n, sizeof(char));
	if (res == NULL || tmp == NULL) {
		free(res);
		free(tmp);
		return NULL;
	}
	*ret_size = (size_t)n + 1;
	GuidaLaPulceRec(f, f_size, a,  b, n, h,  ret_size, 0, 0, tmp, res);
	if (*ret_size == ((size_t)n + 1)) {
		free(res);
		return NULL;
	}
	res = realloc(res, (*ret_size) * sizeof(char));
	free(tmp);
	return res;
}