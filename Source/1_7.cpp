#include <cmath>
#include <iostream>
using namespace std;

const float SOGLIA = 0.001;

int main() {
	int n;
	float r = 1;
	
	cout << "Inserisci n: ";
	cin >> n;
	while (n < 0) {
		cout << "n deve essere positivo. Reinserisci n: ";
		cin >> n;
	}

	do{
		r = (r + (n / r)) / 2;
	} while (abs(sqrt(n) - r) > SOGLIA);

	cout << "La radice di " << n << " e' " << r;

	return 0;
}