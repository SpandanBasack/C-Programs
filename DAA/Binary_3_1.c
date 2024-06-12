#include <stdio.h>
#include <stdlib.h>
int binarySearch(int *arr, int left, int right, int key);
int comparisons=0;
int main()
{
    int n=0, k=0;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    int *arr = (int*) malloc(n* sizeof(int));
    printf("Enter the elements of the array:\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to be searched:\n");
    scanf("%d", &k);
    int index = binarySearch(arr, 0, n, k);
    printf("%d found at index location %d\n", k, index);
    printf("Number of comparisons: %d", comparisons);
    free(arr);
    return 0;
}
int binarySearch(int *arr, int left, int right, int key)
{
    int mid = (left+right)/2;
    comparisons = comparisons+1;
    if(key == arr[mid])
    {
         return mid;
    }
    else if(key>mid){
        return binarySearch(arr, mid+1, right, key);
    }
    else{
        return binarySearch(arr, left, mid-1, key);
    }
}