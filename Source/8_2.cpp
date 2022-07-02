#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "8_1-heap.h"

int main() {
	int costo = 0;
	const int L = 4;
	int len[L] = { 4, 3, 2, 6 };
	
	MinHeapPQ<int> albero(L);
	for (int i = 0; i < L; i++) {
		albero.insert(len[i]);
	}
	int somma = 0;
	while (!albero.empty()) {
		int minUno = albero.getmin();
		//cout << "minuno: " << minUno << endl;
		if (!albero.empty()) {
			int minDue = albero.getmin();
			//cout << "Mindue: " << minDue << endl;
			somma = minUno + minDue;
			costo += somma;
			//cout << "COsto: " << costo << " somma " << somma << endl;
			albero.insert(somma);
		}
		
	}
	
	cout << costo << endl;


	return 0;
}