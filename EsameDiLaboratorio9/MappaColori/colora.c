//Time 55m
#include "colora.h"
void PrintRis(char* ris, int dim) {
	for (int i = 0; i < dim-1; i++) {
		printf("%d -> %c; ", i, ris[i]);
	}
	printf("%d -> %c;\n", dim-1, ris[dim-1]);
}
bool IsTouching(int a1, int a2, const struct Matrix* m) {
	return m->data[a1 * (int)(m->size) + a2];
}
void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, const int dim, char* ris, int pos, int* total) {
	if (pos == dim) {
		PrintRis(ris, dim);
		*total += 1;
		return;
	}
	bool adj = false;
	//For every color
	for (int col = 0; col < c_size; col++) {
		//Controls that the same color is not adjacent
		adj = false;
		for (int same_col = 0; same_col < pos; same_col++) {
			if (ris[same_col] == c[col]) {
				if (IsTouching(same_col, pos, m)) {
					adj = true;
					continue;
				}
			}

		}
		if (!adj) {
			ris[pos] = c[col];
			MappaColoriRec(m, c, c_size, dim, ris, pos + 1, total);
			ris[pos] = 0;
		}

	}
}
int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {
	int dim = m->size;
	char* ris = calloc(dim, sizeof(char));
	int total = 0;
	MappaColoriRec(m, c, c_size, dim, ris, 0, &total);
	free(ris);
	return total;
}