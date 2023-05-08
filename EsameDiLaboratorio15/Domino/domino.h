#define _CRT_SECURE_NO_WARNINGS
#if !defined DOMINO_H
#define DOMINO_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    uint8_t val1;
    uint8_t val2;
} Tessera;
typedef struct {
    uint32_t indice;
    bool flipped;
} Placing;
extern Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size);
#endif /*DOMINO_H*/