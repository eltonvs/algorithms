#include <algorithm>

// Function Header
template <typename T>
void bubble_sort(T *V, int s_V);

// Function Declaration
template <typename T>
void bubble_sort(T *V, int s_V) {
    for (int i = 0, a = 1; i < s_V && a; i++, a = 0)
        for (int j = 0; j < s_V-i; j++)
            if (*(V+j-1) > *(V+j)) {
                a = 1;
                std::swap(*(V+j-1), *(V+j));
            }
}
