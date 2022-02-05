#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>
#include <set>
#include <sstream>
#include <string>

using namespace q3;

auto getlines(std::istream& is) -> std::vector<std::string> {
	auto s = std::string{};
	auto result = std::vector<std::string>{};
	while (std::getline(is, s)) {
		result.push_back(s);
	}
	return result;
}

TEST_CASE("test empty database deserialisation") {
	auto d = database{};
	auto ss = std::stringstream("");
	ss >> d;

	CHECK(d.count() == 0);
}

TEST_CASE("test database deserialisation - one empty record") {
	auto d = database{};
	auto ss = std::stringstream("{\n}\n");
	ss >> d;

	CHECK(d.count() == 1);
}

TEST_CASE("test database deserialisation - two empty records") {
	auto d = database{};
	auto ss = std::stringstream("{\n}\n{\n}\n");
	ss >> d;

	CHECK(d.count() == 2);
}
