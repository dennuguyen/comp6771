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

TEST_CASE("Able to transpose matrix with elements") {
	auto sm = make_sparse_matrix<long long>(2, 2, {{0, 0, 2}, {1, 0, 2}});
	auto expected = make_sparse_matrix<long long>(2, 2, {{0, 0, 2}, {0, 1, 2}});

	sm.transpose();

	CHECK(sm == expected);
}

TEST_CASE("Able to transpose non-square matrix") {
	auto sm = make_sparse_matrix<long long>(2, 3, {{0, 0, 2}, {1, 0, 2}});
	auto expected = make_sparse_matrix<long long>(3, 2, {{0, 0, 2}, {0, 1, 2}});

	sm.transpose();

	CHECK(sm == expected);
}

TEST_CASE("Transposing a fully sparse matrix does nothing") {
	auto sm = make_sparse_matrix<long long>(2, 2, {});
	auto expected = make_sparse_matrix<long long>(2, 2, {});

	sm.transpose();

	CHECK(sm == expected);
}