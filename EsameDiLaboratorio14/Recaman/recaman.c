//Time 4m 30s

int Recaman(int n) {
	if (n < 1) {
		return -1;
	}
	if (n == 1) {
		return 1;
	}
	if (Recaman(n-1) % (n - 1) == 0) {
		return Recaman(n-1) / (n-1);
	} 
	else {
		return (n-1) * Recaman(n - 1);
	}
}