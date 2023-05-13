//Time 5m 40s
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int RadiceNumreticaRec(int n) {
	if (n / 10 == 0) {
		return n;
	}
	int tmp = 0;
	while (n != 0) {
		tmp += n % 10;
		n /= 10;
	}
	return RadiceNumreticaRec(tmp);

}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n;
	int res = sscanf(argv[1], "%d", &n);
	if (res != 1 || n < 0) {
		return 1;
	}
	printf("%d", RadiceNumreticaRec(n));
	return 0;
}