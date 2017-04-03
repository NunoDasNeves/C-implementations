/* MergeSort.h
 * My Merge Sort implementation
 * by Nuno Das Neves
 */

#include<stdlib.h>
#include"MergeSort.h"

// Sort an array
// params:
// base - The array to sort
// len - how many elements in the array
// size - how big each element is in bytes
// cmp - a function used for comparing two objects
/*void MergeSort(
        void *base,
        size_t len,
        size_t size,
        signed (*cmp)(const void *, const void *)
        );

*/
#include<stdio.h>
// sort a into b
void merge(int a[],int lo,int mid,int hi,int b[]) {
    int i, j, k;
    for (k=lo, i = lo, j = mid+1; k<hi+1;++k) {
        if(i < mid+1 && (j > hi || a[i] <= a[j])) {
            b[k] = a[i++];
        } else {
            b[k] = a[j++];
        }
    }
}

// sort b into a
void msort(int b[], int lo, int hi, int a[]) {
    if (lo >= hi) return;
    int mid = (hi+lo)/2;
    // swap the b with a at each level; sort a into b
    msort(a, lo, mid, b);
    msort(a, mid+1, hi, b);
    // merge the results from b into a
    merge(b, lo, mid, hi, a);
}

void mergesort(int a[], int n) {
    int *b = (int *)malloc(sizeof(int)*n);
    int i;
    // copy a into b
    for (i=0;i<n;++i) b[i] = a[i];
    // sort b into a;
    msort(b, 0, n-1, a);
    free(b);
}
