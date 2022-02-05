#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class div_fixture {
public:
	div_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~div_fixture() {
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

TEST_CASE_METHOD(div_fixture, "dividing two positive integers") {
	set_input("1 2 div");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(2 / 1 = 2\s*)"));
}

TEST_CASE_METHOD(div_fixture, "doing 2 sequential divisions of positive integers") {
	set_input("1 2 div\n"
	          "3 27 div\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2 / 1 = 2\s*)"
	                                    R"(27 / 3 = 9\s*)"));
}

TEST_CASE_METHOD(div_fixture, "dividing two doubles together") {
	set_input("0.1 1.5 div\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(1\.500 / 0\.100 = 15\.000\s*)"));
}

TEST_CASE_METHOD(div_fixture, "dividing ints and doubles together") {
	set_input("1.5 6 div\n"
	          "10 div");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(6 / 1\.500 = 4\.000\s*)"
	                                    R"(10 / 4\.000 = 2\.500\s*)"));
}

TEST_CASE_METHOD(div_fixture, "dividing ints into a double result") {
	set_input("3 8 div 4 5 div");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(8 / 3 = 2\.667\s*)"
	                                    R"(5 / 4 = 1\.250\s*)"));
}

TEST_CASE_METHOD(div_fixture, "sequential divisions don't lose unecessary precision") {
	set_input("3 8 div 15 div");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(8 / 3 = 2\.667\s*)"
	                                    R"(15 / 2\.667 = 5\.625\s*)"));
}