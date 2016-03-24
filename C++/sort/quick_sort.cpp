#include <algorithm>

template <typename T>
bool compare(T a, T b) {
    return a < b;
}

template <typename T>
int divide(T *V, int l, int r, bool (*comp)(T, T) = compare) {
    // i to iterate vector and j gets the final position of the pivot
    int i = l, j = l;
    while (i < r) {
        // Separate vector with comp() condition
        if (comp(*(V+i), *(V+r)))
            std::swap(*(V+i), *(V+j++));
        i++;
    }
    // put the pivot on your final position
    std::swap(*(V+r), *(V+j));

    // Return the pivot position
    return j;
}

template <typename T>
void quick_sort(T *V, int l, int r, bool (*comp)(T, T) = compare) {
    // Verify base case (a vector with 1 element is already sorted)
    if (r > l) {
        // Call function to partition vector and get the pivot element
        int k = divide(V, l, r, comp);
        // Divide & Conquer: call quicksort again to sort the extremities
        quick_sort(V, 0, k-1, comp);
        quick_sort(V, k+1, r, comp);
    }
}
