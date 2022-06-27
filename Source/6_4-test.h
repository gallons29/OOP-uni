#include <iostream>
#include <string>
using namespace std;

class Item {
private:
	string cognome;
	int eta;
	float mediaVoti;

public:
	Item(string c, int e, float v) {
		cognome = c;
		eta = e;
		mediaVoti = v;
	};
	Item() {
		cognome = "";
		eta = 0;
		mediaVoti = 0;
	};

	string getCognome() { return cognome; };
	int getEta() { return eta; };
	float getVoti() { return mediaVoti; };

};

