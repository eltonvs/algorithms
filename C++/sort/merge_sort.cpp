template <typename T>
void merge(T *A, T *B, int s_B, T *C, int s_C, bool(*comp)(T, T)) {
    // Create vars to iterate vector
    int i = 0, j = 0, k = 0;
    // Merge values until the smaller vector's size
    while (i < s_B && j < s_C)
        A[k++] = comp(B[i], C[j]) ? B[i++] : C[j++];
    // Copy the remaining values from the biggest vector (only if exists)
    while (i < s_B)
        A[k++] = B[i++];
    while (j < s_C)
        A[k++] = C[j++];
}

template <typename T>
void merge_sort(T *V, int s_V, bool(*comp)(T, T)) {
    // Verify base case (a vector with 1 element is already sorted)
    if (s_V > 1) {
        // Define subvectors' size
        int s_aux1 = s_V/2;
        int s_aux2 = s_V - s_aux1;

        // Create subvectors
        T *aux1, *aux2;
        aux1 = new T[s_aux1];
        aux2 = new T[s_aux2];

        // Copy values to subvectors
        for (int i = 0; i < s_aux1; i++)
            aux1[i] = V[i];
        for (int i = s_aux1; i < s_V; i++)
            aux2[i-s_aux1] = V[i];

        // Sort subvectors
        merge_sort(aux1, s_aux1);
        merge_sort(aux2, s_aux2);

        // Merge sorted subvectors
        merge(V, aux1, s_aux1, aux2, s_aux2, comp);

        // Delete allocated memory
        delete[] aux1;
        delete[] aux2;
    }
}

// Example of a comparation function
template <typename T>
bool cmp(T a, T b) {
    return a < b;
}
