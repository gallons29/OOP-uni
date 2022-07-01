#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "7_4-binary_tree.h"

int main() {

	BinaryTree<Item>* albero = new BinaryTree<Item>;

	albero->AddItem(Item(30));
	albero->AddItem(Item(64));
	albero->AddItem(Item(23));
	albero->AddItem(Item(21));
	albero->AddItem(Item(55));
	albero->AddItem(Item(90));
	albero->AddItem(Item(31));

	albero->traverse();
	cout << "\nHeight: " << albero->height() << endl;

	//delete albero;


	return 0;
}