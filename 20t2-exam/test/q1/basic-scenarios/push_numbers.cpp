#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class push_numbers_fixture {
public:
	push_numbers_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~push_numbers_fixture() {
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

TEST_CASE_METHOD(push_numbers_fixture, "pushing space separated positive integers") {
	set_input("1 2 3");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(\s*)"));
}

TEST_CASE_METHOD(push_numbers_fixture, "pushing new line separated positive integers") {
	set_input("1\n"
	          "2\n"
	          "3\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(\s*)"));
}

TEST_CASE_METHOD(push_numbers_fixture,
                 "pushing space and newline separated integers (incl. negative integers)") {
	set_input("-1\n"
	          "0 20 100 -3\n"
	          "1\n"
	          "2\n"
	          "3\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(\s*)"));
}

TEST_CASE_METHOD(push_numbers_fixture,
                 "pushing space and newline separated positive doubles and integers") {
	set_input("1.0 2.0\n"
	          "3.5 1"
	          "2 0");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(\s*)"));
}