#include <algorithm>

template <typename T>
void selection_sort(T *V, int s_V);

template <typename T>
void selection_sort(T *V, int s_V) {
    for (int i = 0, m = 0; i < s_V; i++, m = i) {
        for (int j = i+1; j < s_V; j++)
            if (*(V+j) < *(V+m)) m = j;
        std::swap(*(V+i), *(V+m));
    }
}
