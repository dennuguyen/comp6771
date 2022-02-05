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
using ranges::common_tuple;
using expected_reference = common_tuple<std::size_t, std::size_t, const long long&>;

TEST_CASE("Iterator abstractly models std::random_access_iterator") {
	CHECK(ranges::random_access_iterator<sparse_matrix::iterator>);
}

TEST_CASE("Iterator actually models std::random_access_iterator") {
	const auto sm = sparse_matrix::identity(3);

	auto r = sm.begin();
	auto a = r;
	auto b = a;

	SECTION("r += n") {
		r += 2;
		CHECK(r == ++++a);

		r -= 2;
		CHECK(r == b);
	}

	SECTION("r + n / n + r") {
		auto s = r + 2;
		auto t = 2 + r;
		CHECK(s == t);

		s = s + -2;
		t = -2 + t;
		CHECK(s == r);
		CHECK(t == r);
		CHECK(t == s);
	}

	SECTION("r -= n") {
		r++;
		r -= 1;

		CHECK(r == a);
	}

	SECTION("r - n") {
		r++;
		a = r - 1;
		CHECK(a == b);
	}

	SECTION("r[n]") {
		CHECK(r[1] == expected_reference{1, 1, 1ll});
	}

	SECTION("a < b") {
		r += 2;
		b += 1;
		a += 0;

		CHECK(a < b);
		CHECK(!(a < a));
		CHECK(!(b < a));
		CHECK(a < r);
		CHECK(a != b);
	}

	SECTION("a > b") {
		a += 2;
		b += 1;
		r += 0;

		CHECK(a > b);
		CHECK(!(a > a));
		CHECK(!(b > a));
		CHECK(a > r);
		CHECK(a != b);
	}

	SECTION("a >= b") {
		a += 2;
		b += 1;
		CHECK(a >= b);
	}

	SECTION("a <= b") {
		b += 2;
		a += 1;
		CHECK(a <= b);
	}
}
