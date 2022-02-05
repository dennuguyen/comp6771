#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class add_fixture {
public:
	add_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~add_fixture() {
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

TEST_CASE_METHOD(add_fixture, "adding two positive integers") {
	set_input("1 2 add");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(2 \+ 1 = 3\s*)"));
}

TEST_CASE_METHOD(add_fixture, "doing 2 sequential adds of positive integers") {
	set_input("1 2 add\n"
	          "3 4 add\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2 \+ 1 = 3\s*)"
	                                    R"(4 \+ 3 = 7\s*)"));
}

TEST_CASE_METHOD(add_fixture, "adding two doubles together") {
	set_input("1.5 3.1 add\n");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(3\.100 \+ 1\.500 = 4\.600\s*)"));
}

TEST_CASE_METHOD(add_fixture, "adding ints and doubles together") {
	set_input("1 2.5 add\n"
	          "10 add");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(2\.500 \+ 1 = 3\.500\s*)"
	                                    R"(10 \+ 3\.500 = 13\.500\s*)"));
}
