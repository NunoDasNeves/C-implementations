/* MergeSort.h
 * My Merge Sort implementation
 * by Nuno Das Neves
 */

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
void mergesort(int a[], int n);
