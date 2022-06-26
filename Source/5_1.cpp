#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> 
using namespace std;

#include "lstack.h"
#include "5_1-LStackTest.h"


int main() {
	LStack<Item> Stack;
	Stack.push(Item(5));
	Stack.push(Item(8));
	Stack.push(Item(3));
	Stack.push(Item(14));
	Stack.push(Item(2));
	
	Lstackprint(Stack);
	cout << endl;
	Reverse(Stack);
	Lstackprint(Stack);


	return 0;
}