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

TEST_CASE_METHOD(test_fixture, "arithmetic operators scenario 1") {
  set_input("0 0 add\n"
            "1 add\n"
            "3 sub\n"
            "2 5 sub\n"
            "sub\n"
            "9 mult\n"
            "18 div\n");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(0 \+ 0 = 0\s*)"
    R"(1 \+ 0 = 1\s*)"
    R"(3 - 1 = 2\s*)"
    R"(5 - 2 = 3\s*)"
    R"(3 - 2 = 1\s*)"
    R"(9 \* 1 = 9\s*)"
    R"(18 / 9 = 2\s*)"
  ));
}