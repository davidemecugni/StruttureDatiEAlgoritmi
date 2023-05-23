#include <stdlib.h>
int TempoTrasportoRec(int n, const int* t, int p, int* v_curr, int lvl) {
	if (v_curr[n - 1] == p) {
		return lvl;
	}
	for (int i = n-2; i> -1; i--) {
		if (v_curr[i] != 0) {
			if (t[i] > v_curr[i]) {
				if (i + 1 < n) {
					v_curr[i + 1] += v_curr[i];
				}
				v_curr[i] = 0;
			}
			else {
				if (i + 1 < n) {
					v_curr[i + 1] += t[i];
				}
				v_curr[i] -= t[i];
			}
		}
	}
	return TempoTrasportoRec(n, t, p, v_curr, lvl + 1);
}
int TempoTrasporto(int n, const int* t, int p) {
	if (t == NULL || n < 0 || p < 0) {
		return -1;
	}
	int *v_curr = calloc(n, sizeof(int));
	v_curr[0] = p;
	int res = TempoTrasportoRec(n, t, p, v_curr, 0);
	free(v_curr);
	return res;
}