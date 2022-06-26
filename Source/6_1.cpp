#include <iostream>
#include <time.h>
using namespace std;

#include "alist.h"
#include "listTest.h"

const int N = 10, MINVAL = 1, MAXVAL = 100;

int random(int min, int max) {
	return rand() % (max-min+1) + min;
}

void selectionsort(AList<int>& L) {
	int min_cur = 0;
	for (int sorted_cur = 0; sorted_cur < L.length(); sorted_cur++) {
		int min_temp = MAXVAL + 1; //lo inizializzo a MAXVAL+1 così che sono sicuro che anche se trova il maxval entri nell'if dopo.
		L.moveToPos(sorted_cur);
		for (int i = 0; i < L.length()-sorted_cur; i++) {
			cout << "getvalue: " << L.getValue() << "  mintemp= " << min_temp << endl;
			if (L.getValue() < min_temp) {
				min_temp = L.getValue();
				min_cur = L.currPos();
			}
			if (L.currPos() < L.length()) {
				L.next();
			}
			
		}
		if (min_cur != sorted_cur) {
			L.moveToPos(min_cur);
			int min = L.remove();
			L.moveToPos(sorted_cur);
			int temp = L.remove();
			L.insert(min);
			L.moveToPos(min_cur);
			L.insert(temp);
		}
		cout << "printo lista" << endl;
		lprint(L);
	}
	
}

int main() {
	srand(time(NULL));
	AList<int> L1;
	AList<int> L2;

	for (int i = 0; i < N; i++) {
		L1.append(random(MINVAL, MAXVAL));
		L2.append(random(MINVAL, MAXVAL));
	}
	cout << "Lists generated:" << endl;
	lprint(L1);
	cout << endl;
	lprint(L2);
	cout << endl;


	//Inserimento elementi di L2 in L1
	L2.moveToStart();
	while (L2.length() > 0) {
		L1.append(L2.remove());
	}
	cout << "L2 appended to L1:" << endl;
	lprint(L1);

	selectionsort(L1);
	cout << "Sorted list: " << endl;
	lprint(L1);

	return 0;
}
