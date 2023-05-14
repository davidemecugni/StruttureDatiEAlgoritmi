//Time 17m 30s
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char NumberToCharT9(char n, int option) {
	switch (n) {
	case '2': 
		if (option == 0) {
			return 'A';
		}
		else if (option == 1) {
			return 'B';
		}
		else if (option == 2) {
			return 'C';
		}
		else {
			return 0;
		}
		break;
	case '3': 
		if (option == 0) {
			return 'D';
		}
		else if (option == 1) {
			return 'E';
		}
		else if (option == 2) {
			return 'F';
		}
		else {
			return 0;
		}
		break;
	case '4': 
		if (option == 0) {
			return 'G';
		}
		else if (option == 1) {
			return 'H';
		}
		else if (option == 2) {
			return 'I';
		}
		else {
			return 0;
		}
		break;
	case '5':
		if (option == 0) {
			return 'J';
		}
		else if (option == 1) {
			return 'K';
		}
		else if (option == 2) {
			return 'L';
		}
		else {
			return 0;
		}
		break;
	case '6': 
		if (option == 0) {
			return 'M';
		}
		else if (option == 1) {
			return 'N';
		}
		else if (option == 2) {
			return 'O';
		}
		else {
			return 0;
		}
		break;
	case '7': 
		if (option == 0) {
			return 'P';
		}
		else if (option == 1) {
			return 'Q';
		}
		else if (option == 2) {
			return 'R';
		}
		else {
			return 'S';
		}
		break;
	case '8': 
		if (option == 0) {
			return 'T';
		}
		else if (option == 1) {
			return 'U';
		}
		else if (option == 2) {
			return 'V';
		}
		else {
			return 0;
		}
		break;
	case '9': 
		if (option == 0) {
			return 'W';
		}
		else if (option == 1) {
			return 'X';
		}
		else if (option == 2) {
			return 'Y';
		}
		else {
			return 'Z';
		}
		break;
	default: return 0;
	}
}
void ParoleT9Rec(const char* str, char* v_curr, int lvl, int *n_parole) {
	if (lvl == (int)strlen(str)) {
		printf("%s\n", v_curr);
		*n_parole += 1;
	}
	for (int i = 0; i < 4; i++) {
		char letter = NumberToCharT9(str[lvl], i);
		if (letter != 0) {
			v_curr[lvl] = letter;
			ParoleT9Rec(str, v_curr, lvl + 1, n_parole);
		}
	}
}
int ParoleT9(const char* str) {
	if (str == NULL) {
		return 0;
	}
	int n_parole = 0;
	char* v_curr = calloc(strlen(str) + 1, sizeof(char));
	ParoleT9Rec(str, v_curr, 0, &n_parole);
	free(v_curr);
	return n_parole;
}