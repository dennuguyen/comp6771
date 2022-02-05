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

TEST_CASE("Can input a sparse_matrix according to the correct format") {
	auto is = std::istringstream{"(2, 2, 2)\n"
	                             "(0, 0, 1)\n"
	                             "(1, 1, 1"};
	const auto expected = sparse_matrix<long long>::identity(2);
	auto result = sparse_matrix<long long>(is);

	CHECK(result == expected);
}

TEST_CASE("Can input an empty non-zero dimension sparse_matrix according to the correct format") {
	auto is = std::istringstream{"(2, 2, 0)"};
	const auto expected = sparse_matrix<long long>(2);
	auto result = sparse_matrix<long long>(is);

	CHECK(result == expected);
}

TEST_CASE("Can input an empty 0-dimension sparse_matrix according in the correct format") {
	auto is = std::istringstream{""};
	const auto expected = sparse_matrix<long long>(0);
	auto result = sparse_matrix<long long>(is);

	CHECK(result == expected);
}