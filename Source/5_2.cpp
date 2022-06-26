#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "5_2-lqueue.h"
#include "LQueueTest.h"


int main() {
	LQueue<int> lista;
	lista.enqueue(5);
	lista.enqueue(7);
	lista.enqueue(2);
	lista.enqueue(18);
	lista.enqueue(11);

	Lqueueprint(lista);
	cout << endl;
	lista.reverse();
	Lqueueprint(lista);

	return 0;
}