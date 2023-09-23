
#include <stdio.h>

int binarysearch(int x, int v[], int n){
    
    int lo = 0, hi = n, mid = 0;

    while (lo < hi){
        mid = (lo + hi) / 2;

        if (v[mid]==x) return mid;
        
        if (x < v[mid]){
            hi = mid;
        } else if (x > v[mid]) {
            lo = mid + 1;
        }
        printf("%d %d %d\n", lo, mid, hi);
    }
    return -1;
}

int binarysearch2(int x, int v[], int n){
    
    int lo = 0, hi = n-1, mid = 0;

    while (lo <= hi){
        mid = lo + (hi - lo) / 2;

        if (v[mid] == x) return mid;
        
        if (x < v[mid]){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        printf("%d %d %d\n", lo, mid, hi);
    }
    return -1;
}


int main(void){

    int a[] = {1,2,3,5,6,7};
    printf("%d", binarysearch(7, a, 6));
    printf("\n");
    printf("%d", binarysearch2(7, a, 6));
    getchar();getchar();
}