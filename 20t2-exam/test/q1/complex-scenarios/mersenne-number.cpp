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

TEST_CASE_METHOD(test_fixture, "program for calculating 3rd and 20th mersenne numbers") {
  set_input("2 2 mult\n"
            "1\n"
            "2 reverse\n"
            "sub\n"
            "1\n"
            "19 repeat\n"
            "2 mult\n"
            "endrepeat\n"
            "1\n"
            "2 reverse\n"
            "sub");

  auto output_sstrm = std::stringstream{};
  q1::run_calculator(filename, output_sstrm);

  CHECK_THAT(output_sstrm.str(), Catch::Matchers::Matches(
    R"(2 \* 2 = 4\s*)"
    R"(4 - 1 = 3\s*)"
    R"(2 \* 1 = 2\s*)"
    R"(2 \* 2 = 4\s*)"
    R"(2 \* 4 = 8\s*)"
    R"(2 \* 8 = 16\s*)"
    R"(2 \* 16 = 32\s*)"
    R"(2 \* 32 = 64\s*)"
    R"(2 \* 64 = 128\s*)"
    R"(2 \* 128 = 256\s*)"
    R"(2 \* 256 = 512\s*)"
    R"(2 \* 512 = 1024\s*)"
    R"(2 \* 1024 = 2048\s*)"
    R"(2 \* 2048 = 4096\s*)"
    R"(2 \* 4096 = 8192\s*)"
    R"(2 \* 8192 = 16384\s*)"
    R"(2 \* 16384 = 32768\s*)"
    R"(2 \* 32768 = 65536\s*)"
    R"(2 \* 65536 = 131072\s*)"
    R"(2 \* 131072 = 262144\s*)"
    R"(2 \* 262144 = 524288\s*)"
    R"(524288 - 1 = 524287\s*)"
  ));
}