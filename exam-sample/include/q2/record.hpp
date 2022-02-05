#ifndef RECORD_HPP
#define RECORD_HPP

#include <ostream>

namespace q2 {
	class record {
	public:


	public:
		record() {};
		~record() {};
		auto get_value(std::string const& s) const -> std::string {
			(void)s;
			return "";
		}

		auto has_attribute(std::string const& key) const -> bool {
			(void)key;
			return false;
		}
		auto count() const -> std::size_t {
			return 0;
		}

		auto delete_attribute(std::string const& key) -> bool {
			(void)key;
			return false;
		}
		auto set_value(std::string const& key, std::string const& val) -> void {
			(void)key;
			(void)val;
		}
		friend auto operator<<(std::ostream& os, record const& g) -> std::ostream& {
			(void)g;
			return os;
		}
		friend auto operator>>(std::istream& is, record& sm) -> std::istream& {
			(void)sm;
			return is;
		}
	};
} // namespace q2

#endif // RECORD_HPP
