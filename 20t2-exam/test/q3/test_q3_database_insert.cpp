#include "q3/database.hpp"
#include "q3/query.hpp"
#include "q3/record.hpp"
#include <catch2/catch.hpp>

using namespace q3;

TEST_CASE("test database insert") {
	auto d = database{};
	CHECK(d.count() == 0);
	d.insert(record{});
	CHECK(d.count() == 1);
	d.insert(record{});
	CHECK(d.count() == 2);
}
