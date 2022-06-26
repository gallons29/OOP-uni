// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"


// Your basic int type as an object.
class Item {
private:
    string cognome, nome;
    int giorno, mese, anno;
public:
  Item(string n, string c, int g, int m, int a) {
      nome = n;
      cognome = c;
      giorno = g;
      mese = m;
      anno = a;
  }
  Item() {
      nome = "";
      cognome = "";
      giorno = 0;
      mese = 0;
      anno = 0;
  }
  string get_cognome() const { return cognome; }
  string get_nome() const { return nome;  }
  int get_giorno() const { return giorno; }
  int get_mese() const { return mese; }
  int get_anno() const { return anno; }

  bool operator<(Item It2) {
      if (cognome < It2.get_cognome()) {
          return true;
      }
      else if (cognome == It2.get_cognome()) {
          if (nome < It2.get_nome()) {
              return true;
          }
          else if (nome == It2.get_nome()) {
              if (anno < It2.get_anno()) {
                  return true;
              }
              else if (anno == It2.get_anno()) {
                  if (mese < It2.get_mese()) {
                      return true;
                  }
                  else if (mese == It2.get_mese()) {
                      if (giorno < It2.get_giorno()) {
                          return true;
                      }
                  }
              }
          }
      }
      return false;
  }

  bool operator==(Item It2) {
      return (cognome == It2.get_cognome() && nome == It2.get_nome() && anno == It2.get_anno() && mese == It2.get_mese() && giorno == It2.get_giorno());
  }

  /*Item operator=(Item It2) {
      cognome = It2.get_cognome();
      nome = It2.get_nome();
      giorno = It2.get_giorno();
      mese = It2.get_mese();
      anno = It2.get_anno();
  }*/

  void print() {
      cout << nome << " " << cognome << " " << giorno << "/" << mese << "/" << anno << endl;
  }
};


// Let us print out Items easily
//inline ostream& operator<<(ostream& s, const Item& i)
//  { return s << i.key(); }
  
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

template <class Item>
void printAgenda(List<Item>& L){
    int currpos = L.currPos();
    L.moveToStart();

    for (int i = 0; i < L.length(); i++) {
        cout << L.getValue().get_nome() << " " << L.getValue().get_cognome() << " " << L.getValue().get_giorno() << "/" << L.getValue().get_mese() << "/" << L.getValue().get_anno() << endl;
        L.next();
    }
    
    cout << "\n";
    L.moveToPos(currpos); // Reset the fence to its original position
}



#endif

