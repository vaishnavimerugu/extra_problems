#include<stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
void add(struct node** headref, int data)
{
	struct node* current = (struct node *) malloc(sizeof(struct node));
	current->num = data;
	current->next = *headref;
	*headref = current;
}
struct node * addLists(struct node *head1, struct node *head2, int len1, int len2)
{
	struct node *greater = (len1 >= len2) ? head1 : head2;
	struct node *smaller = (len1<len2) ? head1 : head2;
	while (smaller != NULL)
	{
		greater->num = greater->num + smaller->num;
		smaller = smaller->next;
		greater = greater->next;
	}
	return (len1 >= len2 ? head1 : head2);
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
	struct node *res = addLists(head1, head2, n1, n2);
	display(res);
	getchar();
}
