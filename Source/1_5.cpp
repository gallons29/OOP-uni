#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

float calcolo_area(float* r);

int main() {
	float raggio;
	float area;
	cout << "Inserisci il raggio: ";
	cin >> raggio;

	area = calcolo_area(&raggio);
	cout << "\nL'area del cerchio e': " << area << endl;

	return 0;
}

float calcolo_area(float* r) {
	return (*r) * (*r) * M_PI;
}