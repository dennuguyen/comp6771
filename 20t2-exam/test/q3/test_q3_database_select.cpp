#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>
#include <set>
#include <sstream>
#include <string>

using namespace q3;

TEST_CASE("test empty database select") {
	auto d = database{};
	auto result = d.select(query_equals("abc", "123"));
	CHECK(result.count() == 0);
}

TEST_CASE("test database select one row ignore other") {
	auto d = database{};
	auto r1 = record{};
	auto r2 = record{};

	r1.set_value("abc", "123");
	r2.set_value("def", "456");

	d.insert(r1);
	d.insert(r2);
	auto result = d.select(query_equals("abc", "123"));

	CHECK(result.count() == 1);
}
