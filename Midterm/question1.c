#include <stdio.h>
#include <stdlib.h>
typedef struct FibPair {
    int fn_1;
    int fn_2;
} FibPair;

void init(FibPair *fb) {
    fb->fn_1=0;
    fb->fn_2=1;
}

int calculate(FibPair *fb,int n) {
    if (n == 0) return fb->fn_1; 
    if (n == 1) return fb->fn_2;
    return calculate(fb,n-1) + calculate(fb, n - 2);
}

void display(int n,FibPair *fb) {
    printf("Fibonacci at %d position:%d\n",n,calculate(fb,5));

}
int main() {
    FibPair *fb= (FibPair*)malloc(sizeof(FibPair));;
    init(fb);
    calculate(fb,5);
    display(5,fb);
    free(fb);
}

