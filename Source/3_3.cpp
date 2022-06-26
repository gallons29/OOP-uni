#include <iostream>
using namespace std;

#include "3_3.h"

int main() {
	Pair<int> coppia_int(20, 40);
	Pair<int> coppia_int2(10, 12);
	Pair<float> coppia_float;
	coppia_float.set_element(1, 30.5);
	coppia_float.set_element(2, 50.1);
	cout << "coppia_int 1: " << coppia_int.get_element(1) << "  2: " << coppia_int.get_element(2) << endl;
	cout << "coppia_float 1: " << coppia_float.get_element(1) << "  2: " << coppia_float.get_element(2) << endl;
	coppia_int.add_up(coppia_int2);
	cout << "coppia_int 1: " << coppia_int.get_element(1) << "  2: " << coppia_int.get_element(2) << endl;
	return 0;
}