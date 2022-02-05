#include <iostream>
#include <string>

int main() {
	std::string str; // length of string is managed for us
	std::getline(std::cin, str);
	std::cout << str << std::endl;
	return 0;
}
