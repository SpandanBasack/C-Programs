#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* left;
    struct node* right;
    int data;
};
struct stack
{
    struct node* arr;
    int top;
    int length;   
};
struct node* createNode(int data)
{
    struct node *k = (struct node *)malloc(sizeof(struct node));
    k->left = NULL;
    k->right = NULL;
    k->data = data;
    return k;
}
int isFull(struct stack* s)
{
    if(s->top == s->length-1)
    return 1;
    else 
    return 0;
}
int isEmpty(struct stack* s)
{
    if(s->top==-1)
    return 1;
    else
    return 0;
}
void push(struct stack* s, struct node* node)
{
    if(isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    else{
    s->top++;
    s->arr[s->top] = node;
    }
}
struct node* pop(struct stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    else{
        struct node* x = s->arr[s->top];
        s->top--;
        return x;
    }
}
int height(struct node* root)
{
    if(root==NULL)
    return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(lheight>rheight)
        return(lheight+1);
        else
        return(rheight+1);
    }
}
void inorder_stack(struct node* node, struct stack* s)
{
    while(node!=NULL)
    {
            push(s,node);
            node = node->left;
    }
}
void inorderNR(struct node* node, struct stack* s)
{
        
        if((node == NULL)&&(isEmpty(s)))
            return;
        else
        {
            while(node!=NULL)
            {
            inorder_stack(node,s);
            node = pop(s);
            printf("%d",node->data);
            node = node->right;
            }
        }
}
int main()
{
    struct node *root, *p2, *p3, *p4, *p5;
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    root = createNode(5); 
    p2 = createNode(2);
    p3 = createNode(1);
    p4 = createNode(3);
    p5 = createNode(4);
    s->length = height(root);
    s->top = -1;
    s->arr = (struct node*) malloc(sizeof(s->length*sizeof(struct node)));
    root->left = p2;
    root->right = p3;
    p2->left = p4;
    p2->right = p5;
    return 0;
}