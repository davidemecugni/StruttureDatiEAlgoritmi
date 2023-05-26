#include "list.h"
extern Item* ListLoad(const char* filename);

int main(void) {
	Item* list = ListLoad("data_00.txt");
	ListWriteStdout(list);
	return 0;
}
