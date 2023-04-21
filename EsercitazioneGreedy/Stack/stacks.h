#if !defined STACK_H
#define STACK_H
#include <stdlib.h>
typedef struct {
unsigned* elements;
size_t m;
} Stack;
extern unsigned MaxSumNStack(Stack* stacks, size_t n);
#endif /*STACK_H*/