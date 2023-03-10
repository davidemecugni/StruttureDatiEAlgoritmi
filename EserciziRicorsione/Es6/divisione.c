int RecDivisione(int a, int b, int res) {
	if (a < b) {
		return res;
	}
	return RecDivisione(a - b, b, res + 1);
}
int Divisione(int a, int b) {
	if (a < 0 || b <= 0) {
		return -1;
	}
	return RecDivisione(a, b, 0);
}