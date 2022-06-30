#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "6_4-test.h"
#include "alist.h"

void mediaVotiSort(Item* stud, int size);

int main() {
	string nString;

	ifstream file("studenti.txt");
	if (file.is_open()) {
		getline(file, nString);
	}
	int N = stoi(nString);
	cout << N << endl;
	Item* studenti = new Item[N];


	string cTemp;
	int eTemp;
	string eS, vS;
	float vTemp;
	int index = 0;
	if (file.is_open()) {
		while (getline(file, cTemp, ' ')) {
			getline(file, eS, ' ');
			eTemp = stoi(eS);
			getline(file, vS);
			vTemp = stof(vS);
			studenti[index] = Item(cTemp, eTemp, vTemp);
			index++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << studenti[i].getCognome() << " " << studenti[i].getEta() << " " << studenti[i].getVoti() << endl;
	}

	int num_scelti, eta_max;
	cout << "Inserisci num_scelti: ";
	cin >> num_scelti;
	cout << "Inserisci eta_max: ";
	cin >> eta_max;

	/*ordinare l’array in modo decrescente secondo la media dei voti(utilizzando un qualsiasi algoritmo)
	viene creata una lista concatenata che contiene i num_scelti studenti con la media più alta che hanno
	un’età strettamente inferiore a eta_max e la stampa a video.Nell’esempio, con num_scelti uguale = 4 ed
	eta_max = 25 la lista deve contenere gli studenti : Viola 30, Blu 28.3, Rosa 27.3 e Neri 25.56*/

	mediaVotiSort(studenti, N);

	for (int i = 0; i < N; i++) {
		cout << studenti[i].getCognome() << " " << studenti[i].getEta() << " " << studenti[i].getVoti() << endl;
	}

	AList<Item> Lista;
	for (int i = 0; i < N && Lista.length() < num_scelti; i++) {
		if (studenti[i].getEta() < eta_max) {
			Lista.append(studenti[i]);
		}
	}

	printListaStudenti(Lista);


	return 0;
}

void mediaVotiSort(Item* stud, int size) {

	for (int i = 0; i < size; i++) {

		Item maxTemp = stud[i];
		for (int j = i; j < size; j++) {
			Item confronto = stud[j];
			if (confronto.getVoti() > maxTemp.getVoti()) {
				stud[i] = confronto;
				stud[j] = maxTemp;
				maxTemp = confronto;
			}
		}

	}

}