#ifndef Q2_HPP
#define Q2_HPP

#include <concepts/concepts.hpp>
#include <exception>
#include <istream>
#include <map>
#include <memory>
#include <range/v3/utility.hpp>
#include <tuple>
#include <type_traits>

namespace q2 {

	class matrix_error {
		// TODO
	};

	template<typename I = int>
	class sparse_matrix {
	public:
		class iterator {
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type = ranges::common_tuple<std::size_t, std::size_t, I>;
			using difference_type = std::ptrdiff_t;

			iterator() = default;

			// Member functions go here

		private:
			iterator(int /* to be modified by you (int is a stub) */);
		};

		using reverse_iterator = std::reverse_iterator<iterator>;

		static auto identity(std::size_t sz) -> sparse_matrix;

		/*
		 * Must be amortised according to min((m × n) ÷ 5, 1000)
		 */
		sparse_matrix(std::size_t dim = 1) {
			(void)dim; /* Write this body yourself */
		}
		sparse_matrix(std::size_t rows, std::size_t columns);
		sparse_matrix(std::istream& is);

		sparse_matrix(sparse_matrix const& other);
		sparse_matrix(sparse_matrix&& other) noexcept;

		~sparse_matrix() noexcept {}

		auto operator=(sparse_matrix const& other) -> sparse_matrix&;
		auto operator=(sparse_matrix&& other) noexcept -> sparse_matrix&;

		auto operator+=(sparse_matrix const& other) -> sparse_matrix&;
		auto operator-=(sparse_matrix const& other) -> sparse_matrix&;
		auto operator*=(sparse_matrix const& other) -> sparse_matrix&;
		auto operator==(sparse_matrix const& other) const noexcept -> bool;

		friend auto operator+(sparse_matrix const& lhs, sparse_matrix const& rhs) -> sparse_matrix;
		friend auto operator-(sparse_matrix const& lhs, sparse_matrix const& rhs) -> sparse_matrix;
		friend auto operator*(sparse_matrix const& lhs, sparse_matrix const& rhs) -> sparse_matrix;
		friend auto operator<<(std::ostream& os, sparse_matrix const&) -> std::ostream& {
			return os;
		}
		friend auto operator>>(std::istream& is, sparse_matrix& sm) -> std::istream&;
		friend auto transpose(sparse_matrix const& sm) -> sparse_matrix;

		auto rows() const noexcept -> std::size_t;
		auto cols() const noexcept -> std::size_t;
		auto element(std::size_t i, std::size_t j, I val) -> void;
		auto element(std::size_t i, std::size_t j) const -> I const&;
		auto transpose() -> sparse_matrix&;

		auto begin() const -> iterator;
		auto end() const -> iterator;

		auto rbegin() const -> reverse_iterator;
		auto rend() const -> reverse_iterator;

	private:
		std::unique_ptr<I[]> vals_;
		std::unique_ptr<std::size_t[]> cidx_;
		std::map<std::size_t, std::pair<std::size_t, std::size_t>> ridx_;

		static std::size_t matrix_count_;
	};

} // namespace q2

#endif // Q2_HPP
