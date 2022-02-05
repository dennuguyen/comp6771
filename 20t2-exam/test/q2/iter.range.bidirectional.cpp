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

TEST_CASE("sparse_matrix abstractly satisfied ranges::bidirection_range") {
	CHECK(ranges::bidirectional_range<sparse_matrix>);
	CHECK(ranges::bidirectional_range<sparse_matrix const>);
}

TEST_CASE("sparse_matrix actually satisfies ranges::bidirectional_range") {
	auto sm = sparse_matrix::identity(3);
	const auto expected = std::vector<expected_value>{expected_value{0, 0, 1},
	                                                  expected_value{1, 1, 1ll},
	                                                  expected_value{2, 2, 1ll}};

	auto reversed = sm | ranges::views::reverse;
	CHECK(ranges::is_permutation(reversed, expected));
	CHECK(ranges::equal(reversed, expected));
}
