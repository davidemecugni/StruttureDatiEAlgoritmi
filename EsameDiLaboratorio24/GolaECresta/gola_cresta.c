//Time 12min
#include <stdlib.h>
#include <stdio.h>
void GolaCrestaRec(size_t n, int lvl, int* v_curr) {
	if (lvl >= 3) {
		for (int i = 0; i < lvl - 2; i++) {
			if (!(v_curr[i]< v_curr[i+1] && v_curr[i+1]>v_curr[i+2]) && !(v_curr[i]>v_curr[i+1] && v_curr[i+1]<v_curr[i+2])) {
				return;
			}
		}
	}
	if ((int)n == lvl) {
		printf("(");
		for (int i = 0; i < (int)n - 1; i++) {
			printf("%d, ", v_curr[i]);
		}
		printf("%d), ", v_curr[(int)n - 1]);
		return;
	}
	for (int i = 0; i < 3; i++) {
		v_curr[lvl] = i;
		GolaCrestaRec(n, lvl + 1, v_curr);
	}
}
void GolaCresta(size_t n) {
	int* v_curr = calloc(n, sizeof(int));
	GolaCrestaRec(n, 0, v_curr);
	free(v_curr);
}