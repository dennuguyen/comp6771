int get_age(); // declaration

int main() { // definition
	auto name = std::string{}; // definition
	name = "Gary Bai";
	std::cout << name << " is " << get_age() << '\n';
	return 0;
}

int get_age() { // definition
	return 38;
}