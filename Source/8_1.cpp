#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "8_1-heap.h"

int main() {

	MinHeapPQ<int> pheappega(8);
	//1 2 3 5 6 9 10 14
	pheappega.insert(10);
	pheappega.insert(6);
	pheappega.insert(3);
	pheappega.insert(14);
	pheappega.insert(9);
	pheappega.insert(5);
	pheappega.insert(1);
	pheappega.insert(2);

	for (int i = 0; i < 8; i++) {
		cout << pheappega.getmin() << endl;
	}

	return 0;
}