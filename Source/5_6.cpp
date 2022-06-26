#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#include "lqueue.h"
#include "5_6-LQueueTest.h"

int oper(int curr);

int main() {
	float u_size;
	cout << "Inserisci il numero di valori che vuoi inserire: ";
	cin >> u_size;
	cout << endl;

	LQueue<Item> Coda;
	for (int i = 0; i < u_size; i++) {
		float user_temp;
		cout << "Inserisci numero float: ";
		cin >> user_temp;
		Coda.enqueue(Item(user_temp));
	}


	int op = 0;
	//op: 1 - somma, 2 - sottrazione, 3 - moltiplicazione, 4 - divisione
	while (u_size > 1) {
		float pre_size = u_size;
		u_size = ceil(u_size / 2);
		cout << "size: " << u_size << endl;
		op = oper(op);
		cout << "operatore: " << op << endl;
		float first;
		for (int i = 0; i < u_size; i++) {
			Item a = Coda.dequeue();
			first = a.key();
			if (int(pre_size) % 2 == 0 || i < (u_size - 1)) {
				Item b = Coda.dequeue();
				float second = b.key();

				switch (op) {
				case 1:
					Coda.enqueue(Item(first + second));
					break;
				case 2:
					Coda.enqueue(Item(first - second));
					break;
				case 3:
					Coda.enqueue(Item(first * second));
					break;
				case 4:
					Coda.enqueue(Item(first / second));
					break;
				}
			}
				
		}
		if (int(pre_size) % 2 != 0) { //vuol dire che era dispari e quindi devo aggiungere l'ultimo elemento da solo
			Coda.enqueue(Item(first));
		}
		Lqueueprint(Coda);
		cout << endl;

	}
	

	return 0;
}

int oper(int curr) {
	return curr < 4 ? curr + 1 : 1;
}