#include <string.h>

int TenToNth(int n) {
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= 10;
	}
	return res;
}
//18 min
int AToIRec(const char* str, int pow, int total, int pos) {
	if (pow == 1) {
		return total + str[pos]-'0';
	}
	AToIRec(str, pow / 10, total + pow * (str[pos] - '0'), pos + 1);
}
int AToI(const char* str) {
	if (str == NULL) {
		return 0;
	}
	return AToIRec(str, TenToNth((int)strlen(str) - 1), 0,0);
}