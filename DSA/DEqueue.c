#include <stdio.h>
#include <stdlib.h>
struct queue{
    int *arr;
    int f;
    int r;
    int size;
};
int isFull(struct queue *q)
{
    if((q->f==-1)&&(q->r==q->size))
    return 1;
    else
    return 0;
}
int isEmpty(struct queue *q)
{
    if((q->f==q->r))
    return 1;
    else
    return 0;
}
void enqueueR(struct queue *q, int n)
{
    if(isFull(q))
    {
        printf("The item cannot be enqueued. Queue is Full.");
    }
    else{
    q->r++;
    int *ptr = q->arr;
    for(int i =0;i<=q->r;i++,ptr++)
    {
       *ptr = n;
    }
    }
}
void enqueueF(struct queue *q, int n)
{
    if(isFull(q))
    {
        printf("The item cannot be enqueued. No space to enqueue.");
    }
    else{
    int *ptr = q->arr;
    for(int i =0;i<=q->f;i++,ptr++)
    {
       *ptr = n;
    }
    q->f--;
    }
}
int dequeueR(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("The item cannot be denqueued. Queue is Empty.");
        return -1;
    }
    else{
    int n=0;
    int *ptr = q->arr;
    for(int i =0;i<q->r;i++)
    {
       ptr++;
    }
    n = *ptr;
    q->r--;
    free(ptr);
    return n;
    }
}
int dequeueQ(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("The item cannot be denqueued. Queue is Empty.");
        return -1;
    }
    else{
    int n=0;
    int *ptr = q->arr;
    for(int i =0;i<=q->f;i++)
    {
       ptr++;
    }
    n = *ptr;
    q->f++;
    free(ptr);
    return n;
    }
}
void main()
{
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    printf("Enter the size of the Queue you want to create:\n");
    scanf("%d",&q->size);
    q->f = q->r = -1;
    q->arr = (int*) malloc(q->size*(sizeof(int)));
    enqueueR(q,3);
    printf("Reverse dequeueing element we get: %d\n",dequeueR(q));   
}