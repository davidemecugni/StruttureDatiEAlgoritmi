#include "stacks.h"
#include <limits.h>
#include <stdbool.h>
unsigned Sum(Stack s) {
	unsigned sum = 0;
	for (size_t j = 0; j < s.m; j++) {
		sum += s.elements[j];
	}
	return sum;
}
bool Unequal(Stack* stacks, size_t n) {
	for (size_t i = 0; i < n - 1; i++) {
		if (Sum(stacks[i]) != Sum(stacks[i + 1])) {
			return true;
		}
	}
	return false;
}
extern unsigned MaxSumNStack(Stack* stacks, size_t n) {
	unsigned max_sum = INT_MIN;
	unsigned sum=0, index=0;
	while (Unequal(stacks, n)) {
		max_sum = 0;
		index = 0;
		for (size_t i = 0; i < n; i++) {
			sum = Sum(stacks[i]);
			if (sum > max_sum) {
				max_sum = sum;
				index = i;
			}
		}
		if (max_sum != INT_MIN) {
			stacks[index].m -= 1;
		}
		
	}
	return Sum(stacks[0]);
}