#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>
#include <set>
#include <sstream>
#include <string>

using namespace std::literals;
using namespace q3;

auto getlines(std::istream& is) -> std::vector<std::string> {
	auto s = std::string{};
	auto result = std::vector<std::string>{};
	while (std::getline(is, s)) {
		result.push_back(s);
	}
	return result;
}

TEST_CASE("test record escape deserialisation - simple") {
	auto const empty_record = R"({
abc!!=123!!
}
)";
	auto r = record{};
	auto ss = std::stringstream(empty_record);
	ss >> r;

	CHECK(r.count() == 1);
	REQUIRE(r.has_attribute("abc!"));
	CHECK(r.get_value("abc!") == "123!");
}

TEST_CASE("test record escape deserialisation - complicated") {
	auto const empty_record = R"({
abc!==123
}
)";
	auto r = record{};
	auto ss = std::stringstream(empty_record);
	ss >> r;

	CHECK(r.count() == 1);
	REQUIRE(r.has_attribute("abc="));
	CHECK(r.get_value("abc=") == "123");
}

TEST_CASE("test record escape deserialisation - hairy") {
	auto const empty_record = R"({
abc!=!==123
}
)";
	auto r = record{};
	auto ss = std::stringstream(empty_record);
	ss >> r;

	CHECK(r.count() == 1);
	REQUIRE(r.has_attribute("abc=="));
	CHECK(r.get_value("abc==") == "123");
}
