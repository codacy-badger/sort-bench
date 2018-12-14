#include <iostream>
#include <chrono>

#include "generator.hpp"
#include "bubble.hpp"

template<typename T, class sort_func>
void bench(std::vector<T> vector, sort_func sort) {
	auto begin {std::chrono::high_resolution_clock::now()};
	bubble_sort(bubble);
	auto end {std::chrono::high_resolution_clock::now()};

	std::cout << "Bubble sort time: "
		<< std::chrono::duration<double, std::milli>{end - begin}.count()
		<< "ms" << std::endl;
}

int main() {
	// Generate random test array
	std::vector<int> test(50'000);
	generate(test, 1, 100);

	// Bench bubble sort
	bench(test, bubble_sort<int>);

	return 0;
}
