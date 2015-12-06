#include<stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
void add(struct node **headref, int data)
{
	struct node* current = (struct node *) malloc(sizeof(struct node));
	current->num = data;
	current->next = *headref;
	*headref = current;
}
void display(struct node *head)
{
	if (head == NULL)
		return;
	while (head != NULL)
	{
		printf("%d\n", head->num);
		head = head->next;
	}
}
void reverse(struct node **head)
{
	if (*head == NULL)
		return;
	struct node *ptr1, *ptr2;
	ptr1 = *head;
	ptr2 = ptr1->next;
	if (ptr2 == NULL)
		return;
	reverse(&ptr2);
	ptr1->next->next = ptr1;
	ptr1->next = NULL;
	*head = ptr2;
}
void main()
{
	struct node *head = NULL;
	int n;
	printf("enter the number of list elements: \n");
	scanf("%d", &n);
	if (n == 0)
		printf("invalid input\n");
	else
	{
		printf("enter data:\n");
		int i;
		for (i = 0; i < n; i++)
		{
			int data;
			scanf("%d", &data);
			add(&head, data);
		}
	}
	reverse(&head);
	display(head);
	getch();
}
