#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* left;
    struct node* right;
    int data;
};
struct node* createNode(int data)
{
    struct node *k = (struct node *)malloc(sizeof(struct node));
    k->left = NULL;
    k->right = NULL;
    k->data = data;
    return k;
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);                
    }
}
int main()
{
    struct node *root, *p2, *p3, *p4, *p5;
    root = createNode(5); 
    p2 = createNode(2);
    p3 = createNode(1);
    p4 = createNode(3);
    p5 = createNode(4);
    root->left = p2;
    root->right = p3;
    p2->left = p4;
    p2->right = p5;
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    return 0;
}