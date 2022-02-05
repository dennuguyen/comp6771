#include "q1/q1.hpp"

#include <catch2/catch.hpp>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

class pop_fixture {
public:
	pop_fixture() {
		filename = std::tmpnam(nullptr);
	}

	~pop_fixture() {
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

TEST_CASE_METHOD(pop_fixture, "popping doesn't output anything") {
	set_input("1 pop");

	auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(\s*)"));
}

TEST_CASE_METHOD(pop_fixture, "popping removes the top member from the stack") {
  set_input("1 2 999 pop add");

  auto output_sstrm = std::stringstream{};
	q1::run_calculator(filename, output_sstrm);

	CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(R"(2 \+ 1 = 3\s*)"));
}