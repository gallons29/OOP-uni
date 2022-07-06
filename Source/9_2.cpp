#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

#include "9_2-bst.h"

int main() {
	ifstream file("telefoni.txt");
	//int numeroTelefono;
	string numeroTS, nomeCognome, ufficio;

	BST<Item, Key> bst1;
	BST<Item, Key> bst2;

	if (file.is_open()) {
		while (getline(file, ufficio, ',')) {
			getline(file, nomeCognome, ',');
			getline(file, numeroTS);

			bst1.insert(Item(nomeCognome, ufficio));
			bst2.insert(Item(numeroTS, nomeCognome));

		}
	}

	bst1.balance();
	bst2.balance();
	bst1.show(cout);
	bst2.show(cout);

	return 0;
}