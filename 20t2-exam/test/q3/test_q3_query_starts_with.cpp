#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>

using namespace q3;

TEST_CASE("test query_starts_with - empty case") {
	auto q = query_starts_with("abc", "");

	auto r1 = record{};
	r1.set_value("abc", "123");

	CHECK(q.matches(r1));
}

TEST_CASE("test query_starts_with - true case") {
	auto q = query_starts_with("abc", "1");

	auto r1 = record{};
	r1.set_value("abc", "123");

	CHECK(q.matches(r1));
}

TEST_CASE("test query_starts_with - false case") {
	auto q = query_equals("abc", "123");

	auto r1 = record{};
	r1.set_value("abc", "1");

	CHECK_FALSE(q.matches(r1));
}

TEST_CASE("test query_starts_with - missing") {
	auto q = query_equals("abc", "123");

	auto r1 = record{};
	r1.set_value("def", "123");

	CHECK_FALSE(q.matches(r1));
}
