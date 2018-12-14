#include <vector>
#include <algorithm>
#include <random>

inline void generate(std::vector<int> &vector, int min, int max) {
    // Setup random generator
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	std::generate(vector.begin(), vector.end(), [&]() { return dis(gen); });
}

inline void generate(std::vector<double> &vector, double min, double max) {
    // Setup random generator
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<> dis(min, max);

	std::generate(vector.begin(), vector.end(), [&]() { return dis(gen); });
}