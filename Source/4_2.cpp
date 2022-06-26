#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

#include "alist.h"
#include "4_2-listTest.h"

int ricerca_es(List<Item>& lista, string abbr, string parola) {
	bool parteb = true;
	lista.moveToStart();
	for (int i = 0; i < lista.length(); i++) {
		Item el = lista.getValue();

		//parte a
		if (el.key() == abbr && el.word() == parola) {
			cout << "Returno 0";
			return 0;
		}
		//parte b
		if (el.key() == abbr || el.word() == parola) {
			parteb = false;
		}
		//parte c
		if (el.key() == abbr && el.word() != parola) {
			lista.remove();
			el.set_word(parola);
			lista.insert(el);
			cout << "Returno 2";
			return 2;
		}

		lista.next();
	}
	if (parteb) {
		lista.append(Item(parola, abbr));
		cout << "Returno 1";
		return 1;
	}
}

int main() {
	AList<Item> Listone;
	Listone.append(Item("Milano", "MI"));
	Listone.append(Item("Torino", "TO"));
	Listone.append(Item("Parma", "PR"));
	Listone.append(Item("Rozzano", "RO"));

	ricerca_es(Listone, "RO", "Roma");
	ricerca_es(Listone, "MI", "Milano");
	ricerca_es(Listone, "AL", "Torino");
	ricerca_es(Listone, "GI", "Giacomo");

	return 0;
}