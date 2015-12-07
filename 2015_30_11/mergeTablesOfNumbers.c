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
int checkForDuplicate(struct node *head, int data)
{
	int res = 0;
	while (head != NULL)
	{
		if (head->num == data)
		{
			res = 1;
			break;
		}
		head = head->next;
	}
	return res;
}
struct node * mergeTablesOfNumbers(int n1, int n2, int r)
{
	if (r <= 0)
	{
		printf("invalid index value\n");
		return NULL;
	}
	struct node *head = NULL;
	int count = 0, curr1 = n1, curr2 = n2, data = n1<n2 ? n1 : n2;
	add(&head, data);
	count++;
	while (count<r)
	{
		if (data == curr1)
		{
			curr1 += n1;
		}
		else
			curr2 += n2;
		data = curr1<curr2 ? curr1 : curr2;
		int res = checkForDuplicate(head, data);
		if (res == 0)
		{
			add(&head, data);
			count++;
		}
	}
	return head;
}
void main()
{
	int n1, n2, r;
	printf("enter the values of first and second table multiple:\n");
	scanf("%d %d", &n1, &n2);
	printf("enter the index of element required in the merged list:\n");
	scanf("%d", &r);
	struct node *result = mergeTablesOfNumbers(n1, n2, r);
	if (result != NULL)
		printf("the %d th element in the resultant list is %d\n", r, result->num);
	getch();
}
