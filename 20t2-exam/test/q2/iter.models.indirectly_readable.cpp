#include <catch2/catch.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator.hpp>
#include <range/v3/iterator/concepts.hpp>
#include <range/v3/view.hpp>

#include "q2/q2.hpp"

using sparse_matrix = q2::sparse_matrix<long long>;

using concepts::same_as;
using ranges::common_tuple;
using ranges::iter_reference_t;
using ranges::iter_value_t;

using expected_value_type = common_tuple<std::size_t, std::size_t, long long>;
using expected_reference = common_tuple<std::size_t, std::size_t, const long long&>;

TEST_CASE("Iterator abstractly models indirectly readable") {
	CHECK(ranges::readable<sparse_matrix::iterator>);
}

TEST_CASE("models std::indirectly_readable") {
	auto sm = sparse_matrix::identity(2);

	CHECK(same_as<iter_value_t<decltype(std::declval<sparse_matrix>().end())>, expected_value_type>);
	CHECK(same_as<iter_reference_t<decltype(std::declval<sparse_matrix>().end())>, expected_reference>);
	CHECK(expected_reference{0, 0, 1ll} == *sm.begin());
}
