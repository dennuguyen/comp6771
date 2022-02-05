#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class reverse_fixture {
public:
	reverse_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~reverse_fixture() {
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

TEST_CASE_METHOD(reverse_fixture, "reversing doesn't output anything") {
	set_input("1 1 reverse");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(\s*)"));
}

TEST_CASE_METHOD(reverse_fixture, "reversing operands for an add") {
	set_input("1 2 2 reverse add");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(1 \+ 2 = 3\s*)"));
}

TEST_CASE_METHOD(reverse_fixture, "reversing 3 numbers for 2 sequential operations") {
	set_input("2 5 8 3 reverse add mult");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2 \+ 5 = 7\s*)"
	                                    R"(7 \* 8 = 56\s*)"));
}

TEST_CASE_METHOD(reverse_fixture, "reversing one number doesn't change the following operation") {
	set_input("10 9 1 reverse mult");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(9 \* 10 = 90\s*)"));
}

TEST_CASE_METHOD(reverse_fixture, "reversing zero numbers doesn't do anything") {
	set_input("0 reverse 1 0 reverse 2 0 reverse sub");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(2 - 1 = 1\s*)"));
}

TEST_CASE_METHOD(reverse_fixture, "reversing the stack multiple times") {
	set_input("9 12 2 reverse 2 reverse 2 reverse 2 reverse add");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(12 \+ 9 = 21\s*)"));
}
