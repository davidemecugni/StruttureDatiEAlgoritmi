#define _CRT_SECURE_NO_WARNINGS

#if !defined GIOIELLI_H
#define GIOIELLI_H
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;
extern Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);
#endif /*GIOIELLI_H*/