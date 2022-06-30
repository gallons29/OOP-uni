#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#include "list.h"

class Item {
private:
	string cognome;
	int eta;
	float mediaVoti;

public:
	Item(string c, int e, float v) {
		cognome = c;
		eta = e;
		mediaVoti = v;
	};
	Item() {
		cognome = "";
		eta = 0;
		mediaVoti = 0;
	};

	string getCognome() const { return cognome; };
	int getEta() const { return eta; };
	float getVoti() const { return mediaVoti; };
};

inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

template <class Item>
void printListaStudenti(List<Item>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	for (int i = 0; i < L.length(); i++) {
		cout << L.getValue().getCognome() << " " << L.getValue().getVoti() << endl;
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}



#endif