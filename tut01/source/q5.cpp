int main() {
	// no issues
	auto i = 3;
	i = 4;

	// decrementing const variable
	auto const j = 5;
	--j;

	// no issue
	auto age = 18;
	auto& my_age = age;
	++my_age;

	// decrementing const variable
	auto agee = 21;
	auto const& my_agee = agee;
	--my_agee;
}