int recProdotto(int a, int b, int res) {
	if (b == 0) {
		return res;
	}
	if (b > 0) {
		return recProdotto(a, b - 1, res + a);
	}
	return recProdotto(a, b + 1, res - a);
}
int ProdottoNegativi(int a, int b) {
	return recProdotto(a, b, 0);
}