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

TEST_CASE_METHOD(test_fixture, "arithmetic operators scenario 3") {
  set_input("-2 -9 sub\n"
            "-5 -2 add\n"
            "div\n"
            "-1 mult\n"
            "0 add\n"
            "0 sub\n"
            "-1.8 10.0 sub");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(-9 - -2 = -7\s*)"
    R"(-2 \+ -5 = -7\s*)"
    R"(-7 / -7 = 1\s*)"
    R"(-1 \* 1 = -1\s*)"
    R"(0 \+ -1 = -1\s*)"
    R"(0 - -1 = 1\s*)"
    R"(10\.000 - -1\.800 = 11\.800\s*)"
  ));
}