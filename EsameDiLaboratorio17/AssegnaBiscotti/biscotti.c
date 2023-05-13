//Time 30min
#include <stdlib.h>
#include <stdbool.h>
/*
bool IsIn(int* v, size_t dim, int val) {
    for (int i = 0; i < (int)dim; i++) {
        if (v[i] == val) {
            return true;
        }
    }
    return false;
}
*/
int BambiniContenti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size, int *v_curr) {
    int bambini_contenti = 0;
    int* g_per_bambino = calloc(bam_size, sizeof(int));
    for (int i = 0; i < (int)bis_size; i++) {
        if (v_curr[i] != -1) {
            g_per_bambino[v_curr[i]] += bis[i];
        }
    }
    for (int i = 0; i < (int)bam_size; i++) {
        if (g_per_bambino[i] >= bam[i]) {
            bambini_contenti++;
        }
    }
    free(g_per_bambino);
    return bambini_contenti;

}
void AssegnaBiscottiRec(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size, int lvl, int* v_curr, int* v_best, int* b_bambini) {
    int bambini_contenti = BambiniContenti(bam, bam_size, bis, bis_size, v_curr);
    if (bambini_contenti > *b_bambini) {
        *b_bambini = bambini_contenti;
    }
    if (lvl == (int)bis_size) {
        return;
    }

    for (int i = 0; i < (int)bam_size; i++) {
        v_curr[lvl] = i;
        AssegnaBiscottiRec(bam, bam_size, bis, bis_size, lvl + 1, v_curr, v_best, b_bambini);
        v_curr[lvl] = -1;
    }
}
int AssegnaBiscotti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size) {
    if (bam == NULL || bis == NULL || bam_size == 0) {
        return 0;
    }
    int b_bambini = 0;
    int* v_curr = calloc(bis_size, sizeof(int));
    int* v_best = calloc(bis_size, sizeof(int));
    for (int i = 0; i < (int)bis_size; i++) {
        v_curr[i] = v_best[i] = -1;
    }
    AssegnaBiscottiRec(bam, bam_size, bis, bis_size, 0, v_curr, v_best, &b_bambini);
    free(v_curr);
    free(v_best);
    return b_bambini;
}