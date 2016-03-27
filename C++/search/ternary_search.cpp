int ter_search_r(int x, int *v, int l, int r) {
    int m1 = (r+l+l)/3, m2 = (r+r+l)/3;

    return (l > r) ? -1 :
        x == *(v+m1) ? m1 :
            x == *(v+m2) ? m2 :
                x > *(v+m2) ? ter_search_r(x, v, m2+1, r) :
                    x < *(v+m1) ? ter_search_r(x, v, l, m1-1) :
                        ter_search_r(x, v, m1+1, m2-1);
}

int ter_search_i(int x, int *v, int l, int r) {
    while (l <= r) {
        int m1 = (r+l+l)/3, m2 = (r+r+l)/3;
        if (*(v+m1) == x)
            return m1;
        else if (*(v+m2) == x)
            return m2;
        else if (x > *(v+m2))
            l = m2+1;
        else if (x < *(v+m1))
            r = m1-1;
        else
            l = m1+1, r = m2-1;
    }

    return -1;
}
