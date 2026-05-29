#include <stdio.h> #include <stdlib.h> #include <time.h>
// Merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) { int i, j, k;
int n1 = m - l + 1; int n2 = r - m;
// Create temporary arrays int L[n1], R[n2];
// Copy data to temporary arrays L[] and R[] for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
// Merge the temporary arrays back into arr[l..r]
i = 0; // Initial index of first subarray
j = 0; // Initial index of second subarray
k = l; // Initial index of merged subarray while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i]; i++;
} else {
arr[k] = R[j]; j++;
} k++;
}
// Copy the remaining elements of L[], if there are any while (i < n1) {
arr[k] = L[i]; i++;
k++;
}
while (j < n2) {
arr[k] = R[j]; j++;
k++;
}
}
// Merge sort function
void mergeSort(int arr[], int l, int r) { if (l < r) {
// Same as (l+r)/2, but avoids overflow for large l and r int m = l + (r - l) / 2;
// Sort first and second halves mergeSort(arr, l, m); mergeSort(arr, m + 1, r);
// Merge the sorted halves merge(arr, l, m, r);
}
}
// Function to generate random numbers between 0 and 999 int generateRandomNumber() {
return rand() % 1000;
}
int main() {
// Set n value int n = 6000;
// Allocate memory for the array
int* arr = (int*)malloc(n * sizeof(int));
// Generate random elements for the array srand(time(NULL));
printf("Random numbers for n = %d:\n", n); for (int i = 0; i < n; i++) {
arr[i] = generateRandomNumber(); printf("%d ", arr[i]);
}
printf("\n");
clock_t start = clock();
// Perform merge sort mergeSort(arr, 0, n - 1);
// Record the end time clock_t end = clock();
// Calculate the time taken for sorting
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
// Output the time taken to sort for the current value of n
printf("\nTime taken to sort for n = %d: %lf seconds\n\n", n, time_taken);
// Display sorted numbers
printf("Sorted numbers for n = %d:\n", n); for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n\n");
// Free the dynamically allocated memory free(arr);
return 0;
}