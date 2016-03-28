#include <iostream>

void move(int n, char from, char to, char other, int *num_movements) {
    if (n == 1) {
        // Base Case, just 1 disc, move to destiny
        std::cout << "Move from " << from << " to " << to << std::endl;
    } else {
        // Move all discs (except the base disc) to the auxiliar column (swap)
        move(n - 1, from, other, to, num_movements);
        // Move the base disc to the destination column
        std::cout << "Move from " << from << " to " << to << std::endl;
        // Move the little tower (without base) to destination column (above the base)
        move(n - 1, other, to, from, num_movements);
    }
    // Add 1 movement to total (needs to result in 2^n - 1)
    (*num_movements)++;
}

int main(int argc, char const *argv[]) {
    int discs, movements = 0;

    // Get discs number
    std::cout << "Number of discs: ";
    cin >> discs;

    // Call function
    move(discs, 'A', 'C', 'B', &movements);

    // Print number of movements
    std::cout << movements << " movement"
              << (movements > 1 ? "s" : "") << " required" << std::endl;

    return EXIT_SUCCESS;
}
