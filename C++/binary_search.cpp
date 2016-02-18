#include <iostream>

using namespace std;

int bin_search_r(int x, int l, int r, int *v) {
	int m = (r + l)/2;

	return (l > r) ? -1 : *(v+m) > x ? bin_search_r(x, l, m-1, v) : *(v+m) < x ? bin_search_r(x, m+1, r, v) : m;
}

int bin_search_i(int x, int l, int r, int *v) {
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

int main(int argc, char const *argv[]) {
	// Your code here

	return EXIT_SUCCESS;
}