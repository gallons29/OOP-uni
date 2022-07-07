#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <fstream>
using namespace std;

bool Find_terno(map<string, set<int>>& lotto, string ruota, int n1, int n2, int n3) {
	set<int> nums = lotto[ruota];

	if (nums.find(n1) != nums.end() && nums.find(n2) != nums.end() && nums.find(n3) != nums.end()) {
		cout << "Ce stiamo" << endl;
		return true;
	}

	cout << "Nun ce stiamo tutti" << endl;
	return false;
}

int main() {
	ifstream file("lotto.txt");
	string nomeRuota;
	int num1, num2, num3, num4, num5;
	
	map<string, set<int>> lotto;

	if (file.is_open()) {
		while (file >> nomeRuota >> num1 >> num2 >> num3 >> num4 >> num5) {
			set<int> temp;
			temp.insert(num1);
			temp.insert(num2);
			temp.insert(num3);
			temp.insert(num4);
			temp.insert(num5);
			lotto.insert(pair<string, set<int>>(nomeRuota, temp));
		}
	}

	Find_terno(lotto, "Firenze", 11, 12, 13);
	Find_terno(lotto, "Milano", 46, 84, 3);

	return 0;
}