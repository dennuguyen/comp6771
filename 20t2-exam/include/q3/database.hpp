#ifndef DATABASE_HPP
#define DATABASE_HPP

namespace q3 {
	class database {
	public:
		// insert - takes a record, always succeeds and returns void
		// count returns size_t
		// operator<< - write out to an ostream
		// operator>> - read in from an istream
		// delete_matching - takes a query and deletes matching records from database
		// select - takes a query and returns a new Database object comprised of matching rows
	};
} // namespace q3

#endif // DATABASE_HPP
