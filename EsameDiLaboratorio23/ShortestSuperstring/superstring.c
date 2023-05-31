//Time 50min
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}
char* SolveSuperstringRec(const char** v, size_t v_size, bool* used, char* res, int lvl) {
    if (lvl == (int)v_size) {
        return res;
    }
    int max = -1;
    int tmp = 0;
    int str = 0;
    for (int i = 0; i < (int)v_size; i++) {
        if (!used[i]) {
            Overlap(res, v[i], &tmp);
            if (tmp > max) {
                max = tmp;
                str = i;
            }
        }
    }
    if (max != -1) {
        res = Overlap(res, v[str], &tmp);
        used[str] = true;
        return SolveSuperstringRec(v, v_size, used, res, lvl + 1);
    }
    return res;
}
char* SolveSuperstring(const char** v, size_t v_size) {
    if (v == NULL || v_size < 1) {
        return NULL;
    }
    bool* used = calloc(v_size, sizeof(bool));
    int max = -1;
    int tmp = 0;
    int str1 = 0;
    int str2 = 1;
    for (int i = 0; i < (int)v_size; i++) {
        for (int j = 1; j < (int)v_size; j++) {
            Overlap(v[i], v[j], &tmp);
            if (tmp > max&& i<j) {
                max = tmp;
                str1 = i;
                str2 = j;
            }
        }
    }

    used[str1] = true;
    used[str2] = true;
    char* res = Overlap(v[str1], v[str2], &tmp);
    res = SolveSuperstringRec(v, v_size, used, res, 2);
    free(used);
    return res;
}