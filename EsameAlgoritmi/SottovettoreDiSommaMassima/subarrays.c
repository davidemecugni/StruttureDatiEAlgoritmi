#include <stdlib.h>
#include <stdbool.h>
bool IsValid(bool* v_curr, int n) {
	bool streak = false;
	bool streak_is_ended = false;
	for (int i = 0; i < n; i++) {
		if (v_curr[i] == true && !streak_is_ended) {
			streak = true;
			continue;
		}
		if (streak == true && v_curr[i] == false) {
			streak_is_ended = true;
			streak = false;
			continue;
		}
		if (streak_is_ended && v_curr[i] == true) {
			return false;
		}
	}
	return true;
}
void OptimalSubarrayRec(const int* v, int n, bool* v_curr, int lvl, int sum, int* best_sum) {
	if (!IsValid(v_curr, n)) {
		return;
	}
	if (lvl == n) {
		if (sum >= *best_sum) {
			*best_sum = sum;
		}
		return;
	}
	v_curr[lvl] = true;
	OptimalSubarrayRec(v, n, v_curr, lvl + 1, sum + v[lvl], best_sum);
	v_curr[lvl] = false;
	OptimalSubarrayRec(v, n, v_curr, lvl + 1, sum, best_sum);
	
}
extern int OptimalSubarray(const int* v, size_t n) {
	if (v == NULL || n == 0) {
		return 0;
	}
	int somma_massima = 0;
	bool* v_curr = calloc(n, sizeof(bool));
	OptimalSubarrayRec(v, n, v_curr, 0, 0, &somma_massima);
	free(v_curr);
	return somma_massima;
}