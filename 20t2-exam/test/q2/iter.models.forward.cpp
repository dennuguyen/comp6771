#include <catch2/catch.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator.hpp>
#include <range/v3/view.hpp>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

#include "q2/q2.hpp"

using sparse_matrix = q2::sparse_matrix<long long>;

TEST_CASE("Iterator abstractly models std::forward_iterator") {
	CHECK(ranges::forward_iterator<sparse_matrix::iterator>);
}

TEST_CASE("Iterator actually models std::forward_iterator") {
	const auto sm = sparse_matrix::identity(2);

	auto a = sm.begin();
	auto b = sm.begin();

	SECTION("Default constructed iterators are equality comparable?") {
		auto const i = sparse_matrix::iterator();
		auto const j = sparse_matrix::iterator();
		CHECK(i == j);
		CHECK(ranges::distance(i, j) == 0);
	}

	SECTION("[iterator.concept.forward]/4.1") {
		REQUIRE(a == b);
		CHECK(++a == ++b);
		CHECK(++a == ++b);
		CHECK(++a == ++b);
		CHECK(++a == ++b);
		CHECK(++a == ++b);
		CHECK(++a == ++b);
		CHECK(++a == ++b);
		CHECK(++a == ++b);
	}

	SECTION("[iterator.concept.forward]/4.2") {
		[](auto x) { ++x; }(a);
		CHECK(*a == *b);
	}
}
