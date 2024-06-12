#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
    struct node *prev;
};
void traversal(struct node *ptr)
{
	while (ptr != 0)
	{
		printf("Element: %d\n", ptr->data);
		ptr = ptr->next;
	}
}
struct node* insertFirst(struct node *head, int data)
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next = head;
	ptr->data = data;
    ptr->prev=NULL;
    head->prev=ptr;
	return ptr;
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
    head->prev = NULL;
	second->data = 45;
	second->next = third;
    second->prev= head;
	third->data = 76;
	third->next = fourth;
    third->prev=second;
	fourth->data = 85;
	fourth->next = NULL;
    fourth->prev=third;
	printf("Linked List before operation:\n");
	traversal(head);
	head = insertFirst(head, 14);
	//head = insertbetween(head,77,2);
	//head = insertEnd(head,33);
	//insertAfternode(second,22);
	//head = deleteFirst(head);
	// head = deleteAtindex(head,2);
    //head = deleteAtlast(head);
	//head = deleteAtValue(head,85);
    printf("Linked List after operation:\n");
	traversal(head);
	return 0;
}