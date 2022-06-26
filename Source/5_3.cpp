#include <iostream>
#include <cstdlib>
using namespace std;

#include "AStackTest.h"
#include "astack.h"
#include "link.h"

int main() {
	AStack<int> stemp;
	const int N = 10;

	for (int i = 1; i <= N; i++) {
		stemp.push(i);
	}


	long int fattoriale = 1;
	for (int i = 1; i <= N; i++) {
		fattoriale *= stemp.pop();
	}

	cout << "Fattoriale di " << N << " = " << fattoriale << endl;

	return 0;
}