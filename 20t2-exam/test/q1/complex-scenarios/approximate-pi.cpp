#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class test_fixture {
public:
	test_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~test_fixture() {
		std::filesystem::remove(filename);
	}

protected:
	auto set_input(std::string const& input) {
		auto input_ofstrm = std::ofstream{filename, std::ios::binary};
		input_ofstrm << input;
		input_ofstrm.close();
	}

	std::string filename;
};


// This program uses Viète's formula with 4 iterations to compute an approximation for Pi.
// This is a difficult test, as it requires that no unecessary loss of precision occurs in the
// calculations of square roots. Students who push the 3 decimal place truncated result of their
// calculations to their stack will lose too much precision to get the correct answer.
TEST_CASE_METHOD(test_fixture, "program for computing an approximation of pi using Viète's formula") {
  set_input("0.0\n"
            "4 repeat\n"
            "2 add\n"
            "sqrt\n"
            "endrepeat\n"
            "2 sub\n"
            "sqrt\n"
            "2\n"
            "4 repeat\n"
            "2 mult\n"
            "endrepeat\n"
            "mult");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(2 \+ 0\.000 = 2\.000\s*)"
    R"(sqrt 2\.000 = 1\.414\s*)"
    R"(2 \+ 1\.414 = 3\.414\s*)"
    R"(sqrt 3\.414 = 1\.848\s*)"
    R"(2 \+ 1\.848 = 3\.848\s*)"
    R"(sqrt 3\.848 = 1\.962\s*)"
    R"(2 \+ 1\.962 = 3\.962\s*)"
    R"(sqrt 3\.962 = 1\.990\s*)"
    R"(2 - 1\.990 = 0\.010\s*)"
    R"(sqrt 0\.010 = 0\.098\s*)"
    R"(2 \* 2 = 4\s*)"
    R"(2 \* 4 = 8\s*)"
    R"(2 \* 8 = 16\s*)"
    R"(2 \* 16 = 32\s*)"
    R"(32 \* 0\.098 = 3\.140\s*)"
  ));
}