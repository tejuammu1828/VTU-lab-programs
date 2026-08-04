/*
Program 11: Merge Sort

Aim:
Design and implement a C program to sort a given set of n integer elements using Merge Sort and compute its time complexity.
*/
 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <math.h> 
#define MAX_BAR_LENGTH 50 
void merge(int arr[], int l, int m, int r) { 
int i = 0, j = 0, k = l; 
int n1 = m - l + 1, n2 = r - m; 
int L[n1], R[n2]; 
for (i = 0; i < n1; i++) L[i] = arr[l + i]; 
for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j]; 
i = j = 0; 
while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; 
while (i < n1) arr[k++] = L[i++]; 
while (j < n2) arr[k++] = R[j++]; 
} 
void mergeSort(int arr[], int l, int r) { 
if (l < r) { 
int m = (l + r) / 2; 
mergeSort(arr, l, m); 
mergeSort(arr, m + 1, r); 
merge(arr, l, m, r); 
} 
} 
int main() { 
int k, i, *sizes; 
clock_t start, end; 
printf("Enter the number of test cases: "); 
scanf("%d", &k); 
sizes = (int *)malloc(k * sizeof(int)); 
for (i = 0; i < k; i++) { 
do { 
printf("Test case %d, Element size: ", i + 1); 
scanf("%d", &sizes[i]); 
if(sizes[i]<5000) 
printf(“Invalid input\n”); 
} while (sizes[i] < 5000); 
} 
srand((unsigned int)time(NULL)); 
double *times = (double *)malloc(k * sizeof(double)); 
for (i = 0; i < k; i++) { 
int *arr = (int *)malloc(sizes[i] * sizeof(int)); 
for (int j = 0; j < sizes[i]; j++) arr[j] = rand() % 10000; 
start = clock(); 
mergeSort(arr, 0, sizes[i] - 1); 
end = clock(); 
times[i] = (double)(end - start) / CLOCKS_PER_SEC; 
printf("Time taken to sort %d elements: %f seconds\n", sizes[i], times[i]); 
free(arr); 
} 
mergeSort(sizes, 0, k - 1); 
printf("\nSorted test case sizes:\n"); 
for (i = 0; i < k; i++) printf("%d ", sizes[i]); 
free(sizes); 
free(times); 
return 0; 
} 
 
