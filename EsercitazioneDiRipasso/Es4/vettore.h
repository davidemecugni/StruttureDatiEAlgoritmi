#if !defined VETTORE_H
#define VETTORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct vettore {
    int* data;
    size_t size;
};
extern int Pop(struct vettore* v);
extern void Push(struct vettore* v, int d);
#endif /*VETTORE_H*/