#ifndef QUERY_HPP
#define QUERY_HPP

namespace q2 {
	class record;

	class query {
	public:
		virtual ~query() = default;
		[[nodiscard]] auto virtual matches(record const&) const -> bool = 0;
	};

	class query_equals : public query {
	public:
		query_equals(std::string attr, std::string value) {}
		auto matches(const record& r) const -> bool override {
			return false;
		}
		auto clone() const -> query_equals* override {
			return new query_equals("", "");
		}
	};

	// class query_less_than
	// class query_greater_than
	// class query_starts_with
	// class query_and
	// class query_or
	// class query_not
} // namespace q2

#endif // QUERY_HPP
