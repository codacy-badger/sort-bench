#include <iostream>
#include <chrono>
#include <string_view>

#include "generator.hpp"
#include "bubble.hpp"
#include "insert.hpp"
#include "selection.hpp"
#include "quick.hpp"

template<typename T, class sort_func>
void bench(std::string_view name, std::vector<T> vector, sort_func sort) {
	auto begin {std::chrono::high_resolution_clock::now()};
	bubble_sort(vector);
	auto end {std::chrono::high_resolution_clock::now()};

	std::cout << name << " sort time:\t"
		<< std::chrono::duration<double, std::milli>{end - begin}.count()
		<< "ms" << std::endl;
}

int main() {
	// Generate random test array
	std::vector<int> test(50'000);
	generate(test, 1, 100);

	bench("Bubble", test, bubble_sort<int>);
	bench("Insert", test, insert_sort<int>);
	bench("Selection", test, selection_sort<int>);
	bench("Quick", test, [](std::vector<int> v) { return ::quick_sort(v, last); });

	return 0;
}
