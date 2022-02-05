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

TEST_CASE("Able to set a non-zero element") {
	auto sm = sparse_matrix<long long>::identity(2);
	auto expected = make_sparse_matrix<long long>(2, 2, {{0, 0, 2}, {1, 1, 1}});

	sm.element(0, 0, 2);

	CHECK(sm == expected);
}

TEST_CASE("Able to set a zero element") {
	auto sm = sparse_matrix<long long>(2);
	auto expected = make_sparse_matrix<long long>(2, 2, {{0, 0, 2}});

	sm.element(0, 0, 2);

	CHECK(sm == expected);
}

TEST_CASE("Exception thrown when value is out of bounds") {
	auto sm = sparse_matrix<long long>::identity(2);

	SECTION("Row out of bounds") {
		CHECK_THROWS_MATCHES(sm.element(15, 0, 2),
		                     matrix_error,
		                     Catch::Matchers::Message("values are not in bounds"));
	}

	SECTION("Column out of bounds") {
		CHECK_THROWS_MATCHES(sm.element(0, 15, 2),
		                     matrix_error,
		                     Catch::Matchers::Message("values are not in bounds"));
	}
}