#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class sqrt_fixture {
public:
	sqrt_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~sqrt_fixture() {
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

TEST_CASE_METHOD(sqrt_fixture, "square root of positive integer") {
	set_input("4 sqrt");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(sqrt 4 = 2\.000\s*)"));
}

TEST_CASE_METHOD(sqrt_fixture, "square root of positive double") {
	set_input("0.9 sqrt");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(sqrt 0\.900 = 0\.949\s*)"));
}

TEST_CASE_METHOD(sqrt_fixture, "sequential square roots") {
	set_input("0.9 sqrt sqrt");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(),
	           Catch::Matchers::Matches(R"(sqrt 0\.900 = 0\.949\s*)"
	                                    R"(sqrt 0\.949 = 0\.974\s*)"));
}