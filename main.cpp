#include <iostream>
#include <chrono>

#include "generator.hpp"
#include "bubble.hpp"

int main() {
	// Generate random test array
	std::vector<int> test(50'000);
	generate(test, 1, 100);

	// Bench bubble sort
	{
		auto bubble = test;
		auto begin {std::chrono::high_resolution_clock::now()};
		bubble_sort(bubble);
		auto end {std::chrono::high_resolution_clock::now()};

		std::cout << "Bubble sort time: "
			<< std::chrono::duration<double, std::milli>{end - begin}.count()
			<< "ms" << std::endl;
	}

	return 0;
}
