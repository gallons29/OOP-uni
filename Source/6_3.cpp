#include <iostream>
using namespace std;

#include "alist.h"
#include "6_3-listTest.h"

int main() {

	AList<Item> Listega;

	Listega.append(Item(2));
	Listega.append(Item(4));
	Listega.append(Item(3));
	Listega.append(Item(1));
	Listega.append(Item(6));
	Listega.append(Item(5));
	Listega.append(Item(7));
	Listega.append(Item(23));

	lprint(Listega);

	//SORTIAML
	insertionsort(Listega);
	lprint(Listega);

	return 0;
}