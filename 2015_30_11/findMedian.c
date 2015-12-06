#include<malloc.h>
#include<stdio.h>
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
int findMedian(struct node *head)
{
	struct node *ptr1 = head;
	struct node *ptr2 = head;
	while (ptr2 != NULL && ptr2->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	return ptr1->num;
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
		printf("the median of the list is : %d ", findMedian(head));
	}
	getch();

}
