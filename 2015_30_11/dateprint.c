#include<stdio.h>
#include<string.h>
struct testcase{
	char input[100];
	char output[100];
}t[3] = { { "22-05-1996", { "twenty two may nineteen thousand nine hundred ninety six" } }, { "09-08-0001", { "nine august one" } }, { "31-12-9999", { "thirty one december nine thousand nine hundred ninety nine" } } };
char output[100];
void mystrcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}
void mystrcat(char *dest, char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while ((*dest = *src) != '\0')
	{
		dest++;
		src++;
	}
}
void printDate(char *input)
{
	char units[10][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char tenSeries[10][15] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char tens[10][10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	char tenPower[2][10] = { "hundred", "thousand" };
	char month[13][10] = { "", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	int val1 = input[0] - '0';
	int val2 = input[1] - '0';
	if (val1 == 0)
		mystrcpy(output, units[val2]);
	else if (val1 == 1)
		mystrcpy(output, tenSeries[val2]);
	else
	{
		mystrcpy(output, tens[val1]);
		mystrcat(output, " ");
		mystrcat(output, units[val2]);
	}
	val1 = input[3] - '0';
	val2 = input[4] - '0';
	if (val1 == 0)
	{
		mystrcat(output, " ");
		mystrcat(output, month[val2]);
	}
	else
	{
		mystrcat(output, " ");
		mystrcat(output, month[val2 + 10]);
	}
	val1 = input[6] - '0';
	val2 = input[7] - '0';
	if (val1 == 1)
	{
		mystrcat(output, " ");
		mystrcat(output, tenSeries[val2]);
		mystrcat(output, " ");
		mystrcat(output, tenPower[1]);
	}
	else
	if (val1>1)
	{
		mystrcat(output, " ");
		mystrcat(output, units[val1]);
		mystrcat(output, " ");
		mystrcat(output, tenPower[1]);
	}

	if (val2 != 0)
	{
		mystrcat(output, " ");
		mystrcat(output, units[val2]);
		mystrcat(output, " ");
		mystrcat(output, tenPower[0]);
	}
	val1 = input[8] - '0';
	val2 = input[9] - '0';
	if (val1 == 0)
	{
		mystrcat(output, " ");
		mystrcat(output, units[val2]);
	}
	else if (val1 == 1)
	{
		mystrcat(output, " ");
		mystrcat(output, tenSeries[val2]);
	}
	else
	{
		mystrcat(output, " ");
		mystrcat(output, tens[val1]);
		mystrcat(output, " ");
		mystrcat(output, units[val2]);
	}
	puts(output);
}
void test(int num_testcases)
{
	for (int i = 0; i < num_testcases; i++)
	{
		printDate(t[i].input);
		if (strcmp(t[i].output, output) == 0)
			printf("pass\n");
		else
			printf("fail\n");

	}
}
void main()
{
	test(3);
	getchar();
}

