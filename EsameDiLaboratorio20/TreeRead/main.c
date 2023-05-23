#include "tree.h"
extern Node* TreeRead(const char* filename);
int main(void) {
	Node* res = TreeRead("tesdfst.txt");
	TreeWriteStdoutInOrder(res);
	TreeDelete(res);
	return 0;
}