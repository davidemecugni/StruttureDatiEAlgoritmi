#if !defined PREZZO_H
#define PREZZO_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Articolo {
    char nome[11];
    int prezzo;
};
extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);
#endif /*PREZZO_H*/