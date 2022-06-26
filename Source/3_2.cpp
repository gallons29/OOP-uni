#include <iostream>
using namespace std;

template <typename T> T most_common(T* A, int size) {
	int common_item = A[0];
	int common_freq = 0;
	int temp = 0;
	for (int i = 0; i < size; i++) {
		temp = 0;
		for (int j = 0; j < size; j++) {
			if (A[i] == A[j]) {
				temp++;
			}
		}
		if (temp > common_freq) {
			common_item = A[i];
			common_freq = temp;
		}
	}

	return common_item;
}

int main() {
	const int size = 6;
	int prova[size] = { 3, 4, 2, 4, 3, 5 };
	int massimo = most_common(prova, size);
	cout << "Maximl: " << massimo << endl;
	return 0;
}