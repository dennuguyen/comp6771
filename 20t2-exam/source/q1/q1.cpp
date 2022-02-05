#include <fstream>
#include <iomanip>
#include <iostream>

#include "q1/q1.hpp"

namespace q1 {
	auto run_calculator(std::string const& filename, std::ostream& os) -> void {
		os.setf(std::ios::fixed, std::ios::floatfield);
		os.precision(3);

		// open the file for reading
		auto in = std::ifstream{};
		in.open(filename);

		// string to be read into
		auto s = std::string{};

		// read the file while we have input.
		while (in >> s) {
			// TODO: Complete this part of the code
			os << "This is the incorrect output. You will want to change this.";
		}
		in.close();
	}
} // namespace q1
