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

TEST_CASE("Iterator abstractly models std::bidirectional_iterator") {
	CHECK(ranges::bidirectional_iterator<sparse_matrix::iterator>);
}

TEST_CASE("Iterator actually models std::bidirectional_iterator") {
	const auto sm = sparse_matrix::identity(2);

	auto a = ranges::next(sm.begin());
	auto b = a;

	SECTION("[iterator.concept.bidir]/3.1.1") {
		auto const old_address = std::addressof(a);
		CHECK(old_address == std::addressof(--a));
	}

	SECTION("[iterator.concept.bidir]/3.1.2") {
		CHECK(a-- == b);
	}

	SECTION("[iterator.concept.bidir]/3.1.3") {
		a--;
		--b;
		CHECK(a == b);
	}

	SECTION("[iterator.concept.bidir]/3.1.4") {
		CHECK(++(--a) == b);
		CHECK(--(++a) == b);
	}
}
