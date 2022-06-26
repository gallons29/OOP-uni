#include <iostream>
using namespace std;

template <class T> T max2(T primo, T secondo) {
	return primo > secondo ? primo : secondo;
}

template <class T> T max3(T primo, T secondo, T terzo) {
	return max2(max2(primo, secondo), terzo);
}

int main() {
	int m1 = max2(2, 4);
	cout << "m1: " << m1 << endl;

	int m2 = max3(34, 22, 25);
	cout << "m2: " << m2 << endl;
	return 0;
}