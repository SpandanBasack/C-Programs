#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *f=NULL;
struct node *r=NULL;
int isfull()
{
    struct node *n = (struct node*) malloc(sizeof(struct node));
    if(n==NULL)
    return 1;
    else
    return 0;
}
void enqueue(int m)
{
    if(isfull())
    printf("Item cannot be equeued. The queue is full.\n");
    else{
        struct node *n = (struct node*) malloc(sizeof(struct node));
        n->data = m;
        n->next = NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}
int isEmpty()
{
    if(f==NULL)
    return 1;
    else
    return 0;
}
int dequeue()
{
    if(isEmpty)
    {
        printf("No item to be dequeued. Queue is empty.\n");
        return -1;
    }
    else{
        struct node *ptr;
        int n = f->data;
        ptr = f;
        f=f->next;
        free(ptr);
        return n;
    }
}
void main()
{
    struct node *q;
    q = (struct node*) malloc(sizeof(struct node));
    enqueue(3);
    enqueue(3);
    enqueue(3);
    enqueue(3);
    printf("Dequeued element: %d\n",dequeue());
}