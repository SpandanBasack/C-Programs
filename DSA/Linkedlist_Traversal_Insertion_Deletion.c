#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
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
	return ptr;
}
struct node* insertbetween(struct node *head, int data, int index)
{
	struct node *ptr = (struct node*) malloc (sizeof(struct node));
	struct node *p=head;
	int i =0;
	while(i<(index-1))
	{
		p=p->next;
		i++;
	}
	ptr->next = p->next;
	p->next = ptr;
	ptr->data = data;
	return head;
}
struct node* insertEnd(struct node* head,int data)
{
	struct node *ptr = (struct node*) malloc (sizeof(struct node));
	struct node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=ptr;
	ptr->next=NULL;
	ptr->data = data;
	return head;
}
void insertAfternode(struct node *pvnd, int data)
{
    struct node *ptr = (struct node*) malloc (sizeof(struct node));
	ptr->next=pvnd->next;
	pvnd->next=ptr;
	ptr->data = data;
}
struct node* deleteFirst(struct node* head)
{
	struct node *ptr = head;
	head= head->next;
	free(ptr);
	return head;
}
struct node* deleteAtindex(struct node* head,int index)
{
	int i=0;
	struct node *p = head;
	struct node *q = head->next;
	while (i<index-1)
	{
		p = p->next;
		q = q->next;
		i++;
	}
	p->next = q->next;
	free(q);
	return (head);
}
struct node* deleteAtlast(struct node* head)
{
	struct node *p = head;
	struct node *q = head->next;
	while (q->next!=NULL)
	{
		p = p->next;
		q = q->next;
	}
	p->next = NULL;
	free(q);
	return (head);
}
struct node* deleteAtValue(struct node* head, int value)
{
	struct node *p = head;
	struct node *q = head->next;
	while ((q->data != value) && (q->next!=NULL))
	{
		p = p->next;
		q = q->next;
	}
	if(q->data==value)
	{
	p->next = q->next;
	free(q);
	}
	return (head);
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
	fourth->next = NULL;
	printf("Linked List before operation:\n");
	traversal(head);
	//head = insertFirst(head, 14);
	//head = insertbetween(head,77,2);
	//head = insertEnd(head,33);
	//insertAfternode(second,22);
	//head = deleteFirst(head);
	// head = deleteAtindex(head,2);
    //head = deleteAtlast(head);
	head = deleteAtValue(head,85);
	printf("Linked List after operation:\n");
	traversal(head);
	return 0;
}