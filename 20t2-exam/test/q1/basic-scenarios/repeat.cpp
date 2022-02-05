#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class repeat_fixture {
public:
	repeat_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~repeat_fixture() {
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

TEST_CASE_METHOD(repeat_fixture, "repeating 2 pushes and a single addition command") {
	set_input("2 repeat\n"
	          "31 4 add\n"
	          "endrepeat");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(4 \+ 31 = 35\s*)"
	                                    R"(4 \+ 31 = 35\s*)"));
}

TEST_CASE_METHOD(repeat_fixture, "repeating a single subtraction command") {
	set_input("1 2 3\n"
	          "2 repeat\n"
	          "sub\n"
	          "endrepeat");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(3 - 2 = 1\s*)"
	                                    R"(1 - 1 = 0\s*)"));
}

TEST_CASE_METHOD(repeat_fixture, "repeating a single number push, then multiplying") {
	set_input("5 repeat\n"
	          "2\n"
	          "endrepeat\n"
	          "mult mult mult mult");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2 \* 2 = 4\s*)"
	                                    R"(4 \* 2 = 8\s*)"
	                                    R"(8 \* 2 = 16\s*)"
	                                    R"(16 \* 2 = 32\s*)"));
}

TEST_CASE_METHOD(repeat_fixture, "repeating with n = 1") {
  set_input("1 repeat 2 8 div endrepeat");

  auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(8 / 2 = 4\s*)"));
}

TEST_CASE_METHOD(repeat_fixture, "repeating with no commands in the repeat body") {
  set_input("10 repeat endrepeat");

  auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(\s*)"));
}