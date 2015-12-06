#include<stdio.h>
#include<malloc.h>
//does not work for all negative numbers
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
int maxSum(struct node *head)
{
    if(head==NULL)
        return -1;
    int maxsum=0,tempsum=0;
    struct node *current=head;
    while(current!=NULL)
    {
        tempsum=tempsum+current->num;
        if(tempsum<0)
            tempsum=0;
        if(maxsum<tempsum)
            maxsum=tempsum;
        current=current->next;
    }
    return maxsum;
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
	printf("the max sum is : %d\n",maxSum(head));
	getch();
}
