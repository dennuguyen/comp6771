#include <catch2/catch.hpp>
#include <initializer_list>
#include <iterator>
#include <range/v3/algorithm.hpp>
#include <sstream>
#include <type_traits>

#include "q2/q2.hpp"

using namespace q2;

// another constructor we should have put in but didn't
template<typename I>
auto make_sparse_matrix(std::size_t m,
                        std::size_t n,
                        std::initializer_list<std::tuple<std::size_t, std::size_t, I>> init) {
	auto sm = sparse_matrix<I>(m, n);
	ranges::for_each(init, [&sm](const auto& e) {
		const auto& [i, j, v] = e;
		sm.element(i, j, v);
	});

	return sm;
}

TEST_CASE("sparse_matrix(const sparse_matrix&)") {
	const auto expected = make_sparse_matrix<long long>(3, 3, {{0, 0, 1}, {1, 1, 1}, {2, 2, 1}});
	const auto original = make_sparse_matrix<long long>(3, 3, {{0, 0, 1}, {1, 1, 1}, {2, 2, 1}});
	const auto cp = original;

	CHECK(cp == expected);
}