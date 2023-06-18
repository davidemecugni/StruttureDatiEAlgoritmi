//Time 5min 25s
#include "tree.h"
void Sum(const Node* t, size_t level, size_t current, int* total) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (level == current) {
		*total += t->value;
		return;
	}
	Sum(TreeLeft(t), level, current + 1, total);
	Sum(TreeRight(t), level, current + 1, total);
}
extern int LevelSum(const Node* t, size_t level) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int total = 0;
	Sum(t, level, 0, &total);
	return total;
}