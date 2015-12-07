
#include<stdio.h>
struct testcase{
char str[100];
int k;
int res;
}t[5]={{"41",3,0},{"61345",200,-1},{"41",1,-1},{"0000",10,0},{"22052015",21,0}};
int repeatAndDivideBy3(char *s,int k)
{
    int i=0,sum=0;
    for(i=0;s[i]!='\0';i++)
    {
     int num=s[i]-'0';
     sum+=num;
    }
    if((sum*k)%3==0)
        return 0;
    else
        return -1;
}
void test(int num_testcases)
{
    int i=0;
    for(i=0;i<num_testcases;i++)
    {
        int res=repeatAndDivideBy3(t[i].str,t[i].k);
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
   test(5);
    getchar();
    return 0;
}
