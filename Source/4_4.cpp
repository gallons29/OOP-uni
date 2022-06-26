#include <iostream>
#include <cstdlib>
using namespace std;

#include "alist.h"
#include "listTest.h"

void produciaml(AList<Item>& List);

int main() {
	AList<Item> Lista;
	Lista.append(Item(4));
	Lista.append(Item(6));
	Lista.append(Item(2));
	Lista.append(Item(3));
	Lista.append(Item(9));
	lprint(Lista);

	produciaml(Lista);
	lprint(Lista);

	return 0;
}



void produciaml(AList<Item>& List) {
	for (List.moveToPos(List.length() - 1); List.currPos() > 0; List.prev()) {
		Item curr_el = List.getValue();
		int curr_key = curr_el.key();
		List.prev();
		Item prev_el = List.getValue();
		int prev_key = prev_el.key();
		List.next();

		List.remove();
		List.insert(Item(curr_key * prev_key));

	}
}