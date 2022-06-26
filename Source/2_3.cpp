#include <string>
#include <iostream>
using namespace std;

class Money {
public:
	Money() {
		euros = 0;
		cents = 0;
	}
	int get_euros() {
		return euros;
	}
	void set_euros(int e) {
		euros = e;
	}
	int get_cents() {
		return cents;
	}
	void set_cents(int c) {
		cents = c;
	}
private:
	int euros, cents;
};

Money operator+(Money m1, Money m2) {
	Money mTot;
	int eTot = m1.get_euros() + m2.get_euros();
	int cTot = m1.get_cents() + m2.get_cents();
	if (cTot >= 100) {
		eTot += 1;
		cTot -= 100;
	}
	mTot.set_euros(eTot);
	mTot.set_cents(cTot);
	return mTot;
}

ostream& operator<<(ostream& os, Money m) {
	os << m.get_euros() << "." << m.get_cents() << endl;
	return os;
}

int main() {
	Money m1, m2, m3;
	m1.set_euros(5);
	m1.set_cents(70);
	m2.set_euros(10);
	m2.set_cents(60);

	m3 = m1 + m2;
	cout << m3;
	return 0;
}