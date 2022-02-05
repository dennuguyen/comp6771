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

TEST_CASE_METHOD(test_fixture, "constant arity (non-variadic) operators scenario 2") {
  set_input("1 2 add pop\n"
            "3 4 sub pop\n"
            "9 10 mult pop\n"
            "2 20 div pop\n"
            "121.0 sqrt pop\n"
            "0 0 add\n"
            "0 add\n"
            "0 sub");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(2 \+ 1 = 3\s*)"
    R"(4 - 3 = 1\s*)"
    R"(10 \* 9 = 90\s*)"
    R"(20 / 2 = 10\s*)"
    R"(sqrt 121\.000 = 11.000\s*)"
    R"(0 \+ 0 = 0\s*)"
    R"(0 \+ 0 = 0\s*)"
    R"(0 - 0 = 0\s*)"
  ));
}