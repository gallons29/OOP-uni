#include <iostream>
using namespace std;

template<class T> class Matrix2x2 {
private:
	T matrix[2][2];
public:
	Matrix2x2() { };
	Matrix2x2(T m[2][2]) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				matrix[i][j] = m[i][j];
			}
		}
	};
	void add(Matrix2x2<T> x) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				matrix[i][j] += x.matrix[i][j];
			}
		}
	};
	void print() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
};