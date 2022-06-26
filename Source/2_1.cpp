#include <string>
#include <iostream>
using namespace std;

class Libro {
public:
	Libro(string t = "", int p = 0) {
		titolo = t;
		pagine = p;
	}
	void set_titolo(string t);
	void set_pagine(int p);
	void get_titolo();
	void get_pagine();
private:
	string titolo;
	int pagine;
};
void Libro::set_titolo(string t) {
	titolo = t;
}
void Libro::set_pagine(int p) {
	pagine = p;
}
void Libro::get_titolo() {
	cout << "Titolo: " << titolo << endl;
}
void Libro::get_pagine() {
	cout << "Pagine: " << pagine << endl;
}

int main() {
	Libro libro1;
	Libro libro2("prova", 25);
	Libro libro3("tree");
	
	libro3.set_pagine(50);

	libro1.get_pagine();
	libro3.get_titolo();
	libro3.get_pagine();
	return 0;
}