#include <stdio.h>

int is_even(int n) {
    return n&1 ? 0 : 1;
    /* Return 0 if the conjunction of n and 1 is 0. Else,
     * the result will be 1 (or -1), and will return true.
     * If the result isn't 0, means the last digit of n is 1,
     * so n is odd.
    */
}

int main() {
    int n;

    scanf("%i", &n);

    printf("%s\n", is_even(n) ? "Even" : "Odd");

    return 0;
}
