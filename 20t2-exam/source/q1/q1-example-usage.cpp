#include <iostream>

#include "q1/q1.hpp"

auto main(int, char* argv[]) -> int {
	q1::run_calculator(argv[1], std::cout);
}
