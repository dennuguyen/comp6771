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

// Note this is the same as the sample case.
TEST_CASE_METHOD(test_fixture, "a repeat with a reverse inside it") {
  set_input("10 20 sub\n"
             "4 3 add\n"
             "2 mult\n"
             "16.0\n"
             "2 repeat\n"
             "sqrt\n"
             "endrepeat\n"
             "pop\n"
             "2.0\n"
             "mult\n"
             "3 repeat\n"
             "2\n"
             "2 reverse\n"
             "div\n"
             "3 mult\n"
             "endrepeat");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(20 - 10 = 10\s*)"
    R"(3 \+ 4 = 7\s*)"
    R"(2 \* 7 = 14\s*)"
    R"(sqrt 16\.000 = 4\.000\s*)"
    R"(sqrt 4\.000 = 2\.000\s*)"
    R"(2\.000 \* 14 = 28\.000\s*)"
    R"(28\.000 / 2 = 14\.000\s*)"
    R"(3 \* 14\.000 = 42\.000\s*)"
    R"(42\.000 / 2 = 21\.000\s*)"
    R"(3 \* 21\.000 = 63\.000\s*)"
    R"(63\.000 / 2 = 31\.500\s*)"
    R"(3 \* 31\.500 = 94\.500\s*)"
  ));
}