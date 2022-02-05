#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>

using namespace q3;

TEST_CASE("test query_greater_than - true case") {
	auto q = query_greater_than("abc", "1");

	auto r1 = record{};
	r1.set_value("abc", "12");

	CHECK(q.matches(r1));
}

TEST_CASE("test query_greater_than - false case where value is equal") {
	auto q = query_greater_than("abc", "1");

	auto r1 = record{};
	r1.set_value("abc", "1");

	CHECK_FALSE(q.matches(r1));
}

TEST_CASE("test query_greater_than - false case where value is less than") {
	auto q = query_greater_than("abc", "1");

	auto r1 = record{};
	r1.set_value("abc", "0");

	CHECK_FALSE(q.matches(r1));
}

TEST_CASE("test query_greater_than - missing attribute") {
	auto q = query_greater_than("abc", "123");

	auto r1 = record{};
	r1.set_value("def", "456");
	CHECK_FALSE(q.matches(r1));
}
