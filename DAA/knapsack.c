#include <stdio.h>

int max(int a, int b){
    return (a>b? a: b);
    }

int knapsack(int profit[], int weight[],int W,int n)
{
    if((n==0) || (W==0))
    return 0;
    else if(weight[n-1]>W)
    return knapsack(profit, weight, W, n-1);
    else
    {
        return max(profit[n-1]+knapsack(profit, weight, W - weight[n-1], n-1), knapsack(profit, weight, W, n-1));
    }
}

int main()
{
    int profit[] = {20, 30, 10, 40};
    int weight[] = {35, 60, 50, 100};
    int W = 100;
    int n = sizeof(profit)/sizeof(profit[0]);
    printf("%d", knapsack(profit, weight, W, n));
    return 0;
}