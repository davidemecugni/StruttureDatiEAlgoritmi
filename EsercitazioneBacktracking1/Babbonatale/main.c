#include <stdio.h>
extern void BabboNatale(const int* pacchi, size_t pacchi_size, int p);


int main(void) {
	int pacchi[] = { 1, 2, 20, 10, 15, 13, 100, 23, 49, 30, 5 };
	BabboNatale(pacchi, 11,  200);
	return 0;
}