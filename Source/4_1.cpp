#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;


#include "alist.h"
#include "listTest.h"

void insert_ordered(List<Item>& L, const Item& it) {
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
		if (it.key() >= L.getValue().key()) // >= per ordine decrescente
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}

void fondiliste(List<Item>& L1, List<Item>& L2, List<Item>& L3) {
	//faccio due for: uno itera L1 e uno itera L2, e inserisco ordinatamente in L3
	L1.moveToStart();
	L2.moveToStart();
	L3.moveToStart(); // porto i cursori di tutte le liste all'inizio per sicurezza
	
	for (int i = 0; i < L1.length(); i++) {
		insert_ordered(L3, L1.getValue());
		L1.next();
	}

	for (int i = 0; i < L2.length(); i++) {
		insert_ordered(L3, L2.getValue());
		L2.next();
	}
	L3.moveToStart(); //perchè è bello
}

int main() {
	AList<Item> L1;
	AList<Item> L2;
	AList<Item> L3;

	//CREAZIONE L1
	L1.insert(Item(5));
	L1.next();
	L1.insert(Item(1));
	L1.next();
	L1.insert(Item(3));
	L1.next();
	L1.moveToStart();
	cout << "L1: "; lprint(L1);

	//CREAZIONE L2
	L2.insert(Item(10));
	L2.next();
	L2.insert(Item(12));
	L2.next();
	L2.insert(Item(7));
	L2.next();
	L2.insert(Item(2));
	L2.next();
	L2.moveToStart();
	cout << "L2: "; lprint(L2);

	fondiliste(L1, L2, L3);

	cout << "L3: "; lprint(L3);


	return 0;
}