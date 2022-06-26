#include <iostream>
#include <cstdlib>
using namespace std;

#include "alist.h"
#include "listTest.h"

int main() {
	const int N = 4;

	AList<Item> arr[N];
	//creazione liste:
	arr[0].append(Item(34));
	arr[0].append(Item(68));
	arr[0].append(Item(23));
	
	arr[1].append(Item(12));
	arr[1].append(Item(156));
	arr[1].append(Item(14));
	arr[1].append(Item(56));
	
	arr[2].append(Item(76));
	arr[2].append(Item(52));
	arr[2].append(Item(4));
	
	arr[3].append(Item(40));
	arr[3].append(Item(41));
	arr[3].append(Item(42));

	int g_max = 0;
	int i_wmax;

	for (int i = 0; i < N; i++) {
		arr[i].moveToStart();

		for (int j = 0; j < arr[i].length(); j++) {
			Item el = arr[i].getValue();
			if (el.key() > g_max) {
				g_max = el.key();
				i_wmax = i;
			}
			arr[i].next();
		}

	}

	cout << "Il massimo si trova alla lista ad indice " << i_wmax << endl;

	return 0;
}