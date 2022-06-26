#include <iostream>
#include <cstdlib>
using namespace std;

#include "AStackTest.h"
#include "astack.h"
#include "link.h"

int main() {
	AStack<int> stemp;
	const int N = 10;
	

	for (int i = 0; i < N; i++) {
		if (i <= 1) {
			stemp.push(1); //inizializzo il fibo
			cout << stemp.topValue() << "\t";
		}
		else {
			//poppo, addo il popped col top value (risultato), pusho il popped e pusho il risultato
			int popped = stemp.pop();
			int temp = popped + stemp.topValue();
			stemp.push(popped);
			stemp.push(temp);
			cout << temp << "\t";
		}
	}

	return 0;
}