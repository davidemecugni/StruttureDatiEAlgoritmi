//Time 7min
int PotenzaRec(int a, int b, int res) {
	if (b == 0) {
		return res;
	}
	return PotenzaRec(a, b - 1, res * a);
}
int Potenza(int a, int b) {
	if (a == b && a == 0) {
		return 1;
	}
	if (b == 0) {
		return 1;
	}
	return PotenzaRec(a, b, 1);
}