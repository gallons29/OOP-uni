#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "7_1-listTest.h"
#include "7_1-binary_tree.h"

int main() {

	BinaryTree<Item>* myBT = new BinaryTree<Item>;
	myBT->AddItem(Item("carlo"));
	myBT->AddItem(Item("darlo"));
	myBT->AddItem(Item("arlo"));
	myBT->AddItem(Item("zzzzz"));
	myBT->AddItem(Item("acco"));
	myBT->AddItem(Item("arro"));
	myBT->AddItem(Item("corlo"));

	myBT->traverse();

	return 0;
}