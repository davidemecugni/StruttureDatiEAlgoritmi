#include <stdio.h>
extern void ToUpper(char* str) {
	if (str == NULL) {
		return;
	}
	while (*str != '\0') {
		if (*str >= 'a' && *str <= 'z') {
			*str += 'A'-'a';
		}
		str++;
	}
	return;
}