#include <algorithm>
#include <iostream>
#include <vector>

// generic function approach
template<class T>
void generic_sort(T a, T b, T c) {
	std::vector<T> vec{a, b, c};
	std::sort(vec.begin(), vec.end());
	for (auto const& i : vec) {
		std::cout << i << " ";
	}
}

// overloaded function approach
void sort(int a, int b, int c) {
	std::vector<int> vec{a, b, c};
	std::sort(vec.begin(), vec.end());
	for (auto const& i : vec) {
		std::cout << i << " ";
	}
}

void sort(std::string& a, std::string& b, std::string& c) {
	std::vector<std::string> vec{a, b, c};
	std::sort(vec.begin(), vec.end());
	for (auto const& i : vec) {
		std::cout << i << " ";
	}
}