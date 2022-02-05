#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class sub_fixture {
public:
	sub_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~sub_fixture() {
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

TEST_CASE_METHOD(sub_fixture, "subtracting two positive integers") {
	set_input("1 2 sub");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(2 - 1 = 1\s*)"));
}

TEST_CASE_METHOD(sub_fixture, "doing 2 sequential subtractions of positive integers") {
	set_input("1 2 sub\n"
	          "3 8 sub\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2 - 1 = 1\s*)"
	                                    R"(8 - 3 = 5\s*)"));
}

TEST_CASE_METHOD(sub_fixture, "subtracting two doubles") {
	set_input("1.5 3.1 sub\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(3\.100 - 1\.500 = 1\.600\s*)"));
}

TEST_CASE_METHOD(sub_fixture, "subtracting ints and doubles together") {
	set_input("1 2.5 sub\n"
	          "10 sub");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2\.500 - 1 = 1\.500\s*)"
	                                    R"(10 - 1\.500 = 8\.500\s*)"));
}

TEST_CASE_METHOD(sub_fixture, "subtracting where the result is negative") {
	set_input("3 0 sub\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(0 - 3 = -3\s*)"));
}