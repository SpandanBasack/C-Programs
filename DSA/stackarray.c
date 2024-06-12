#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    return 1;
    else 
    return 0;
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    return 1;
    else 
    return 0;
}
void push(struct stack *ptr, int val)
{
    if(isFull(ptr))
    printf("Stack Overflow. Item cannot be pushed.\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
        printf("Pushed: %d\n",val);
    }
}
int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    printf("Stack Underflow. No item present to be popped.\n");
    else{
        int k = ptr->arr[ptr->top];
        --ptr->top;
        return k;
    }
}
int peek(struct stack *ptr, int i)
{
    if((ptr->top-i+1)<0)
    printf("Invalid Operation\n");
    else{
        return(ptr->arr[ptr->top-i+1]);
    }

}
void main()
{
    struct stack *s;
    s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    push(s,84);
    push(s,37);
    push(s,68);
    push(s,59);
    push(s,24);
    push(s,56);
    push(s,32);
    push(s,78);
    push(s,42);
    push(s,41);
    printf("Popped: %d\n",pop(s));
    for(int j = 1; j<=s->top+1;j++)
    printf("The element at index %d is: %d\n",j,peek(s,j));
}
