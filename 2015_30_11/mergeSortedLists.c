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
struct node * mergeLists(struct node *head1, struct node *head2)
{
	struct node temp;
	struct node *result = &temp;
	temp.next = NULL;
	while (1)
	{
		if (head1 == NULL)
		{
			result->next = head2;
			break;
		}
		else if (head2 == NULL)
		{
			result->next = head1;
			break;
		}
		if (head1->num <= head2->num)
		{
			mergeNode(&(result->next), &head1);
		}
		else
		{
			mergeNode(&(result->next), &head2);
		}
		result = result->next;
	}
	return(temp.next);
}
void mergeNode(struct node **dest, struct node **source)
{
	struct node *current = *source;
	if (current != NULL)
	{
		*source = current->next;
		current->next = *dest;
		*dest = current;
	}
}
void main()
{
	struct node *head1 = NULL, *head2 = NULL;
	int n1, n2;
	printf("enter the number of list1 & list2 elements: \n");
	scanf("%d %d", &n1, &n2);
	if (n1 == 0 && n2 == 0)
		printf("invalid input\n");
	else
	{
		printf("enter data for list1:\n");
		int i;
		for (i = 0; i < n1; i++)
		{
			int data;
			scanf("%d", &data);
			add(&head1, data);
		}
		printf("enter data for list2:\n");
		for (i = 0; i < n2; i++)
		{
			int data;
			scanf("%d", &data);
			add(&head2, data);
		}
	}
	printf("\n\n");
	struct node *head = mergeLists(head1, head2);
	display(head);
	getch();
}
