#include <algorithm>

// Function Header
template <typename T>
void insertion_sort(T *V, int s_V);

// Function Declaration
template <typename T>
void insertion_sort(T *V, int s_V) {
    for (int i = 1; i < s_V; i++)
        if (*(V+i) <= *(V+i-1)) {
            int j = i;
            while (!(*(V+j) > *(V+j-1))) {
                std::swap(*(V+j), *(V+j-1));
                j--;
            }
        }
}
