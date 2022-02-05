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

TEST_CASE("sparse_matrix can be used as a reversed range") {
	auto sm = sparse_matrix::identity(3);
	const auto reversed = std::vector(sm.rbegin(), sm.rend());
	const auto expected = sm | ranges::views::reverse;

	CHECK(ranges::is_permutation(reversed, expected));
	CHECK(ranges::equal(reversed, expected));
}
