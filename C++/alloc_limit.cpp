#include <iostream>

#define BIG_NUMBER 100  // A big number to be used as i in 2^i

int main(int argc, char const *argv[]) {
    long int *V;  // The vector
    unsigned long int e = 1;  // The result of 2^i
    bool cont = true;  // The var to decide if the loop continues or not

    for (int i = 0; i < BIG_NUMBER && cont; i++) {
        // Show a status message
        std::cout << ">>> Trying to allocate memory with 2^" << i << "...\n\n";

        try {
            // Try to allocate vector
            V = new long int[e];
        } catch(std::bad_alloc &err) {
            // Show error message
            std::cerr << ">>>! Error: " << err.what() << std::endl;
            // Show the maximum
            std::cout << ">>>! The maximum value is 2^" << i-1 << std::endl;
            // Set cont as false (stops the loop)
            cont = false;
        }

        // Increase e by 2 times himself
        e *= 2;
    }

    // Delete V (remove allocated memory)
    delete[] V;

    // Show a Exiting message
    std::cout << "\n>>> Exiting..." << std::endl << std::endl;

    return EXIT_SUCCESS;
}
