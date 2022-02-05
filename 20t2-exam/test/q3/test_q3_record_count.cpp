#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>

using namespace q3;

TEST_CASE("test record count") {
	auto r = record{};
	CHECK(r.count() == 0);
	r.set_value("abc", "123");
	CHECK(r.count() == 1);
	r.set_value("def", "456");
	CHECK(r.count() == 2);
	r.set_value("def", "123");
	CHECK(r.count() == 2);
}
