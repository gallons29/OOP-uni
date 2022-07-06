// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
//#include <string>
#include <time.h>  // Used by timing functions
#include <typeinfo>
using namespace std;

#include "list.h"

typedef int Key;
static int maxKey = 1000;

class Item {
private:
	string data;
public:
	Key keydata;
	Item() {
		keydata = maxKey;
	};
	Item(Key k, string d) {
		data = d;
		keydata = k;
	};
	Key key() const {
		return keydata;
	};
	int null() {
		return keydata == maxKey;
	};

	string getdata() const {
		return data;
	};

	void concatenateData(string d) {
		data += d;
	}

	void show(ostream& os = cout) {
		os << keydata << " " << data << endl;
	};

};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
  { return s << i.key(); }
  
// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
  int currpos = L.currPos();

  L.moveToStart();

  cout << "< ";
  int i;
  for (i=0; i<currpos; i++) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << "| ";
  while (L.currPos()<L.length()) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}

void insert_ordered(List<Item>& L, const Item& it) {
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
		if (it.key() < L.getValue().key()) // >= per ordine decrescente
		{
			L.insert(it);
			return;
		}
		if (it.key() == L.getValue().key()) // >= per ordine decrescente
		{
			Item temp = L.getValue();
			temp.concatenateData(it.getdata());
			cout << "ho concatenato id " << temp.key() << " ed è uscito " << temp.getdata() << endl;
			return;
		}
	}
	L.append(it);
}


#endif

