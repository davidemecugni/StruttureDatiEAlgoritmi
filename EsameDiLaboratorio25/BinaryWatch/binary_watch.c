//Time 30min
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
int BoolToInt(bool* a, bool hour) {
	int n = 0, power = 1;
	if (hour) {
		for (int i = 4; i > -1; i--) {
			n += power * a[i];
			power *= 2;
		}
		return n;
	}
	else {
		for (int i = 10; i > 4; i--) {
			n += power * a[i];
			power *= 2;
		}
		return n;
	}

}
bool IsValid(int h, int m) {
	return (h >= 0) && (h <= 23) && (m >= 0) && (m <= 59);
}
extern void ValidTimesRec(uint8_t n, bool* time, int curr_leds, int lvl) {
	int h = BoolToInt(time, true);
	int m = BoolToInt(time, false);
	if (!IsValid(h, m) || lvl >= 12) {
		return;
	}
	if ((int)n == curr_leds) {
		printf("%02d:%02d, ", h, m);
		return;
	}
	time[lvl] = true;
	ValidTimesRec(n, time, curr_leds + 1, lvl+1);
	time[lvl] = false;
	ValidTimesRec(n, time, curr_leds, lvl +1);
}
// 16 8 4 2 1 , 32 16 8 4 2 1
//Time xxxxx:xxxxxx
void ValidTimes(uint8_t n) {
	bool* timer = calloc(12, sizeof(bool));
	ValidTimesRec(n, timer, 0, 0);
	free(timer);
}