#include "reverse.h"
int main(void) {
	//Lists

	//Simple list 0 to 9
	Item* zero_to_nine = ListCreateEmpty();
	ElemType tmp;
	for (int i = 0; i < 6; i++) {
		tmp = i;
		zero_to_nine = ListInsertBack(zero_to_nine, &tmp);
	}
	zero_to_nine = Reverse(zero_to_nine, 3);
	ListWriteStdout(zero_to_nine);
	return 0;
}