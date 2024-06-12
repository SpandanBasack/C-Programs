#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int isFull()
{
    struct node *s;
    s = (struct node *)malloc(sizeof(struct node));
    if (s == NULL)
        return 1;
    else
        return 0;
}
int isEmpty(struct node *p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}
struct node *push(struct node *p, int n)
{
    if (isFull())
    {
        printf("Stack Overflow.\n");
        return p;
    }
    else
    {
        struct node *s;
        s = (struct node *)malloc(sizeof(struct node));
        s->next = p;
        s->data = n;
        p = s;
        return p;
    }
}
struct node *pop(struct node *p)
{
    if (isEmpty(p))
        printf("Stack Underflow.\n");
    else
    {
        struct node *n;
        n = p;
        printf("Popped element:%d\n",n->data);
        p = p->next;
        free(n);
        return p;
    }
}
void traverse(struct node* top)
{
    struct node *n = top;
    while(n!=NULL)
    {
        int i =1;
        printf("The element at position %d is: %d\n",i,n->data);
        n=n->next;
        i++;
    }
}
int peek(struct node* p, int k)
{
    struct node* n = p;
    for(int i=0; (i<k-1 && n!=NULL);i++)
    {
        n = n->next;
    }
    if(n!=NULL)
    return n->data;
    else
    return -1;  
}
void main()
{
    struct node *top = NULL;
    int k = 0;
    do
    {
        int n = 0;
        printf("Enter 0 to exit:\n");
        printf("Enter 1 to push:\n");
        printf("Enter 2 to pop:\n");
        printf("Enter 3 to traverse linked list:\n");
        printf("Enter 4 to peek:\n");
        scanf("%d", &n);
        if (n == 0)
            k = 1;
        else if (n == 1)
        {
            int m = 0;
            printf("Enter value to push:\n");
            scanf("%d", &m);
            top = push(top, m);
        }
        else if (n == 2)
        {
            top = pop(top);
        }
        else if(n==3)
        {
            traverse(top);
        }
        else if(n==4)
        {
            int m =0;
            int k =0;
            printf("Enter the index at which you want to peek:\n");
            scanf("%d",&m);
            k = peek(top,m);
            if(k=-1)
            printf("Out of Bounds\n");
            else
            printf("The element at %d is %d.\n",m,k);            
        }
        else
            printf("Wrong Choice. Try again.\n");
    } while (k == 0);
    printf("Process Exited...\n");
}
