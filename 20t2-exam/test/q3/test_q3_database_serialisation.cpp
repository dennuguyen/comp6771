#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>
#include <set>
#include <sstream>
#include <string>

using namespace q3;

// note we only test on empty records here as I don't want errors in record serialisation
// to influence the results of database serialisation.  (e.g. database serialisation could be
// good where there are bugs in record serialisation.)

TEST_CASE("test empty database serialisation") {
	auto d = database{};
	auto ss = std::stringstream();
	ss << d;
	CHECK(ss.str() == "");
}

TEST_CASE("test database serialisation of one empty record") {
	auto d = database{};
	d.insert(record{});
	auto ss = std::stringstream();
	ss << d;
	CHECK(ss.str() == "{\n}\n");
}

TEST_CASE("test database serialisation of two empty records") {
	auto d = database{};
	d.insert(record{});
	d.insert(record{});
	auto ss = std::stringstream();
	ss << d;
	CHECK(ss.str() == "{\n}\n{\n}\n");
}
