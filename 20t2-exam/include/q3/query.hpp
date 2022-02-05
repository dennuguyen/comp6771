#ifndef QUERY_HPP
#define QUERY_HPP

namespace q3 {
	class record;

	class query {
	public:
		virtual ~query() = default;
		[[nodiscard]] auto virtual matches(record const&) const -> bool = 0;
	};

	class query_equals : public query {
	public:
		// query_equals(column, value);
	};

	// class query_less_than
	// class query_greater_than
	// class query_starts_with
	// class query_and
	// class query_or
	// class query_not
} // namespace q3

#endif // QUERY_HPP
