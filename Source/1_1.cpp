#include <iostream>
using namespace std;

const int N = 5;
void stampa_array(int array[N]);

int main() {
	int a[N];
	int b[N] = { 0, -3, 6, -9, 12 };
	int c[N];
	int d[N];
	cout << "Inserisci i valori di a\n";
	for (int i = 0, j = N-1; (i < N || j >= 0); i++, j--) {
		cout << "Elemento #" << i << " ";
		cin >> a[i];
		c[i] = a[i] + b[j];
		d[i] = a[i] > b[i] ? 1 : a[i] == b[i] ? 0 : -1;
	}

	stampa_array(a);
	stampa_array(b);
	stampa_array(c);
	stampa_array(d);

	return 0;
}

void stampa_array(int array[N]) {
	for (int i = 0; i < N; i++) {
		cout << array[i] << "\t";
	}
	cout << "\n";
}