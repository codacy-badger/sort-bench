#include <iostream>
#include <chrono>

#include "generator.hpp"

int main() {
	// Generate random test array
	std::vector<int> test(50'000);
	generate(test, 1, 100);

	return 0;
}
