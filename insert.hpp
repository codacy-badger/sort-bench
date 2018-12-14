#include <vector>

template<typename T>
void insert_sort(std::vector<T> &vector) {
	int n = vector.size(), i, j;

	for(i = 1; i < n; ++i) {
		auto key = vector[i];

		for(j = i - 1; j >= 0 && vector[j] > key; --j)
			vector[j+1] = vector[j];
		
		vector[j+1] = key;
	}
}