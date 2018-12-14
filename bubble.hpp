#include <vector>
#include <utility>

template<typename T>
void bubble_sort(std::vector<T> &vector) {
	bool swapped;
	int n = vector.size();

	for(int i = 0; i < n-1; ++i) {
		swapped = false;
		for(int j = 0; j < n-i-1; ++j) {
			if (vector[j] > vector[j+1]) {
				std::swap(vector[j], vector[j+1]);
				swapped = true;
			}
		}

		if(!swapped) break;
	}
}