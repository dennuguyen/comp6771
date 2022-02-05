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

TEST_CASE("Subtraction binds to sparse_matrix&") {
	auto lhs = make_sparse_matrix<long long>(2, 3, {{0, 0, 2}, {1, 2, 2}});
	auto rhs = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});
	const auto expected = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});

	auto result = lhs - rhs;

	CHECK(result == expected);
}

TEST_CASE("Subtration binds to sparse_matrix&&") {
	const auto expected = make_sparse_matrix<long long>(2, 3, {{0, 0, -1}, {1, 2, -1}});

	auto result = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}})
	              - make_sparse_matrix<long long>(2, 3, {{0, 0, 2}, {1, 2, 2}});

	CHECK(result == expected);
}

TEST_CASE("Exception is thrown as exepcted") {
	auto lhs = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});
	auto rhs = sparse_matrix<long long>(); // defaults to dim:1

	CHECK_THROWS_MATCHES(lhs - rhs,
	                     matrix_error,
	                     Catch::Matchers::Message("matrices must have identical dimensions"));
}

TEST_CASE("Zeroing elements via subtraction makes the matrix sparse") {
	auto lhs = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});
	const auto rhs = make_sparse_matrix<long long>(2, 3, {{0, 0, 1}, {1, 2, 1}});
	const auto expected = make_sparse_matrix<long long>(2, 3, {});

	auto result = lhs - rhs;

	CHECK(result == expected);
}

TEST_CASE("Subtracting from a sparse element reifies it") {
	auto lhs = make_sparse_matrix<long long>(2, 2, {});
	auto rhs = sparse_matrix<long long>::identity(2);

	auto result = lhs - rhs;

	CHECK(result == make_sparse_matrix<long long>(2, 2, {{0, 0, -1}, {1, 1, -1}}));
}