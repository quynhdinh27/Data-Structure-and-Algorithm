#include <stdio.h>
double calPi_recursive(int n) {
    if (n == 0) {
        return 4.0/(4*0 + 1) - 4.0/(4*0 + 3);
    }

    return calPi_recursive(n - 1) + (4.0/(4*n + 1) - 4.0/(4*n + 3));
}

int main() {
    int n = 10;
    double result = calPi_recursive(n);
    printf("Pi when n = %d is: %lf\n", n, result);
    return 0;
}