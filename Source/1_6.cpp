#include <iostream>
using namespace std;

int main() {
	float p_netto;
	float p_finale;
	cout << "Inserisci prezzo netto: ";
	cin >> p_netto;
	p_finale = p_netto;
	if (p_netto > 100) {
		p_finale -= (35 * p_finale / 100);
	}

	p_finale += (22 * p_finale / 100);

	cout << "Prezzo finale: " << p_finale << endl;

	return 0;
}