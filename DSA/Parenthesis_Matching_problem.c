#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    char arr[];
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
void push(struct stack *ptr, char val)
{
    if(isFull(ptr))
    printf("Stack Overflow cannot push to stack.\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
void pop(struct stack *ptr)
{
    --ptr->top;    
}
int parenthesis(char *p)
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr[s->size];
    for(int i=0;p[i]!='\0';i++)
    {
        if(p[i] == '(')
            push(s,'(');
        else if(p[i] ==')')
            if(isEmpty(s))
            return 0;
            pop(s);
    }
    if(isEmpty(s))
    return 1;
    else
    return 0;
}
void main()
{
    char *c = "2*(3*4";
    if(parenthesis(c))
    printf("The parenthesis of the given expression are matching.\n");
    else
    printf("The parenthesis of the given expression are not matching.\n");
}
