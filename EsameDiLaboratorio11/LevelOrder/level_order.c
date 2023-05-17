//Time 21m 19s
#include "tree.h" 
void StampaLivelloRec(const Node* t, const int level, int count, bool* stampato) {
	//If we passed a leaf
	if (TreeIsEmpty(t)) {
		*stampato = false;
		return;
	}
	//If we reached the desired level we print the element
	if (level == count) {
		printf("%d ", (int)t->value);
		//Set stampato to true bc we found an element
		*stampato = true;
		return;
	}
	bool tmp = false;
	StampaLivelloRec(t->left, level, count + 1, stampato);
	if (*stampato) {
		tmp = true;
	}
	StampaLivelloRec(t->right, level, count + 1, stampato);
	//If any subtree has reached the desired level
	tmp = (*stampato) || tmp;
	*stampato = tmp;
}
void LevelOrder(const Node* t) {
	bool stampato = true;
	int level = 0;
	//While the current level has something to be printed
	while (stampato){
		StampaLivelloRec(t, level, 0, &stampato);
		//Next level
		++level;
	}
}