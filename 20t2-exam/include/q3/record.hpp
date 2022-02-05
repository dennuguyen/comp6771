#ifndef RECORD_HPP
#define RECORD_HPP

#include <ostream>

namespace q3 {
	class record {
	public:
		// get_value takes a string, returns a string
		// set_value takes two strings, return void
		// has_attribute takes a string, return bool
		// count takes no parameters, returns size_t
		// delete_attribute takes a string, return bool
		// operator<< - write out to an ostream
		// operator>> - read in from an istream
		friend auto operator<<(std::ostream& os, record const&) -> std::ostream& {
			return os;
		}
	};
} // namespace q3

#endif // RECORD_HPP
