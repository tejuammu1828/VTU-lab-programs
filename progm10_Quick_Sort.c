 /*
Program 10: Quick Sort

Aim:
Design and implement a C program to sort a given set of n integer elements using Quick Sort and compute its time complexity.
*/
 
 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
int partition(int arr[], int low, int high) { 
int pivot = arr[high], i = low - 1, temp; 
for (int j = low; j < high; j++) { 
if (arr[j] <= pivot) { 
i++; 
temp = arr[i]; 
arr[i] = arr[j]; 
arr[j] = temp; 
} 
} 
arr[high] = arr[i + 1]; 
arr[i + 1] = pivot; 
return i + 1; 
} 
 
void quickSort(int arr[], int low, int high) { 
if (low < high) { 
int pi = partition(arr, low, high); 
quickSort(arr, low, pi - 1); 
quickSort(arr, pi + 1, high); 
} 
} 
 
int main() { 
int k, *sizes, i; 
clock_t start, end; 
 
printf("Enter the number of test cases: "); 
scanf("%d", &k); 
 
sizes = (int *)malloc(k * sizeof(int)); // Allocate memory for sizes 
if (!sizes) return printf("Memory allocation failed.\n"), 1; 
 
printf("Enter %d Element sizes (each must be >= 5000):\n", k); 
for (i = 0; i < k; i++) { 
do { 
printf("Test case %d, Element size: ", i + 1); 
scanf("%d", &sizes[i]); 
if(sizes[i]<5000) 
printf(“Invalid Input\n”); 
} while (sizes[i] < 5000); 
} 
 
srand((unsigned int)time(NULL)); 
for (i = 0; i < k; i++) { 
int *arr = (int *)malloc(sizes[i] * sizeof(int)); // Allocate memory for array 
if (!arr) return printf("Memory allocation failed.\n"), 1; 
for (int j = 0; j < sizes[i]; j++) arr[j] = rand() % 10000; 
start = clock(); 
quickSort(arr, 0, sizes[i] - 1); 
end = clock(); 
double time_taken = (double)(end - start) / CLOCKS_PER_SEC; 
printf("Time taken to sort %d elements: %f seconds\n", sizes[i], time_taken); 
free(arr); 
} 
 
quickSort(sizes, 0, k - 1); // Sort the sizes in ascending order 
printf("\nSorted test case sizes:\n"); 
for (i = 0; i < k; i++) printf("%d ", sizes[i]); 
printf("\n"); 
free(sizes); 
return 0; 
} 
