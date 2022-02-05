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

TEST_CASE("Iterator abstractly models std::input_iterator") {
	CHECK(ranges::input_iterator<sparse_matrix::iterator>);
}

TEST_CASE("models std::input_iterator") {
	const auto sm = sparse_matrix::identity(2);
	const auto expected =
	   std::vector<std::tuple<std::size_t, std::size_t, long long>>{{0, 0, 1}, {1, 1, 1}};

	CHECK(ranges::equal(sm, expected));
}
