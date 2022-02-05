#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class mult_fixture {
public:
	mult_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~mult_fixture() {
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

TEST_CASE_METHOD(mult_fixture, "multiplying two positive integers") {
	set_input("1 2 mult");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(2 \* 1 = 2\s*)"));
}

TEST_CASE_METHOD(mult_fixture, "doing 2 sequential multiplies of positive integers") {
	set_input("1 2 mult\n"
	          "3 4 mult\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2 \* 1 = 2\s*)"
	                                    R"(4 \* 3 = 12\s*)"));
}

TEST_CASE_METHOD(mult_fixture, "multiplying two doubles together") {
	set_input("1.5 0.1 mult\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(0\.100 \* 1\.500 = 0\.150\s*)"));
}

TEST_CASE_METHOD(mult_fixture, "multiplying ints and doubles together") {
	set_input("3 2.5 mult\n"
	          "10 mult");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2\.500 \* 3 = 7\.500\s*)"
	                                    R"(10 \* 7\.500 = 75\.000\s*)"));
}
