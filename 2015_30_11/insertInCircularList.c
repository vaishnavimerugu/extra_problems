#include<malloc.h>
#include<stdio.h>
struct node
{
	int num;
	struct node *next;
};
void main()
{
	struct node *head = NULL;
	printf("enter the number of nodes:\n");
	int n;
	scanf("%d", &n);
	if (n == 0)
		printf("invalid input,empty list created");
	else
	{
		printf("enter data\n");
		while (n>0)
		{
			int data;
			scanf("%d", &data);
			insert(&head, data);
			n--;
		}
	}
	displaylist(head);
	getch();

}
void insert(struct node **head, int data)
{
	struct node *current = *head;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if (current == NULL)
	{
		newnode->next = newnode;
		newnode->num = data;
		*head = newnode;
	}
	else
	{
		while (current->next != *head)
			current = current->next;
		newnode->num = data;
		current->next = newnode;
		newnode->next = *head;
	}
}
void displaylist(struct node *head)
{
	struct node *current = head;
	while (current->next != head)
	{
		printf("%d", current->num);
		current = current->next;
	}
	printf("%d", current->num);
}
