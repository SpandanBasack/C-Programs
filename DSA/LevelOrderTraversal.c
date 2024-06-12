#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* left;
    struct node* right;
    int data;
};
void levelprint(struct node* root, int level);
int height(struct node *root);
struct node* createNode(int data)
{
    struct node *k = (struct node *)malloc(sizeof(struct node));
    k->left = NULL;
    k->right = NULL;
    k->data = data;
    return k;
}
void levelrun(struct node* root)
{
    int h = height(root);
    int i;
    for(i =1;i<=h;i++)
    {
        levelprint(root, i);
    }
}
void levelprint(struct node* root, int level)
{
    if(root==NULL)
    return;
    if(level==1)
    printf("%d ", root->data);
    else if(level > 1)
    {
        levelprint(root->left, level-1);
        levelprint(root->right, level -1);
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
    levelrun(root);
    return 0;
}