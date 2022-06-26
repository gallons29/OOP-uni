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
using namespace std;

#include "list.h"


// Your basic int type as an object.
class Item {
private:
  int val;
public:
  Item(int input=0) { val = input; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return val; }

  bool operator> (Item It2) {
      return (val > It2.key());
  }
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

void insertionsort(List<Item>& L) {
    int n = L.length();
    int k = 1;

    for (int i = 1; i < n; i++) {

        L.moveToPos(k);
        Item elemDaSortare = L.getValue();
        L.remove();
        int cursor = k; //valore a caso
        L.prev();
        Item confronto = L.getValue();

        while(elemDaSortare > confronto && cursor > 0) {
            //cout << elemDaSortare.key() << " > " << confronto.key() << "? Si" << endl;
            
            cursor--;
            L.prev();
            //lprint(L);
            confronto = L.getValue();
            
        }

        //cout << elemDaSortare.key() << " -> " << cursor << endl;
        L.moveToPos(cursor);
        L.insert(elemDaSortare);
        k++;
        //lprint(L);
    }
}

#endif

