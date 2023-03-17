/* A backtrack algorithm used to find recursively 
all subsets of dim k in a set of dim n
*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
//
//vcurr is a bool array used to select the elements
//*nsol counts the number of subsets
//cnt counts how many elements of the set are selected

//Recursive template of the function
void SubsetKRec(int n, int k, bool* vcurr, int i, int *nsol, int cnt) {
	//If the subset is correctecly formed
	//The subset is of dim k
	if (cnt == k) {
		printf("{");
		//Only prints to the current level i
		for (int j = 0; j < i; j++) {
			//If the element of the set is in the subset
			if (vcurr[j]) {
				printf(" %i ", j);
			}
		}
		printf("},");
		(*nsol)++;
		return;
	}
	
	//If we reach the end of the tree("leaves")
	if (i == n ) {
		return;
	}
	//Case current element not in the subset
	vcurr[i] = 0;
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt);
	//Case current element in the subset
	vcurr[i] = 1;
	SubsetKRec(n, k, vcurr, i + 1, nsol, cnt+1);
}
//Non-recursive template of the function
int SubsetK(int n, int k) {
	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	//0 for i because it starts at level 0
	SubsetKRec(n,k,vcurr,0, &nsol, 0);
	printf("\nNr. of subset found: %i\n", nsol);
	free(vcurr);
	return nsol;
}
int main(void) {
	SubsetK(10,3);
	return 0;
}