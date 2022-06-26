#include <assert.h>
#include <iostream>
using namespace std;


template<class T> class Pair {
private:
	T first;
	T second;
public:
	Pair() {
		
	}
	Pair(T f, T s) {
		first = f;
		second = s;
	}
	void set_element(int position, T value) {
		assert(position == 1 || position == 2);
		if (position == 1) {
			first = value;
		}
		else if (position == 2) {
			second = value;
		}
	}

	T get_element(int position) {
		assert(position == 1 || position == 2);
		if (position == 1) {
			return first;
		}
		else if (position == 2) {
			return second;
		}
	}

	void add_up(const Pair<T>& the_pair) {
		first += the_pair.first;
		second += the_pair.second;
	}
};