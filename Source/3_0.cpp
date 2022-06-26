#include <iostream>
using namespace std;

class mobile {
public:
	mobile() {
		altezza = 0;
		larghezza = 0;
	}
	void set_altezza(int a) {
		altezza = a;
	}
	void set_larghezza(int l) {
		larghezza = l;
	}
	int get_altezza() {
		return altezza;
	}
	int get_larghezza() {
		return larghezza;
	}
private:
	int altezza;
	int larghezza;
};

class armadio : public mobile {
public:
	armadio() {
		numero_ante = 0;
	}
	void set_ante(int a) {
		numero_ante = a;
	}
	int get_ante() {
		return numero_ante;
	}
private:
	int numero_ante;
};

int main() {
	armadio armadillo;
	armadillo.set_altezza(45);
	armadillo.set_larghezza(20);
	armadillo.set_ante(5);

	cout << "Altezza: " << armadillo.get_altezza() << endl;
	cout << "Larghezza: " << armadillo.get_larghezza() << endl;
	cout << "Numero ante: " << armadillo.get_ante() << endl;
	return 0;
}