#include <stdio.h>
#include <stdlib.h>
struct circular_queue{
    int f;
    int b;
    int *arr;
    int size;
};
int isFull(struct circular_queue *n)
{
    if ((n->b+1)%n->size == n->f)
        return 1;
    else
        return 0;
}
int isEmpty(struct circular_queue *n)
{
    if (n->f == n->b)
        return 1;
    else
        return 0;
}
void enqueue(struct circular_queue *n, int m)
{
    if (isFull(n))
        printf("The circular_queue is Full. The item cannot be enqueued.\n");
    else
    {
        n->b = (n->b+1)%n->size;
        n->arr[n->b] = m;
    }
}
int dequeue(struct circular_queue *n)
{
    int a = 0;
    if (isEmpty(n))
        printf("Cannot dequeue. The circular_queue is empty.");
    else
    {
        a = n->arr[n->f];
        n->f=(n->f+1)%n->size;
    }
    return a;
}
int main()
{
    struct circular_queue *q;
    q = (struct circular_queue *)malloc(sizeof(struct circular_queue));
    q->f = q->b = 0;
    q->size = 5;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 10);
    enqueue(q, 10);
    enqueue(q, 10);
    enqueue(q, 10);
    enqueue(q, 10);
    if(isEmpty(q))
    printf("The circular_queue is Empty.\n");
    else
    printf("The circular_queue is not Empty.\n");
}