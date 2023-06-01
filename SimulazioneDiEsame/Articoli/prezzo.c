//Time 28min
#include "prezzo.h"
void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum, int lvl, int partial_sum, bool* v_curr) {
	if (partial_sum == sum) {
		for (int i = 0; i < lvl; i++) {
			if (v_curr[i]) {
				printf("%s, ", a[i].nome);
			}
		}
		printf("\n");
		return;
	}
	if (lvl >= (int)a_size || partial_sum > sum) {
		return;
	}
	v_curr[lvl] = true;
	TrovaArticoliRec(a, a_size, sum, lvl + 1, partial_sum + a[lvl].prezzo, v_curr);
	v_curr[lvl] = false;
	TrovaArticoliRec(a, a_size, sum, lvl + 1, partial_sum, v_curr);

}
extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	if (a == NULL || a_size == 0) {
		return;
	}
	bool* v_curr = calloc(a_size, sizeof(bool));
	TrovaArticoliRec(a, a_size, sum, 0, 0, v_curr);
	free(v_curr);
}