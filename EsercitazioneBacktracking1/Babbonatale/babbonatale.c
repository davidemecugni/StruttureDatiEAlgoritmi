#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Recursive template of the function
//p peso, selected_gifts is the current subset, i is the level of the tree, cnt is the number of presents in the current solution, max is the best number of presents found, max_gifts is the best solution 
void BabboNataleRec(const int *pacchi, size_t pacchi_size, int p, bool* selected_gifts, size_t i, int cnt, int *max, bool* max_gifts ) {
	int total_weight = 0;
	for(size_t j = 0; j < i; j++) {
		if (selected_gifts[j]) {
			total_weight += pacchi[j];
		}
	}
	//Pruning: if the cargo overweights the limit or
	//if the branch is suboptimal compared to the best branch
	//already found
	if (total_weight > p || cnt + (pacchi_size - i - 1) < *max) {
		return;
	}
	//If the solution is perfect
	if (total_weight == p ) {
		memcpy(max_gifts, selected_gifts, sizeof(bool) * pacchi_size);
		*max = cnt;
		return;
	}
	//If the solution is better then the best one found before
	if (cnt>*max) {
		memcpy(max_gifts, selected_gifts, sizeof(bool) * pacchi_size);
		*max = cnt;
		return;
	}

	//If we reach the end of the tree("leaves")
	if (i == pacchi_size) {
		return;
	}
	//Branch present not in the subset
	selected_gifts[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, selected_gifts, i+1, cnt, max, max_gifts);
	//Branch present in the subset
	selected_gifts[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, selected_gifts, i+1, cnt+1, max, max_gifts);
	//Is needed to correctly rollback the branch
	selected_gifts[i] = 0;
}
//Non-recursive template of the function
void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	if (pacchi == NULL || p < 0) {
		return;
	}
	bool* selected_gifts = calloc(pacchi_size, sizeof(bool));
	bool* max_gifts = calloc(pacchi_size, sizeof(bool));
	int max = 0;
	//0 for i because it starts at level 0
	BabboNataleRec(pacchi, pacchi_size, p, selected_gifts, 0, 0, &max, max_gifts);
	if (max_gifts != 0) {
		for (size_t i = 0; i < pacchi_size; i++) {
			printf("%i ", max_gifts[i]);
		}
	}
	free(selected_gifts);
	free(max_gifts);
	return;
}