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

TEST_CASE_METHOD(test_fixture, "constant arity (non-variadic) operators scenario 1") {
  set_input("2 3.0 sub\n"
            "sqrt\n"
            "8.5 div\n"
            "120 3 mult\n"
            "pop\n"
            "7.5 add\n"
            "sqrt\n"
            "sqrt");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(3\.000 - 2 = 1\.000\s*)"
    R"(sqrt 1\.000 = 1\.000\s*)"
    R"(8\.500 / 1\.000 = 8\.500\s*)"
    R"(3 \* 120 = 360\s*)"
    R"(7\.500 \+ 8\.500 = 16\.000\s*)"
    R"(sqrt 16\.000 = 4\.000\s*)"
    R"(sqrt 4\.000 = 2\.000\s*)"
  ));
}