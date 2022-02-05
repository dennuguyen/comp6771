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

TEST_CASE("test record escape serialisation") {
	auto r = record{};
	r.set_value("abc!", "123!");
	r.set_value("def==", "456");

	auto expected_line1 = "abc!!=123!!";
	auto expected_line2 = "def!=!==456";
	auto ss = std::stringstream();
	ss << r;
	ss.seekg(0);
	auto lines = getlines(ss);
	CHECK(std::find(lines.begin(), lines.end(), expected_line1) != lines.end());
	CHECK(std::find(lines.begin(), lines.end(), expected_line2) != lines.end());
}
