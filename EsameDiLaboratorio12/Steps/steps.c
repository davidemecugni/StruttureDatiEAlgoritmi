//Time 12m 18s
#include <stdlib.h>
#include <stdio.h>
void StepsRec(int n, int* sol, int len_sol, int* total) {
	if (n == 0) {
		*total += 1;
		printf("[");
		for (int i = 0; i < len_sol-1; i++) {
			printf("%d, ", sol[i]);
		}
		printf("%d], ", sol[len_sol - 1]);
	}
	for(int i=1;i<4;i++){
		if (n - i >= 0) {
			sol[len_sol] = i;
			StepsRec(n-i, sol, len_sol+1, total);
			sol[len_sol] = 0;
		}
	}
}
int Steps(int n) {
	if (n <= 0) {
		return 0;
	}
	int total = 0;
	int* sol = calloc(n, sizeof(int));
	StepsRec(n, sol, 0, &total);
	free(sol);
	return total;
}