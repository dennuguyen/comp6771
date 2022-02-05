#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>

using namespace q3;

TEST_CASE("test query_not - true case") {
	auto subq = query_equals("abc", "123");
	auto q = query_not(subq);

	auto r1 = record{};
	r1.set_value("abc", "345");

	CHECK(q.matches(r1));
}

TEST_CASE("test query_not - false case") {
	auto subq = query_equals("abc", "123");
	auto q = query_not(subq);

	auto r1 = record{};
	r1.set_value("abc", "123");

	CHECK_FALSE(q.matches(r1));
}
