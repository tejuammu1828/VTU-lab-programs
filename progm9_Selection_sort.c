 /*
Program 9: Selection Sort

Aim:
Design and implement a C program to sort a given set of n integer elements using Selection Sort and compute its time complexity.
*/
 
 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
void selectionSort(int arr[], int n) { 
int i, j, minIndex, temp; 
for (i = 0; i < n - 1; i++) { 
minIndex = i; 
for (j = i + 1; j < n; j++) { 
if (arr[j] < arr[minIndex]) minIndex = j; 
} 
temp = arr[minIndex]; 
arr[minIndex] = arr[i]; 
arr[i] = temp; 
} 
} 
 
int main() { 
int k, i, j; 
clock_t start, end; 
printf("Enter the number of test cases: "); 
scanf("%d", &k); 
 
// Declare an array to store the sizes of the test cases 
int sizes[k]; 
for (i = 0; i < k; i++) { 
int size; 
do{ 
 
printf("Test case %d, Element size: ", i + 1); 
scanf("%d", &size); 
sizes[i] = size; // Store the size for later printing 
if (sizes[i]<5000) 
printf(“Invalid input\n”); 
}
while(sizes[i]<5000);  
int *arr = (int *)malloc(size * sizeof(int)); 
for (j = 0; j < size; j++) arr[j] = rand() % 10000; 
 
start = clock(); 
selectionSort(arr, size); 
end = clock(); 
 
printf("Time taken to sort %d elements: %.6f seconds\n", size, (double)(end - start) / 
CLOCKS_PER_SEC); 
free(arr); 
} 
selectionSort(sizes, k); 
printf("\nSorted test case sizes:\n"); 
for (i = 0; i < k; i++) { 
printf("%d ", sizes[i]); 
} 
printf("\n"); 
 
return 0; 
}