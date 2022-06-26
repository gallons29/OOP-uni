#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

#include "list.h"


// Your basic int type as an object.
class Item {
private:
  string parola;
  string abbr;
public:
  Item(string p="", string a="") {
      parola = p;
      abbr = a;
  }
  
  string key() const {
      return abbr;
  }
  string word() const {
      return parola;
  }
  void set_word(string new_w) {
      parola = new_w;
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
