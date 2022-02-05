#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>

using namespace q3;

TEST_CASE("test record delete attribute") {
	auto r = record{};
	r.set_value("abc", "123");
	r.set_value("def", "456");
	r.delete_attribute("def");
	CHECK(r.has_attribute("abc"));
	CHECK_FALSE(r.has_attribute("def"));
	CHECK(r.count() == 1);
}
