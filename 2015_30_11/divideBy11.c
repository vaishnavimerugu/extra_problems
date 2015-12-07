#include<stdio.h>
struct testcase{
char str[100];
int res;
}t[5]={ { "7524",0 }, { "489657",-1 }, { "1331",0 },{"00001",-1},{"38",-1} };
int divideBy11(char *s)
{
    int i = 0, sum_even = 0, sum_odd = 0;
    int difference;
    for(i=0;s[i]!='\0';i++)
    {
     int num=s[i]-'0';
		if (i%2== 0)
			sum_even +=num;
		else
			sum_odd +=num;
    }
    difference =sum_even>sum_odd?(sum_even-sum_odd):(sum_odd-sum_even);
	if (difference%11 == 0)
		return 0;
	else
		return -1;

}
void test(int num_testcases)
{
    int i=0;
    for(i=0;i<num_testcases;i++)
    {
        int res=divideBy11(t[i].str);
        if(res==t[i].res)
        {
            printf("pass\n");
        }
        else
            printf("fail\n");
    }
}
int main()
{
   test(6);
    getchar();
    return 0;
}

