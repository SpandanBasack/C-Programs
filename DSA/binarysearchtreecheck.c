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
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);                
    }
}
int isBst(struct node* root)
{
    static struct node *prev = NULL;
    if(root!=NULL)
    {
        if(!(isBst(root->left)))
        return 0;
        if(prev!=NULL && root->data<=prev->data)
        return 0;
        prev = root;
        return isBst(root->right);        
    }
    else
    return 1;
}
struct node* search(struct node* root, int key)
{
    if(root==NULL)
    return NULL;
    if(root->data == key)
    return root;
    else if(root->data > key)
    return search(root->left,key);
    else
    return search(root->right, key);
}
struct node* searchitr(struct node* root, int key)
{
    while(root!=NULL)
    {
        if(root->data == key)
        return root;
        else if(root->data > key)
        root = root->left;
        else
        root = root->right;
    }
    return NULL;
}
void insert(struct node *root, int key)
{
    struct node* prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(root->data==key)
        {
            printf("Cannot insert %d. Already in BST.\n",root->data);
            return;
        }
        if(key<root->data)
        root = root -> left;
        else
        root = root -> right;
    }
    struct node *new = createNode(key);
    if(key<prev->data)
    prev->left = new;
    else
    prev->right = new;
}
struct node* inorderpredecessor(struct node* root)
{
    root = root->left;
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
struct node* delete(struct node* root, int key)
{
    struct node *prd;
    if(root==NULL)
    return NULL;
    if(root->left == NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(key<root->data)
    root->left = delete(root->left, key);
    else if(key>root->data)
    root->right = delete(root->right,key);
    else{
        prd = inorderpredecessor(root);
        root->data = prd->data;
        root->left = delete(root->left, prd->data);         
    }
    return root;
}
int main()
{
    struct node *root, *p2, *p3, *p4, *p5;
    root = createNode(5); 
    p2 = createNode(3);
    p3 = createNode(6);
    p4 = createNode(1);
    p5 = createNode(4);
    root->left = p2;
    root->right = p3;
    p2->left = p4;
    p2->right = p5;
    insert(root,7);
    inorder(root);
    printf("\n");
    if(isBst(root))
    {
        printf("The given tree is a Binary Search tree.\n");
        if(searchitr(root,1)!=NULL)
        printf("The searched item present is: %d\n",searchitr(root,7)->data);
        else
        printf("The searched item is not present.\n");
    }
    else
    printf("The given tree is not a binary tree.\n");
    delete(root, 3);
    inorder(root);
    return 0;
}