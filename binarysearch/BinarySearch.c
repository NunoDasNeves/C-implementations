/* BinarySearch.c
 * My Binary Search implementation
 * by Nuno Das Neves
 */


#include<stdlib.h>
#include<stdio.h>
#include"BinarySearch.h"

int binarysearch(int a[], int n, int x) {
    int lo = 0;
    int hi = n;
    while (lo <= hi) {
        int m  = (hi+lo)/2;
        if (a[m] == x) {
            return m;
        } else if (a[m] > x) {
            hi = m;
        } else {
            lo = m+1;
        }
    }
    return -1;
}

