#include<stdlib.h>
#include<stdio.h>
#include"MergeSort.h"

int main() {
    int a[] = {2, 4, 5, 3, 2, 1, 6, 7};
    int n = 8;
    mergesort(a, n);
    int i;
    for (i=0;i<n;++i) printf("%d ",a[i]);
    printf("\n");
}
