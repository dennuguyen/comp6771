#include <catch2/catch.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator.hpp>
#include <range/v3/view.hpp>
#include <string>
#include <type_traits>
#include <vector>

#include "q2/q2.hpp"

using sparse_matrix = q2::sparse_matrix<long long>;

template<ranges::input_or_output_iterator I, ranges::sentinel_for<I> S>
void check_models_sentinel_for(I first, S last, ranges::iter_difference_t<I> const n) {
	CHECK(ranges::distance(first, last) == n);
}

TEST_CASE("Iterator abstractly could be a sentinel") {
	CHECK(ranges::input_or_output_iterator<sparse_matrix::iterator>);
	CHECK(ranges::sentinel_for<decltype(std::declval<sparse_matrix>().end()), sparse_matrix::iterator>);
}

TEST_CASE("[iterator.concept.sentinel]") {
	auto sm = sparse_matrix::identity(2);
	CHECK(std::distance(sm.begin(), sm.end()) == 2);
}
