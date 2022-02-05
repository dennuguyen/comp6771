#include <catch2/catch.hpp>
#include <concepts/concepts.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator.hpp>
#include <range/v3/view.hpp>
#include <string>
#include <type_traits>
#include <vector>

#include "q2/q2.hpp"

using sparse_matrix = q2::sparse_matrix<long long>;
using ranges::common_tuple;
using expected_reference = common_tuple<std::size_t, std::size_t, const long long&>;

TEST_CASE("iterator abstractly models std::weakly_incrementable") {
	CHECK(ranges::weakly_incrementable<sparse_matrix::iterator>);
}

TEST_CASE("iterator actually models std::weakly_incrementable") {
	auto sm = sparse_matrix::identity(2);
	auto i = sm.begin();

	SECTION("[iterator.concept.winc]/13.2 (Part 1)") {
		++i;
		CHECK(expected_reference{1, 1, 1ll} == *i);
	}

	SECTION("[iterator.concept.winc]/13.2 (Part 2)") {
		(void)i++;
		CHECK(expected_reference{1, 1, 1ll} == *i);
	}

	SECTION("[iterator.concept.winc]/13.3") {
		auto const old_address = std::addressof(i);
		CHECK(old_address == std::addressof(++i));
	}
}
