//Time 2m 20s
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int MCD(int m, int n) {
	if (m < n) {
		Swap(&m, &n);
	}
	if (n == 0) {
		return m;
	}
	return MCD(n, m % n);
}