#include <stdio.h>
int findMax(int a[],int n) {
        int max=0;
    for(int i=0;i<=n-1;i++) {
        if(a[i]>=a[max]) {
            max = i;
        }
    }
     return max;
}
int flip(int a[],int n) {
    for(int i=0; i<=n/2;i++) {
      int temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
}

void sort(int arr[], int n) {
    int size = n;

    while (size > 1) {
        int max = findMax(arr, size);

        if (max != size - 1) {
            if (max != 0) {
                flip(arr, max+ 1);
            }
            flip(arr, size);
        }

        size--;
    }
}
int main() {
    int a[] = {2,3,5,7,9};
    int n=5;
    sort(a,n);
    for(int i=0;i<=n-1;i++){
        printf("%d",a[i]);
    }
    
}