//aim: to add 2 equal length strings from left to right containing unsigned numbers.sum of first digits of the strings is taken <9 for convenience
#include<stdio.h>
/*test cases
1.strings having all digit sums except 1st >9
2.strings having all digit sums except 1st<9
3.strings having a mix of sums <9 and >9
4.invalid input
*/
char *StringAdd(char *s1,char *s2)
{
	int i,i1,j,sum;
	for(i=0;s1[i]!='\0';i++)//iterate until end of string
	{
		sum=s1[i]-'0'+s2[i]-'0';//calculating the sum of digits
		if(sum==9)
			s1[i]=sum+'0';//if sum is 9 put it in the result
		else if(sum<9)
		{
			s1[i]=sum+'0';//if sum<9  put in the result and store the index in i1 for handling case sum>9
			i1=i;
		}
		else
		{
		    //if sum>9 store the units digit in i and increase the value of all digits from i1 to i by 1
			s1[i]=(sum%10)+'0';
			for(j=i1;j!=i;j++)
				s1[j]=(((s1[j]-'0'+1)%10)+'0');
			i1=i;//change the value of i1 to i so that from next time changes can take place from here
		}
	}
	return s1;
}
int main()
{
	char s1[100],s2[100];
	printf("enter the strings to be added: ");
	scanf("%s %s",s1,s2);
	char *result=StringAdd(s1,s2);
	printf("resultant string is: %s",result);
	getch();
	return 0;
}
