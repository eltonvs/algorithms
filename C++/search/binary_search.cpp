int bin_search_r(int x, int l, int r, int *v) {
    // Gets the middle position
    int m = (r + l)/2;

    /*
     * If the left edge exceed the right, stop the program (the element wasn't found)
     * else, if the actual element is bigger than x (to be found), search again, but only on the first-half from vector
     * else, if the actual element is lower than x (to be found), search again, but only on the last-half from vector
     * else, the actual element is equals to x, so return it
     */
    return (l > r) ? -1 :
        *(v+m) > x ? bin_search_r(x, l, m-1, v) :
            *(v+m) < x ? bin_search_r(x, m+1, r, v) : m;
}

int bin_search_i(int x, int *v, int l, int r) {
    while (l <= r) {
        int m = (r + l)/2;
        if (*(v+m) == x)
            return m;
        else if (*(v+m) < x)
            l = m+1;
        else
            r = m-1;
    }

    return -1;
}
