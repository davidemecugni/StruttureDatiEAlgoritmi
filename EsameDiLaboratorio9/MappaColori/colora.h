#if !defined COLOR_H
#define COLOR_H
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
struct Matrix {
    size_t size;
    bool* data;
};
extern int MappaColori(const struct Matrix* m, const char* c, size_t c_size);
#endif /*COLOR_H*/