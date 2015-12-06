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
void swap(struct node *a, struct node *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}
void findMisplacedElements(struct node *head)
{
	if (head == NULL)
		return;
	struct node *current = head, *pos1 = head, *pos2 = head, *prev = head;
	while (current != NULL)
	{
		if (pos1 == head)
		{
			if (current->num > current->next->num)
			{
				pos1 = current;
			}
			else
			{
				if ((prev->num < current->num) && (current->next->num<current->num))
					pos1 = current;
			}
		}
		else
		{
			if (current->num<prev->num)
				pos2 = current;
		}
		prev = current;
		current = current->next;
	}
	swap(pos1, pos2);
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
		findMisplacedElements(head);
		display(head);
	}
	getch();
}
