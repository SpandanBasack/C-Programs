#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void traversal(struct node *head)
{
    struct node *ptr = head;
    do{
        printf("The element %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
struct node* insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    struct node *p = head;
    while (p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;
    head = ptr;
    return head;
}
int main()
{
	struct node *head, *second, *third, *fourth;
	head = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	fourth = (struct node *)malloc(sizeof(struct node));
	head->data = 23;
	head->next = second;
	second->data = 45;
	second->next = third;
	third->data = 76;
	third->next = fourth;
	fourth->data = 85;
	fourth->next = head;
	printf("The elements in the given linked list are:\n");
    traversal(head);
    head = insertAtFirst(head,54);
    printf("The given elements after modification:\n");
    traversal(head);
	return 0;
}