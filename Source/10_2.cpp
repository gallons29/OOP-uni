#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

#include "llist.h"
#include "10_2-listTest.h"

int main() {

	LList<list<Item>> lista_di_liste;
	
	list<Item> lista1;
	lista1.push_back(Item(2));
	lista1.push_back(Item(6));
	lista1.push_back(Item(21));

	list<Item> lista2;
	lista2.push_back(Item(3));
	lista2.push_back(Item(13));
	lista2.push_back(Item(8));
	lista2.push_back(Item(10));
	
	list<Item> lista3;
	lista3.push_back(Item(4));
	lista3.push_back(Item(3));
	lista3.push_back(Item(75));
	lista3.push_back(Item(16));
	lista3.push_back(Item(21));
	
	list<Item> lista4;
	lista4.push_back(Item(11));
	lista4.push_back(Item(6));
	lista4.push_back(Item(19));

	lista_di_liste.append(lista1);
	lista_di_liste.append(lista2);
	lista_di_liste.append(lista3);
	lista_di_liste.append(lista4);

	lista_di_liste.moveToStart();
	int maxKey = lista_di_liste.getValue().front().key();
	//cout << "prova " << maxKey << endl;
	for (int i = 0; i < lista_di_liste.length(); i++) {
		list<Item> ltemp = lista_di_liste.getValue();
		for (list<Item>::iterator it = ltemp.begin(); it != ltemp.end(); it++) {
			if (maxKey < it->key()) {
				maxKey = it->key();
			}
		}
		lista_di_liste.next();
	}

	cout << "maxKey = " << maxKey << endl;

	return 0;
}