#include <stdlib.h>
extern int AssegnaBiscotti(const int* bam, size_t bam_size,
	const int* bis, size_t bis_size);
int main(void) {
	int bam[] = { 10, 20, 30 };
	int bis[] = { 10, 50 };
	int res = AssegnaBiscotti(bam, 3, bis, 2);
	return 0;
}