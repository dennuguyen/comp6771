#include <catch2/catch.hpp>
#include <initializer_list>
#include <iterator>
#include <range/v3/algorithm.hpp>
#include <sstream>
#include <type_traits>

// have to do this because idiot Simon did not add public methods to access the private data
// member
// NOLINTNEXTLINE
#define private public

#include "q2/q2.hpp"

// don't need to mess around with macros anymore (but the damage has been done...)
#undef private
using namespace q2;

TEST_CASE("vals_ exists") {
	using required_t = std::unique_ptr<int[]>;
	if constexpr (!std::is_same_v<decltype(std::declval<sparse_matrix<int>>().vals_), required_t>) {
		CHECK(false);
	}
	CHECK(true);
}

TEST_CASE("cidx_ exists") {
	using required_t = std::unique_ptr<std::size_t[]>;
	if constexpr (!std::is_same_v<decltype(std::declval<sparse_matrix<int>>().cidx_), required_t>) {
		CHECK(false);
	}
	CHECK(true);
}

TEST_CASE("ridx_ exists") {
	using required_t = std::map<std::size_t, std::pair<std::size_t, std::size_t>>;
	if constexpr (!std::is_same_v<decltype(std::declval<sparse_matrix<int>>().ridx_), required_t>) {
		CHECK(false);
	}
	CHECK(true);
}

TEST_CASE("Static data member matrix_count_ tracks ref. count of ctors and dtors"
          "(implicitly also tests ~sparse_matrix, but this is fairly unimportant") {
	if constexpr (!std::is_same_v<decltype(std::declval<sparse_matrix<int>>().matrix_count_), std::size_t>)
	{
		CHECK(false);
	}

	auto sm = sparse_matrix<long long>::identity(3);
	CHECK(sm.matrix_count_ == 1);
	{
		auto will_soon_die = sm;
		CHECK(will_soon_die.matrix_count_ == 2);
		CHECK(sm.matrix_count_ == 2);
	}
	CHECK(sm.matrix_count_ == 1);
}
