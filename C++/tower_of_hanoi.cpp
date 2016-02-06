#include <iostream>

using namespace std;

void move(int n, char from, char to, char other, int *num_movements) {
	if (n == 1) {
		cout << "Move from " << from << " to " << to << endl;
	}else {
		move(n - 1, from, other, to, num_movements);
		cout << "Move from " << from << " to " << to << endl;
		move(n - 1, other, to, from, num_movements);
	}
	(*num_movements)++;
}

int main(int argc, char const *argv[]) {
	int discs, movements = 0;

	// Get discs number
	cout << "Number of discs: ";
	cin >> discs;

	// Call function
	move(discs, 'A', 'C', 'B', &movements);

	// Print number of movements
	cout << movements << " movement" << (movements > 1 ? "s" : "") << " required" << endl;

	return EXIT_SUCCESS;
}