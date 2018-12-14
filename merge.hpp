#include <vector>

template<typename T>
void merge(std::vector<T> &vector, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<T> L(n1), R(n2);

	for(int i = 0; i < n1; ++i)
		L[i] = vector[l + 1];
	for(int i = 0; i < n2; ++i)
		R[i] = vector[m + i + 1];

	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2) {
		if (L[i] <= R[j]) vector[k] = L[i], ++i;
		else vector[k] = R[j], ++j;
        ++k;
	}

	while(i < n1) vector[k] = L[i], ++i, ++k;
	while(j < n2) vector[k] = R[j], ++j, ++k;
}

template<typename T>
void merge_sort_helper(std::vector<T> &vector, int l, int r) {
	if(l < r) {
		int m = l + (r-l)/2;

		merge_sort_helper(vector, l, m);
		merge_sort_helper(vector, m+1, r);
		merge(vector, l, m, r);
	}
}

template<typename T>
inline void merge_sort(std::vector<T> &vector) {
	merge_sort_helper(vector, 0, vector.size());
}