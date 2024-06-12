#include <stdio.h>
#include <stdlib.h>
struct item{
    int weight, profit, fraction;
};

int main()
{
    int n = 0;
    printf("Enter the no. of elements:\n");
    scanf("%d", &n);
    item item_array[n];
    for(int i = 0; i<n; i++)
    {
        printf("Enter the weight and profit of the item:\n");
        scanf("%d %d", &item_array[i].weight, &item_array[i].profit);
    }
    for(int i = 0)
    return 0;
}