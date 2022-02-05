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

TEST_CASE("Can access a non-zero element") {
	const auto sm = sparse_matrix<long long>::identity(2);
	const auto expected = 1;

	CHECK(sm.element(0, 0) == expected);
}

TEST_CASE("Exception thrown as expected") {
	const auto sm = sparse_matrix<long long>::identity(2);

	SECTION("Exception thrown when row is out of bounds") {
		CHECK_THROWS_MATCHES(sm.element(15, 0),
		                     matrix_error,
		                     Catch::Matchers::Message("values are not in bounds"));
	}

	SECTION("Exception thrown when column is out of bounds") {
		CHECK_THROWS_MATCHES(sm.element(0, 15),
		                     matrix_error,
		                     Catch::Matchers::Message("values are not in bounds"));
	}
}

TEST_CASE("A reified element can be accessed") {
	auto sm = sparse_matrix<long long>(2);
	const auto expected = 2;

	sm.element(0, 0, 2);

	CHECK(sm.element(0, 0) == expected);
}
