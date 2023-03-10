#include <limits.h>
int abs(int x) {
	if (x > 0) {
		return x;
	}
	return -x;
}
int RecDivisione(int a, int b, int res, int segno) {
	if (abs(a) < abs(b)) {
		return res;
	}
	if (segno == 0) {
		if ((a > 0 && b > 0 )||( a < 0 && b < 0)) {
			segno = 1;
		}
		else {
			segno = -1;
		}
	}
	return RecDivisione(abs(a) - abs(b), abs(b), res + segno, segno);
	
	
}
int DivisioneNegativi(int a, int b) {
	if (b==0) {
		return INT_MAX;
	}
	return RecDivisione(a, b, 0,0);
}