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

TEST_CASE("Compound multiplication binds to sparse_matrix&") {
	auto lhs = make_sparse_matrix<long long>(2, 2, {{0, 0, 2}, {1, 1, 2}});
	auto rhs = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});
	const auto expected = make_sparse_matrix<long long>(2, 3, {{0, 0, 2}, {1, 2, 2}});

	lhs *= rhs;

	CHECK(lhs == expected);
}

TEST_CASE("Compound multiplication binds to sparse_matrix&&") {
	auto lhs = make_sparse_matrix<long long>(2, 2, {{0, 0, 2}, {1, 1, 2}});
	const auto expected = make_sparse_matrix<long long>(2, 3, {{0, 0, 2}, {1, 2, 2}});

	lhs *= make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});

	CHECK(lhs == expected);
}

TEST_CASE("Exception is thrown as exepcted") {
	auto lhs = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});
	auto rhs = sparse_matrix<long long>(); // defaults to dim:1

	CHECK_THROWS_MATCHES(lhs *= rhs,
	                     matrix_error,
	                     Catch::Matchers::Message("LHS cols() != RHS rows()"));
}

TEST_CASE("Zeroing elements via multiplication makes the matrix sparse") {
	auto lhs = make_sparse_matrix<long long>(2, 2, {{0, 0, 1}, {1, 2, 1}});
	const auto rhs = make_sparse_matrix<long long>(2, 3, {});
	const auto expected = make_sparse_matrix<long long>(2, 3, {});

	lhs *= rhs;

	CHECK(lhs == expected);
}