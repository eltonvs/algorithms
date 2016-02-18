#include <iostream>

using namespace std;

int binary_search(int x, int l, int r, int *v) {
	int m = (r + l)/2;

	return (l > r) ? -1 : *(v+m) > x ? binary_search(x, l, m-1, v) : *(v+m) < x ? binary_search(x, m+1, r, v) : m;
}

int main(int argc, char const *argv[]) {
	// Your code here

	return EXIT_SUCCESS;
}