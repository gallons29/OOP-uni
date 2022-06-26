#include <iostream>
using namespace std;

#include "3_4.h";

int main() {
	int m[2][2] = { {1,2},{3,4} };
	Matrix2x2<int> matrice(m);

	int m2[2][2] = { {5,6}, {7,8} };
	Matrix2x2<int> matrice2(m2);

	matrice.add(matrice2);

	matrice.print();


	return 0;
}