#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>
#include <set>
#include <sstream>
#include <string>

using namespace q3;
using namespace std::literals;

auto getlines(std::istream& is) -> std::vector<std::string> {
	auto s = std::string{};
	auto result = std::vector<std::string>{};
	while (std::getline(is, s)) {
		result.push_back(s);
	}
	return result;
}

TEST_CASE("test empty record deserialisation") {
	auto const empty_record = "{\n}\n"s;
	auto r = record{};
	auto ss = std::stringstream(empty_record);
	ss >> r;

	CHECK(r.count() == 0);
}

TEST_CASE("test non-empty record serialisation") {
	auto const empty_record = R"({
abc=123
def=456
}
)";
	auto r = record{};
	auto ss = std::stringstream(empty_record);
	ss >> r;

	CHECK(r.count() == 2);
	CHECK(r.get_value("abc") == "123");
	CHECK(r.get_value("def") == "456");
}
