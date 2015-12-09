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
float findMedian(struct node *head)
{
    int count = 1;
    struct node *mid = head,*curr=head;
    while (curr->next!= NULL)
    {
        if (count%2==0)
            mid = mid->next;
        count++;
        curr = curr->next;
    }
    if(count%2==0)
        return ((float)((mid->next->num)+(mid->num))/2);
    else
        return mid->num;
}
void main()
{
	struct node *head = NULL;
	int n;
	printf("enter the number of list elements: \n");
	scanf("%d", &n);
	if (n <= 0)
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
		printf("the median of the list is : %f ", findMedian(head));
	}
	getch();
}
