#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
//Recursive template of the function
void OmbrelloniRec(int n, int k, bool* vcurr, int i, int* nsol, int cnt) {
	//Pruning: if the ad
	for (int j = 1; j < i; j++) {
		if (vcurr[j] && vcurr[j - 1]) {
			return;
		}
	}
	if (cnt == k) {
		++(*nsol);
		//Only prints to the current level i
		
		printf("%4i)", *nsol);
		for (int j = 0; j < n; j++) {
			//If the element of the set is in the subset
			if (vcurr[j]) {
				printf(" 1");
			}
			else {
				printf(" 0");
			}
		}
		printf("\n");
		
		return;
	}

	//If we reach the end of the tree("leaves")
	if (i == n) {
		return;
	}
	//Branch current element not in the subset
	vcurr[i] = 0;
	OmbrelloniRec(n, k, vcurr, i + 1, nsol, cnt);
	//Branch current element in the subset
	vcurr[i] = 1;
	OmbrelloniRec(n, k, vcurr, i + 1, nsol, cnt + 1);
	//Is needed to correctly rollback the branch
	vcurr[i] = 0;
}
//Non-recursive template of the function
int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0) {
		return 0;
	}
	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	//0 for i because it starts at level 0
	OmbrelloniRec(n, k, vcurr, 0, &nsol, 0);
	free(vcurr);
	return nsol;
}