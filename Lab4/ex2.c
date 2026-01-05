#include <stdio.h>
int checkPrime(int n) {
    if(n<2) return 0;
    for(int i=2;i<=n/2;i++) {
        if(n%i==0) return 0; 
    } 
    return 1;
}
int list(int n, int arr[]) {
    if(n==1) return 0;
    int size = list(n-1,arr);
    if(checkPrime(n)) {
        arr[size++]=n;
    }
    return size;

}
void sphenic(int n,int size,int arr[]) {
    for(int i=0;i<size-2;i++) {
        for(int j=i+1;j<size-1;j++) {
            for(int k=j+1;k<size;k++) {
                int result = arr[i]*arr[j]*arr[k];
                if(result<=n){
                    printf("%d\n",result);
                    
                }
            }
        }

    }
}
int main() {
    int arr[100];
    int n = 66;

    int size = list(n, arr);
    printf("Sphenic numbers from 1 to %d:\n", n);
    sphenic(n, size,arr);

    return 0;
}