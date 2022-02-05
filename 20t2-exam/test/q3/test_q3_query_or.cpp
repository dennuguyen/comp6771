#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>

using namespace q3;

TEST_CASE("test query_or - true true case") {
	auto subq = query_equals("abc", "123");
	auto q = query_or(subq, subq);

	auto r1 = record{};
	r1.set_value("abc", "123");

	CHECK(q.matches(r1));
}

TEST_CASE("test query_or - true false case") {
	auto subq1 = query_equals("abc", "123");
	auto subq2 = query_equals("abc", "456");
	auto q = query_or(subq1, subq2);

	auto r1 = record{};
	r1.set_value("abc", "123");

	CHECK(q.matches(r1));
}

TEST_CASE("test query_or - fa;se true case") {
	auto subq1 = query_equals("abc", "456");
	auto subq2 = query_equals("abc", "123");
	auto q = query_or(subq1, subq2);

	auto r1 = record{};
	r1.set_value("abc", "123");

	CHECK(q.matches(r1));
}

TEST_CASE("test query_or - false false case") {
	auto subq1 = query_equals("abc", "456");
	auto subq2 = query_equals("abc", "456");
	auto q = query_or(subq1, subq2);

	auto r1 = record{};
	r1.set_value("abc", "123");

	CHECK_FALSE(q.matches(r1));
}
