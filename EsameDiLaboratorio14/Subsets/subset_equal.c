//1hr 35min
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int Lowest(int* v, int len) {
	int min = v[0];
	for (int i = 1; i < len; i++) {
		if (v[i] < min) {
			min = v[i];
		}
	}
	return min;
}
bool IsIn(int* v, int len, int val) {
	for (int i = 0; i < len; i++) {
		if (v[i] == val) {
			return true;
		}
	}
	return false;
}
void SubsetEqualRec(int n, int s, int* res, int sum, bool* vcurr, int i) {
	//If the partial sum is bigger than desired or the index is over the max
	if ( sum > s || i > n) {
		return;
	}
	if (sum == s ) {
		printf("{ ");
		for (int j = 0; j < n; j++) {
			//If the element is selected
			if (vcurr[j]) {
				printf("%d ", j+1);
			}

		}
		printf("}, ");
		return;
	}
	//If we finished all the elements
	if (i == n) {
		return;
	}
	vcurr[i] = 1;
	SubsetEqualRec(n, s, res, sum + i + 1, vcurr, i + 1);

	//No sum if the element isn't selected
	vcurr[i] = 0;
	SubsetEqualRec(n, s, res, sum, vcurr, i + 1);
}
void SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0) {
		return;
	}
	//Selects the elements 0->1, 1->2, 2->3...
	bool* vcurr = calloc(n, sizeof(bool));
	int* res = calloc(n, sizeof(int));

	SubsetEqualRec(n, s, res, 0, vcurr, 0);
	free(res);
	free(vcurr);
}