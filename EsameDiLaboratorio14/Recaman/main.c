#include <stdio.h>
extern int Recaman(int n);
int main(void) {
	for (int i = 0; i < 10; i++) {
		printf("Recaman(%d) = %4d\n", i, Recaman(i));
	}
}