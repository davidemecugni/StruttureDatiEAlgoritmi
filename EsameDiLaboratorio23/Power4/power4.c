//Time 12min
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Power4Rec(int n, int count, int current) {
	if ((count == 0 && n % 4 != 0 && n != 1) || ( current % 4 != 0 && current != 1)) {
		printf("!p4");
		return;
	}
	++count;
	current /= 4;
	if (current == 0) {
		printf("4^%d = %d", count-1, n);
		return;
	}
	Power4Rec(n, count, current);
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n;
	sscanf(argv[1], "%d", &n);
	Power4Rec(n,0,n);
	return 0;
}