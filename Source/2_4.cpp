#include <string>
#include <sstream>
#include <fstream>
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
	bool operator != (Persona p2) {
		if (nome != p2.nome || cognome != p2.cognome || anni != p2.anni) {
			return true;
		}
		else {
			return false;
		}
	};
private:
	string nome, cognome;
	int anni;
};
string Persona::getInformation() {
	return nome.substr(0, 1) + ". " + cognome + ", " + to_string(anni);
}
void Persona::setCognome(string c) {
	cognome = c;
}

int main() {
	Persona persona1("Mario", "Rossi", 30);
	//Persona persona2("Jerry", "Dance", 25);
	Persona persona2("Mario", "Rossi", 30);
	ofstream ud("output.txt");
	if (ud.is_open()) {
		if (persona1 != persona2) {
			ud << "DIVERSI";
		}
		else {
			ud << "UGUALI";
		}
		ud.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}

	return 0;
}