#include <stdio.h>
#define N 10
void print(int v[], int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int v[], int dim) {
	//Necessario a capire quando il vettore e' ordinato
	int ordinato = 0,i;
	while (!ordinato) {
		//Nel caso vi sia uno scambio viene settato a zero
		ordinato = 1;
		for (i = 0; i < dim - 1; i++) {
			//Se due elementi non sono nell'ordine corretto
			if (v[i] > v[i + 1]) {
				swap(&v[i], &v[i + 1]);
				//Uno scambio e' avvenuto dunque il vettore non e' ordinato
				ordinato = 0;
			}
		}
		--dim;
	}
}
void InsertionSort(int v[], int dim) {
	/*
	* Sorting fatto per sistemare il vettore dal basso

	for (int i = 0; i < dim; i++) {
		int tmp = v[i];
		int j = i;
		while (j > 0 && v[j-1] > tmp) {
			v[j] = v[j - 1];
			j--;
			v[j] = tmp;
		}
	}
	*/
	//Sorting per sistemare il vettore dall'alto
	for (int i = dim - 1; i > -1; i--) {
		int tmp = v[i];
		int j = i;
		while (j<dim - 1 && v[j+1]<tmp) {
			v[j] = v[j + 1];
			j++;
			v[j] = tmp;
		}
	}
}

void MergeDIY(int A[], int first, int mid, int last) {
	int B[N], f, m, f_new;
	f = first;
	m = mid + 1;
	f_new = first;
	while (f <= mid && m <= last) {
		if (A[f] < A[m]) {
			B[f_new] = A[f];
			f++;
		}
		else {
			B[f_new] = A[m];
			m++;
		}
		f_new++;
	}
	while (f <= mid) {
		B[f_new] = A[f++];
		f_new++;
	}
	while (m <= last) {
		B[f_new] = A[m++];
		f_new++;
	}
	for (int i = first; i <= last; i++) {
		A[i] = B[i];
	}
}
void MergeSortDIY(int A[], int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		MergeSortDIY(A, first, mid);
		MergeSortDIY(A, mid+1, last);
		MergeDIY(A, first, mid, last);
	}
}
void QuickSortDIY(int A[], int first, int last) {
	int f, l, pivot;
	if (first < last) {
		f = first;
		l = last;
		pivot = A[l];
		do {
			while (A[f] < pivot) f++;
			while (A[l] > pivot) l--;
			if (f <= l) {
				swap(&A[f], &A[l]);
				f++; l--;
			}
		} while (f <= l);
		QuickSortDIY(A, first, l);
		QuickSortDIY(A, f, last);
	}
}
int main(void) {
	int v[N] = {7,4,7,7,7,8,5,6,2,3};
	print(v, N);
	QuickSortDIY(v, 0, N-1);
	print(v, N);

	return 0;
}