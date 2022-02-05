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

TEST_CASE("test empty record serialisation") {
	auto const empty_record = "{\n}\n";
	auto r = record{};
	auto ss = std::stringstream();
	ss << r;
	CHECK(ss.str() == empty_record);
}

TEST_CASE("test non-empty record serialisation") {
	auto r = record{};
	r.set_value("abc", "123");
	r.set_value("def", "456");

	auto expected_lines = std::set<std::string>{"{", "abc=123", "def=456", "}"};

	auto const expected_line_count = expected_lines.size();

	auto ss = std::stringstream();
	ss << r;
	ss.seekg(0);
	auto lines = getlines(ss);
	REQUIRE(expected_line_count == lines.size());
	CHECK(lines[0] == "{");
	CHECK(lines[lines.size() - 1] == "}");
	CHECK(expected_lines == std::set<std::string>(expected_lines.begin(), expected_lines.end()));
}
