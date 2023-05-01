//Time 6min 44s

#include <stdbool.h>
#include <string.h>
bool IsPalindromoRec(const char* str, int left, int right) {
	//If all checked letters are couples
	if (left >= right) {
		return true;
	}
	//If some letters are not the same left right
	if (str[left] != str[right]) {
		return false;
	}
	IsPalindromoRec(str, left + 1, right - 1);

}
bool IsPalindromo(const char* str) {
	if (str == NULL) {
		return false;
	}
	if (strcmp("", str) == 0) {
		return true;
	}
	return IsPalindromoRec(str, 0, strlen(str) - 1);
}