#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

int main() {

	list<int> nums;
	nums.push_back(1);
	nums.push_back(22);
	nums.push_back(4);
	nums.push_back(31);
	nums.push_back(4);
	nums.push_back(13);

	for (list<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;

	list<int>::iterator it = nums.begin();
	it++;
	it = nums.insert(it, 5);
	it++;
	nums.insert(it, 15);

	for (list<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;

	return 0;
}