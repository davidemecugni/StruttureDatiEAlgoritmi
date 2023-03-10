#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"occorrenze <s> <c>\")");
		return 1;
	}
	int n = 0;
	for (int i = 0; i < (int)strlen(argv[1]); i++) {
		if (argv[1][i] == argv[2][0]) {
			++n;
		}
	}
	printf("%d", n);
	return 0;
}