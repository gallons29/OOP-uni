#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "7_2-binary_tree.h"

int main() {

	BinaryTree<Item>* alberoUno = new BinaryTree<Item>;
	alberoUno->AddItem(Item(25));
	alberoUno->AddItem(Item(3));
	alberoUno->AddItem(Item(5));
	alberoUno->AddItem(Item(28));
	alberoUno->AddItem(Item(2));

	alberoUno->traverse();
	cout << endl;

	BinaryTree<Item>* alberoDue = new BinaryTree<Item>;
	alberoDue->AddItem(Item(70));
	alberoDue->AddItem(Item(7));
	alberoDue->AddItem(Item(18));
	alberoDue->AddItem(Item(72));
	alberoDue->AddItem(Item(5));

	alberoDue->traverse();
	cout << endl;

	if (alberoUno->equal_tree_structure(alberoDue->root)) {
		cout << "Struttura uguale\n";
	}
	else {
		cout << "Struttura non uguale\n";
	}




	return 0;
}