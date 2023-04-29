#include <stdlib.h>
#include <stdio.h>

#define N 10



void scambia(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}



void BubbleSort(int v[], int dim) {
	int i;
	int ordinato = 0;
	while (dim > 1 && !ordinato) {
		ordinato = 1; /* hp: ? ordinato */
		for (i = 0; i < dim - 1; i++)
			if (v[i] > v[i + 1]) {
				scambia(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		dim--;
	}
}


void InsertionSort(int v[], int dim) {

	for (int i = 1; i < dim; i++) {
		int temp = v[i];
		int j = i;
		//printf("i: %d j: %d temp: %d\n", i, j , temp);
		//for(int i=0; i<7; i++)
		//	printf("%d ", v[i]);
		//printf("\n");
		while (j > 0 && v[j - 1] > temp) {
			v[j] = v[j - 1];
			j--;
			//	printf("i: %d j: %d temp: %d\n", i, j , temp);
			//	for(int i=0; i<7; i++)
			//		printf("%d ", v[i]);
			//	printf("\n");
			v[j] = temp;
		}
	}
}


void Merge(int A[], int first, int last, int mid) {
	int i, j, k, h, B[N];
	i = first;
	j = mid + 1;
	k = first;
	while (i <= mid && j <= last) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		}
		else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		B[k] = A[i++];
		k++;
	}
	while (j <= last) {
		B[k] = A[j++];
		k++;
	}
	for (i = first; i <= last; i++)
		A[i] = B[i];
}


void MergeSort(int A[], int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		MergeSort(A, first, mid);
		MergeSort(A, mid + 1, last);
		Merge(A, first, last, mid);
	}
}




void QuickSort(int A[], int first, int last) {
	int i, j, pivot;
	if (first < last) {
		i = first;
		j = last;
		pivot = A[last];
		do {
			while (A[i] < pivot) i++;
			while (A[j] > pivot) j--;
			if (i <= j) {
				scambia(&A[i], &A[j]);
				i++, j--;
			}
		} while (i <= j);
		QuickSort(A, first, j);
		QuickSort(A, i, last);
	}
}


int BinSearchRec(int A[], int first, int last, int target) {

	if (first > last)
		return -1; // non trovato
	int mid = (first + last) / 2; // mediana
	int middle = A[mid];
	if (middle == target)return mid; // trovato
	else if (middle < target) // cerco a destra
		return BinSearchRec(A, mid + 1, last, target);
	else
		// cerco a sinistra
		return BinSearchRec(A, first, mid - 1, target);

}

int BinSearch(int A[], int first, int last, int target) {

	int mid, middle;
	while (first <= last) {
		mid = (first + last) / 2; // mediana
		middle = A[mid];
		if (middle == target) return mid; // trovato
		else if (middle < target) // cerco a destra
			first = mid + 1;
		else
			// cerco a sinistra
			last = mid - 1;

	}
	return -1; // non trovato
}

int lower_bound(int A[], int first, int last, int target) {

	int mid, middle;
	while (first < last) {
		mid = (last + first) / 2; // mediana
		middle = A[mid];
		if (middle < target) // cerca a destra
			first = mid + 1;
		else
			// cerca a sinistra
			last = mid;

	}


	if (first == last && A[first] < target) {
		first++;
	}

	// Ritorno l'indice di lower_bound
	if (first == last)
		return first;
	else
		// lower_bound non trovato
		return -1;

}

int upper_bound(int A[], int first, int last, int target) {

	int mid, middle;
	while (first < last) {
		mid = (last + first) / 2; // mediana
		middle = A[mid];
		if (middle <= target) // cerca a destra
			first = mid + 1;
		else
			// cerca a sinistra
			last = mid;

	}

	if (first == last && A[first] == target) {
		first++;
	}

	// Ritorno l'indice di upper_bound
	if (first == last)
		return first;
	else
		// upper_bound non trovato
		return -1;

}

void main() {

	int v[N] = {
		//7,4,2,1,7,3,5};
		7,4,7,7,7,8,5,6,2,3 };

	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);

	BubbleSort(v, N);
	//InsertionSort(v, N);
	//MergeSort(v, 0, N-1);
	//QuickSort(v, 0, N-1);

	printf("\nVettore ordinato:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);

	int a = 4;
	printf("\nIl valore %d si trova in posizione %d  (soluzione ricorsiva)", a, BinSearchRec(v, 0, N - 1, a));

	printf("\nIl valore %d si trova in posizione %d  (soluzione iterativa)", a, BinSearch(v, 0, N - 1, a));

	//a = 1;
	a = 7;
	printf("\nIl valore %d si trova in posizione %d  (soluzione ricorsiva)", a, BinSearchRec(v, 0, N - 1, a));

	printf("\nIl valore %d si trova in posizione %d  (soluzione iterativa)", a, BinSearch(v, 0, N - 1, a));

	printf("\nIl lower bound %d si trova in posizione %d  (soluzione iterativa)", a, lower_bound(v, 0, N - 1, a));

	printf("\nL'upper bound %d si trova in posizione %d  (soluzione iterativa)", a, upper_bound(v, 0, N - 1, a));
}