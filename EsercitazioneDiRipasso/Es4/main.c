#include "vettore.h"

int main(void) {
	struct vettore* es = calloc(1,sizeof(struct vettore));
	es->data = calloc(3, 4);
	es->data[0] = 1;
	es->data[1] = 2;
	es->data[2] = 3;
	es->size = 3;
	Push(es, 4);

}