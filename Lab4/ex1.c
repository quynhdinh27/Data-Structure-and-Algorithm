#include <stdio.h>
// input n
// set sum = 0 
// while n>0 do
//     digit = n mod 10
//     sum  = sum + digit
//     n = n/10
// end while
// output sum 

int sumDigit(int n) {
    if (n == 0) {
        return 0;  
    } else {            

    return (n % 10) + sumDigit(n / 10);
    }
}
//Let n be the number of digit, S(n) is the complexity of the algorithm with an n digits number
//The complexity is S(n) = S(n-1) + 4 = 4(n-1) + S(1) ~ O(n)
int main() {
    int n = 12359;
    int result = sumDigit(n);
    printf("Result of sum all digits:%d",result);

}