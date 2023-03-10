unsigned long long Fattoriale(int n) {
	if (n < 0) {
		return 0;
	}
	if (n == 0 || n == 1) {
		return 1;
	}
	return Fattoriale(n - 1) * n;
}