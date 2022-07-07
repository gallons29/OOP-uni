#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <queue>
using namespace std;

int main() {
	
	list<queue<int>> lista_di_code;

	queue<int> coda1;
	queue<int> coda2;
	queue<int> coda3;
	queue<int> coda4;
	
	coda1.push(30);
	coda1.push(12);
	coda1.push(1);
	coda1.push(203);
	coda1.push(10);

	coda2.push(7);

	coda3.push(14);
	coda3.push(29);
	coda3.push(45);
	coda3.push(100);

	coda4.push(2);
	coda4.push(13);
	coda4.push(8);

	lista_di_code.push_back(coda1);
	lista_di_code.push_back(coda2);
	lista_di_code.push_back(coda3);
	lista_di_code.push_back(coda4);

	for (list<queue<int>>::iterator it = lista_di_code.begin(); it != --lista_di_code.end(); it++) { //--lista.end è il penultimo
		
		if (it->size() > 0) {
			list<queue<int>>::iterator codasuccessiva = it;
			++codasuccessiva;
			codasuccessiva->push(it->front());
			it->pop();
		}

	}

	for (list<queue<int>>::iterator it = lista_di_code.begin(); it != lista_di_code.end(); it++) {

		while (!it->empty()) {
			cout << it->front() << " ";
			it->pop();
		}
		cout << endl;

	}

	return 0;
}