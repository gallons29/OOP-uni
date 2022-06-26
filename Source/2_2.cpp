#include <string>
#include <sstream>
#include <iostream>
using namespace std;

const int N_PERSONE = 3;

class Persona {
public:
	Persona(string n, string c, int a) {
		nome = n;
		cognome = c;
		anni = a;
	}
	string getInformation();
	void setCognome(string c);
private:
	string nome, cognome;
	int anni;
};
string Persona::getInformation() {
	cout << nome.substr(0, 1) << ". " << cognome << ", " << to_string(anni) << endl;
	return nome.substr(0, 1) + ". " + cognome + ", " + to_string(anni);
}
void Persona::setCognome(string c) {
	cognome = c;
}

int main() {
	Persona persona1("Mario", "Rossi", 30);
	Persona persona2("Jerry", "Dance", 25);
	Persona persona3("Carlo", "Cap", 50);

	persona1.getInformation();
	persona2.getInformation();
	persona3.getInformation();

	Persona persone[N_PERSONE] = { persona1, persona2, persona3 };
	for (int i = 0; i < N_PERSONE; i++) {
		persone[i].setCognome("Bianchi");
		persone[i].getInformation();
	}

	return 0;
}