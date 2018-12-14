#include <vector>
#include <utility>

const auto last = [](auto v, int l, int h) {
    return v[h];
};

template<typename T, typename P>
auto partition(std::vector<T> &vector, int l, int h, P pivot_f) {
    auto pivot = pivot_f(vector, l, h);
    int i = l - 1;

    for (int j = l; j <= h-1; ++j)
        if(vector[j] <= pivot)
            ++i, std::swap(vector[i], vector[j]);

    std::swap(vector[i+1], vector[h]);
    return (i+1);
}

template<typename T, typename P>
void quick_sort_helper(std::vector<T> &vector, int l, int h, P pivot_f) {
    if (l < h) {
        int p = partition(vector, l, h, pivot_f);

        quick_sort_helper(vector, l, p-1, pivot_f);
        quick_sort_helper(vector, p+1, h, pivot_f);
    }
}

template<typename T, typename P>
inline void quick_sort(std::vector<T> &vector, P pivot_f) {
    quick_sort_helper(vector, 0, vector.size(), pivot_f);
}
