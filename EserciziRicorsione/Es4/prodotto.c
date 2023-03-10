int recProdotto(int a, int b, int res) {
	if (b == 0) {
		return res;
	}
	return recProdotto(a, b - 1, res + a);
}
extern int Prodotto(int a, int b) {
	if (a < 0 || b < 0) {
		return -1;
	}
	return recProdotto(a, b, 0);
}