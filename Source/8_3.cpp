#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "8_3-heap.h"

int main() {
	const int k = 3, n = 4;
	int arr[k][n] = { {1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11} };

	int out[(n*k)];
	MinHeapPQ<Item>* albero = new MinHeapPQ<Item>(k);
	int j = 0;
	for (int i = 0; i < k; i++) {
		albero->insert(Item(arr[i][j], i, j+1));
	}
	for (int i = 0; i < n * k; i++) {
		Item min = albero->getmin();
		out[i] = min.val();
		if (min.next() < n) {
			albero->insert(Item(arr[min.from()][min.next()], min.from(), min.next()+1));
		}
	}

	for (int i = 0; i < n * k; i++) {
		cout << out[i] << " ";
	}
	cout << endl;

	return 0;
}