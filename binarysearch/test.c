#include<stdlib.h>
#include<stdio.h>
#include"BinarySearch.h"

int main() {
    int a[] = {1, 3, 4, 5, 6, 7, 8, 8, 16, 32, 33, 100};
    int n = 12;
    int x = 8;
    int i = binarysearch(a, n, x);
    printf("%d is at position %d\n",x,i);
}
