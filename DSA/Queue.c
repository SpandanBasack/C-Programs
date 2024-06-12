#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int f;
    int b;
    int *arr;
    int size;
};
int isFull(struct queue *n)
{
    if (n->b == (n->size - 1))
        return 1;
    else
        return 0;
}
int isEmpty(struct queue *n)
{
    if (n->f == n->b)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *n, int m)
{
    if (isFull(n))
        printf("The queue is Full. The item cannot be enqueued.");
    else
    {
        n->b++;
        n->arr[n->b] = m;
    }
}
int dequeue(struct queue *n)
{
    int a = 0;
    if (isEmpty(n))
        printf("Cannot dequeue. The queue is empty.");
    else
    {
        a = n->arr[n->f];
        n->f++;
    }
    return a;
}
int main()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->f = q->b = -1;
    q->size = 100;
    q->arr = (int *)malloc(100 * sizeof(int));
    enqueue(q, 10);
    int i = dequeue(q);
    if(isEmpty(q))
    printf("The Queue is Empty.\n");
    else
    printf("The Queue is not Empty.\n");
}