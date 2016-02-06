#include <iostream>

using namespace std;

int binary_search(int x, int f, int l, int *v) {
	int m = (l + f)/2;

	return f >= l ? -1 : v[m] > x ? binary_search(x, f, m, v) : v[m] < x ? binary_search(x, m+1, l, v) : m;
}

int main(int argc, char const *argv[]) {
	// Your code here

	return EXIT_SUCCESS;
}