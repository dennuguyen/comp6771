#ifndef DATABASE_HPP
#define DATABASE_HPP

namespace q2 {
	class database {
	public:
		database() = default;
		~database() = default;

		auto insert(record const& r) -> void {

		}

		auto count() const -> std::size_t {
			return 0;
		}

		friend auto operator<<(std::ostream& os, database const& g) -> std::ostream& {
			return os;
		}
		friend auto operator>>(std::istream& is, database& sm) -> std::istream& {

			return is;
		}
		auto delete_matching(query const& q) -> std::size_t {
			return std::size_t{0};
		}
		auto select(query const& q) const -> database {
			database n;
			return n;
		}
	private:
		std::vector<record> records_;
	};

} // namespace q2

#endif // DATABASE_HPP
