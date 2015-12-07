#include<stdio.h>
void printLastKLines(FILE *fp, int k)
{
	if (fp == NULL || k <= 0)
	{
		printf("invalid input\n");
		return;
	}
	int size = 1, kcount = 0, ch;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\n')
			size++;
	}
	fseek(fp, 0, SEEK_SET);
	while ((ch = fgetc(fp)) != EOF&&kcount<size - k)
	{
		if (ch == '\n')
			kcount++;
	}
	printf("%c", ch);
	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
	}
	fclose(fp);
	getch();
}
int main()
{
	FILE *fp;
	int k;
	fp = fopen("C:/Users/VAISHNAVI/Desktop/hello.txt", "r");
	printf("enter the number of lines from last to be printed:\n");
	scanf("%d", &k);
	printLastKLines(fp, k);
}
