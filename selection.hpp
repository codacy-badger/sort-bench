#include <vector>
#include <utility>

template<typename T>
void selection_sort(std::vector<T> &vector) {
	int n = vector.size();

	for(int i = 0, min_idx; i < n-1; ++i) {
		min_idx = i;
		for(int j = i+1; j < n; ++j)
			if(vector[j] < vector[min_idx])
				min_idx = j;

		std::swap(vector[min_idx], vector[i]);
	}
}