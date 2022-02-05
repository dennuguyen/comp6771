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

TEST_CASE_METHOD(test_fixture, "arithmetic operators scenario 2") {
  set_input("3 5 sub\n"
            "1.5 8.5 add\n"
            "div\n"
            "1 1 mult\n"
            "add\n"
            "0 sub\n"
            "12.4 1.1 add");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(5 - 3 = 2\s*)"
    R"(8\.500 \+ 1\.500 = 10\.000\s*)"
    R"(10\.000 / 2 = 5\.000\s*)"
    R"(1 \* 1 = 1\s*)"
    R"(1 \+ 5\.000 = 6\.000\s*)"
    R"(0 - 6\.000 = -6\.000\s*)"
    R"(1\.100 \+ 12\.400 = 13\.500\s*)"
  ));
}