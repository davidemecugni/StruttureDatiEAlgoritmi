//Time 14min
#include <stdlib.h>
#include <stdio.h>
void ParentesiRec(int n, char* v_curr, int lvl, int current_open, int total_open, int* total) {
	if (2*n == lvl) {
		printf("%s\n", v_curr);
		*total += 1;
		return;
	}
	if (total_open<n) {
		v_curr[lvl] = '(';
		ParentesiRec(n, v_curr, lvl + 1, current_open + 1, total_open +1, total);
	}
	if (current_open != 0) {
		v_curr[lvl] = ')';
		ParentesiRec(n, v_curr, lvl + 1, current_open - 1, total_open, total);
	}
}
extern int Parentesi(int n) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return 0;
	}
	int total = 0;
	char* v_curr = calloc(2*(size_t)n+1, sizeof(char));
	ParentesiRec(n, v_curr, 0, 0, 0, &total);
	free(v_curr);
	return total;

}