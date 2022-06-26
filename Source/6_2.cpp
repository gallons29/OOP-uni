#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "alist.h"
#include "6_2-listTest.h"

int main() {
	ifstream agenda("agenda.txt");
	string cognome, nome;
	int giorno, mese, anno;
	string g, m, a;

	AList<Item> Listona;

	if (agenda.is_open()) {
		while (getline(agenda, nome, ' ')) {
			getline(agenda, cognome, ' ');
			getline(agenda, g, '/');
			istringstream giornale(g);
			giornale >> giorno;
			getline(agenda, m, '/');
			istringstream mesale(m);
			mesale >> mese;
			getline(agenda, a);
			istringstream annale(a);
			annale >> anno;
			//cout << nome << " " << cognome << " " << giorno << "/" << mese << "/" << anno << endl;
			Listona.append(Item(nome, cognome, giorno, mese, anno));
		}
		agenda.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}


	printAgenda(Listona);

	cout << "Sortiamo!!!" << endl;
	Listona.moveToStart();
	Item min_temp;
	Item confronto;
	int min_curr = 0;
	Listona.next();
	int n = Listona.length();
	int k = n;
	for (int j = 0; j < n; j++) {
		min_temp = Listona.getValue();
		for (int i = 0; i < k; i++) { //length-1 perchè un item l'ho già assegnato fuori dal for
			confronto = Listona.getValue();
			if (confronto < min_temp) {
				min_temp = confronto;
				min_curr = Listona.currPos();
			}
			if (Listona.currPos() < k) {
				Listona.next();
			} //problemi col for
		}
		k--;
		min_temp.print();
		Listona.moveToPos(min_curr);
		Listona.remove();
		Listona.moveToStart();
		min_curr = 0;
		/*cout << "Stato Listona" << endl;
		printAgenda(Listona);*/
	}
	



	return 0;
}