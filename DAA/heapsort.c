#include <stdio.h>

int heapify(int arr[],int n,int i)
{
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if((right < n)&&(arr[right] > arr[largest]))
    {
        largest = right;
    }
    if((left < n)&&(arr[left] > arr[largest]))
    {
        largest = left;
    }
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for(int i = n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i = n-1; i>=0;i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i-1, 0);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = {12, 14, 10, 20, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);

    heapsort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}