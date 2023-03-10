
int RecMin(int* v, int v_size, int min) {
	if (v_size == 0) {
		return min;
	}
	if (v[0] < RecMin(v + 1, v_size - 1, min)) {
		return v[0];
	}
	return RecMin(v + 1, v_size - 1, min);

}
extern int Minimo(const int* v, int v_size) {
	int min = v[0];
	return RecMin(v+1, v_size-1, min);
}
