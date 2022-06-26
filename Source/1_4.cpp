#include <iostream>
#include <string>
#include <time.h>
using namespace std;

const int N = 2;

int main() {
	struct tipolibro {
		string titolo;
		string autore;
		int anno;
		int prezzo;
	};

	tipolibro libri[N];
	for (int i = 0; i < N; i++) {
		cout << "Libro #" << i + 1 << "\n";
		cout << "Titolo: ";
		cin >> libri[i].titolo;
		cout << "Autore: ";
		cin >> libri[i].autore;
		cout << "Anno: ";
		cin >> libri[i].anno;
		libri[i].prezzo = 1 + rand() % 201;
		cout << "Prezzo (generato): " << libri[i].prezzo << "\n";
	}

	//Calcolo prezzo medio, maggiore e anno più vecchio
	int media = 0, maggiore = libri[0].prezzo, anno_vecchio = libri[0].anno;
	for (int i = 0; i < N; i++) {
		media += libri[i].prezzo;
		/*if (libri[i].prezzo >= maggiore) {
			maggiore = libri[i].prezzo;
		}*/
		maggiore = libri[i].prezzo >= maggiore ? libri[i].prezzo : maggiore;
		anno_vecchio = libri[i].anno <= anno_vecchio ? libri[i].anno : anno_vecchio;
	}
	media = media / N;

	cout << "Prezzo medio: " << media << "\n";
	cout << "Prezzo maggiore: " << maggiore << "\n";
	cout << "Anno piu' vecchio: " << anno_vecchio << "\n";

	return 0;
}