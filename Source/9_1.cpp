#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

#include "9_1-bst.h"

int main() {
	BST<Item, Key> bst1;
	BST<Item, Key> bst2;


	ifstream file("info.dat");
	int id;
	string dato, idS;
	if (file.is_open()) {
		while (getline(file, idS, ' ')) {
			id = stoi(idS);
			getline(file, dato);
			
			bst1.insert(Item(id, dato));

		}
	}

	int inputId = 0;
	string inputDato;
	while (inputId >= 0) {
		cout << "Inserisci id e dato (id negativo per uscire): ";
		cin >> inputId;
		cin >> inputDato;
		//cout << "input id: " << inputId << " dato: " << inputDato;
		if (inputId >= 0) {
			bst2.insert(Item(inputId, inputDato));
		}
	}

	bst1.balance();
	bst2.balance();
	bst1.show(cout);
	bst2.show(cout);

	return 0;
}