//Time 21m 19s
#include "tree.h" 
void MaxDepth(const Node* t, int* depth) {
	if (TreeIsEmpty(t)) {
		return;
	}
	MaxDepth(t->left, depth);
	MaxDepth(t->right, depth);

}
void StampaLivelloRec(const Node* t, const int level, int count, bool* stampato) {
	if (TreeIsEmpty(t)) {
		*stampato = false;
		return;
	}
	if (level == count) {
		printf("%d ", (int)t->value);
		*stampato = true;
		return;
	}
	bool tmp = false;
	StampaLivelloRec(t->left, level, count + 1, stampato);
	if (*stampato) {
		tmp = true;
	}
	StampaLivelloRec(t->right, level, count + 1, stampato);
	tmp = (*stampato) || tmp;
	*stampato = tmp;
}
void LevelOrder(const Node* t) {
	bool stampato = true;
	int level = 0;
	int depth;
	MaxDepth(t, &depth);
	while (stampato){
		StampaLivelloRec(t, level, 0, &stampato);
		++level;
	}
}