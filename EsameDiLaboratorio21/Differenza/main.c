#include "differenza.h"
extern Item* Differenza(const Item* i1, const Item* i2);

int main(void) {
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	for (char i = '4'; i < '9'+1; i++) {
		i1 = ListInsertBack(i1, &i);
	}
	char a = 64;
	for (char i = '5'; i > '0'-1; i--) {
		i2 = ListInsertBack(i2, &i);
	}
	ListWriteStdout(i1);
	ListWriteStdout(i2);
	Item* res = Differenza(i1, i2);
	ListWriteStdout(res);
	ListDelete(i1);
	ListDelete(i2);
	ListDelete(res);
	return 0;
}