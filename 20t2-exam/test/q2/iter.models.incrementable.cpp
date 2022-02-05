#include <catch2/catch.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator.hpp>
#include <range/v3/view.hpp>
#include <string>
#include <type_traits>
#include <vector>

#include "q2/q2.hpp"

using sparse_matrix = q2::sparse_matrix<long long>;

TEST_CASE("Iterator abstractly models incrementable") {
	CHECK(ranges::incrementable<sparse_matrix::iterator>);
}

TEST_CASE("Iterator actually models std::incrementable") {
	auto sm = sparse_matrix::identity(2);
	auto a = sm.begin();
	auto b = sm.begin();

	SECTION("[iterator.concept.inc]/2.1") {
		CHECK(a++ == b);
	}

	SECTION("[iterator.concept.inc]/2.2") {
		a++;
		CHECK(a == ++b);

		a++;
		CHECK(a == ++b);
	}
}
