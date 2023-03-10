#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"mul <a> <b>\"");
		return 1;
	}
	int n = 0;
	n = atoi(argv[1]) * atoi(argv[2]);
	printf("%d", n);
	return 0;
}