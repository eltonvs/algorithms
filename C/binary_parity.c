#include <stdio.h>

int is_even(int n) {
    return n&1 ? 0 : 1;
}

int main() {
    int n;

    scanf("%i", &n);

    printf("%s\n", is_even(n) ? "Even" : "Odd");

    return 0;
}
