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
using ranges::common_tuple;
using expected_value = common_tuple<std::size_t, std::size_t, long long>;

TEST_CASE("sparse_matrix abstractly satisfies ranges::forward_range") {
	CHECK(ranges::forward_range<sparse_matrix>);
	CHECK(ranges::forward_range<sparse_matrix const>);
}

TEST_CASE("sparse_matrix actually satisfies ranges::forward_range") {
	auto sm = sparse_matrix::identity(3);
	const auto expected = std::vector<expected_value>{expected_value{0, 0, 1},
	                                                  expected_value{1, 1, 1},
	                                                  expected_value{2, 2, 1}};

	CHECK(ranges::is_permutation(sm, expected));
	CHECK(ranges::equal(sm, expected));
}
