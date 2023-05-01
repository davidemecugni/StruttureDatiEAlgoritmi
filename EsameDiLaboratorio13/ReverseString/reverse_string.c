//Time 8min 07s
#include <string.h>
#include <stdlib.h>
char* ReverseStringRec(const char* input, char* res, int c_res) {
	if (c_res == (int)strlen(input)) {
		return res;
	}
	res[c_res] = input[strlen(input) - c_res - 1];
	ReverseStringRec(input, res, c_res + 1);
	return res; // No warnings
}
char* ReverseString(const char* str) {
	if (str == NULL) {
		return NULL;
	}
	char* res = calloc(strlen(str) + 1, sizeof(char));
	return ReverseStringRec(str, res, 0);
}