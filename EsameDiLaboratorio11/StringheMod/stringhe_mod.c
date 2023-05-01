//Time 9m 36s
#include <stdio.h>
#include <stdlib.h>
void BacktrackStrModRec(int n_letters, int len, int liv, char* str) {
	if (liv == len) {
		printf("{%s}, ", str);
		return;
	}
	for (int i = 0; i < n_letters; i++) {
		str[liv] = i + 'a';
		BacktrackStrModRec(n_letters, len, liv + 1, str);
		str[liv] = 0;
	}
}
void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26 || k <= 0) {
		return;
	}
	char* str = calloc(k+1, sizeof(char));
	BacktrackStrModRec(n, k, 0, str);
	free(str);
}