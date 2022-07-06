#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

#include "9_3-bst.h"

int main() {
	ifstream fileA("parteA.txt");
	ifstream fileB("parteB.txt");

	int matricola, voto;
	string fullName, email, matricolaS, votoS;

	BST<Item, Key> bst1;
	BST<Item, Key> bst2;

	if (fileA.is_open()) {
		while (getline(fileA, matricolaS, ',')) {
			matricola = stoi(matricolaS);
			getline(fileA, fullName, ',');
			getline(fileA, votoS, ',');
			if (votoS == "INSUFFICIENTE") {
				voto = 0;
			}
			else {
				voto = stoi(votoS);
			}
			getline(fileA, email);
			
			bst1.insert(Item(matricola, fullName, email, voto));

		}
	}

	if (fileB.is_open()) {
		while (getline(fileB, matricolaS, ',')) {
			matricola = stoi(matricolaS);
			getline(fileB, fullName, ',');
			getline(fileB, votoS, ',');
			if (votoS == "INSUFFICIENTE") {
				voto = 0;
			}
			else {
				voto = stoi(votoS);
			}
			getline(fileB, email);

			bst2.insert(Item(matricola, fullName, email, voto));

		}
	}


	bst1.balance();
	bst2.balance();
	cout << "PUNTO 1\n";
	bst1.show(cout);
	bst2.show(cout);
	cout << "\n\n\n\n";

	bst1.attraversamento(bst2);

	return 0;
}