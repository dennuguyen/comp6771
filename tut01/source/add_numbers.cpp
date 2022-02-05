#include <iostream>

int main() {
	int a;
	int b;
	std::cout << "Please enter two numbers: ";
	if (not(std::cin >> a >> b)) {
		std::cerr << "Something went wrong while reading an integer, bailing...\n";
		return 1;
	}
	std::cout << "Sum: " << a + b << std::endl;
	return 0;
}
