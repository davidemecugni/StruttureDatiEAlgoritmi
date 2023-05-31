//Time 38min
#include <stdlib.h>
#include <stdbool.h>
bool IsIn(const int* s, int val) {
	for (int i = 0; i < 9; i++) {
		if (s[i] == val) {
			return true;
		}
	}
	return false;
}
int ProductRow(const int* s, int row, int n) {
	int res = 1;
	for (int i = row * n; i < row * n + n; i++) {
		res *= s[i];
	}
	return res;
}
int ProductCol(const int* s, int row, int n) {
	int res = 1;
	for (int i = 0; i < n*n; i+=n) {
		res *= s[i+row];
	}
	return res;
}
bool IsValid(int* v_curr, int n) {
	int val = ProductCol(v_curr, 0, n);
	for (int i = 1; i < n; i++) {
		if (ProductCol(v_curr, i, n) != val) {
			return false;
		}
	}
	for (int i = 0; i < n; i++) {
		if (ProductRow(v_curr, i, n) != val) {
			return false;
		}
	}
	return true;
}
void RisolviProdottoRec(int n, const int* s, int* v_curr, bool* found, int lvl, bool * is_in) {
	if (lvl == n * n && *found == false) {
		if (IsValid(v_curr, n)) {
			if (!IsIn(s, -200)) {
				*found = true;
			}
		}
	}
	for (int i = 0; i < n*n && *found == false; i++) {
		if (is_in[i] == false) {
			v_curr[lvl] = s[i];
			is_in[i] = true;
			RisolviProdottoRec(n, s, v_curr, found, lvl + 1, is_in);
			is_in[i] = false;
			if (*found == false) {
				v_curr[lvl] = -200;
			}
		}
	}
}
int* RisolviProdotto(int n, const int* s) {
	int* v_curr = calloc((size_t)n*n, sizeof(int));
	bool* is_in = calloc((size_t)n * n, sizeof(bool));
	bool found = false;
	RisolviProdottoRec(n, s, v_curr, &found, 0, is_in);
	free(is_in);
	if (found) {
		return v_curr;
	}
	free(v_curr);
	return NULL;
}