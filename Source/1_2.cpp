#include <iostream>
using namespace std;

const int G = 31;

void riempi_array(int *array, int size);
void controlla_giorni_uguali(int* array_a, int* array_b, int size);

int main() {
	int persona_a[G];
	int persona_b[G];
	int giorno_temp;

	riempi_array(persona_a, G);
	riempi_array(persona_b, G);

	cout << "Persona A\n";
	do {
		cout << "Inserisci giorno ";
		cin >> giorno_temp;
		//cout << "\n";
		if (giorno_temp < 0 || giorno_temp > 31) {
			cout << "Giorno non valido\n";
		}
		else if (giorno_temp == 0) {
			break;
		}
		else {
			persona_a[giorno_temp] = 1;
		}
	} while (giorno_temp != 0);

	cout << "\n";
	cout << "Persona B\n";
	do {
		cout << "Inserisci giorno ";
		cin >> giorno_temp;
		//cout << "\n";
		if (giorno_temp < 0 || giorno_temp > 31) {
			cout << "Giorno non valido\n";
		}
		else if (giorno_temp == 0) {
			break;
		}
		else {
			persona_b[giorno_temp] = 1;
		}
	} while (giorno_temp != 0);

	controlla_giorni_uguali(persona_a, persona_b, G);


	return 0;
}

void riempi_array(int *array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}


void controlla_giorni_uguali(int* array_a, int* array_b, int size) {
	cout << "\nGiorni disponibili per entrambi: \n";
	for (int i = 0; i < size; i++)
	{
		if (array_a[i] == 1 && array_b[i] == 1) {
			cout << i << "\t";
		}
	}
}




