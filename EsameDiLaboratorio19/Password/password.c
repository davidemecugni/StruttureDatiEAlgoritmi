//Time 9m 32s
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void PasswordRec(const char* str, int n, int lvl, char* current, int* total) {
	//If we reached the desired lenght, we +1 the total of password
	//and we print the password
	if (lvl == n) {
		*total += 1;
		printf("%s\n", current);
		return;
	}
	//We try a password for every char in the array
	for (int i = 0; i < (int)strlen(str); i++) {
		current[lvl] = str[i];
		PasswordRec(str, n, lvl + 1, current, total);
	}
}
int Password(const char* str, int n) {
	//Default conditions
	if (str == NULL || n < 1) {
		return 0;
	}
	int total = 0;
	//The size of current is n+1 bc we need a password of lenght n + \0
	char* current = calloc(n+1, sizeof(char));
	//Recursively try passwords
	PasswordRec(str, n, 0, current, &total);
	free(current);
	return total;
}