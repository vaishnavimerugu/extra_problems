#include<stdio.h>
struct testcase
{
    char str1[100];
    char str2[100];
    char output[101];
}t[5]={{"12345","345"," 12690"},{"87564321","852004761"," 939569082"},{"2015","19470"," 21485"},{"00000","111"," 00111"},{"9652952599","9966931240","19619883839"}};
int mystrlen(char *s)
{
    int len=0;
    while(s[len]!='\0')
    {
        len++;
    }
    return len;
}
char *stringAdder(char *s1,char *s2)
{
    int carry=0,i=0,len=0;
    char *result,*greater;
    int s1len=mystrlen(s1);
    int s2len=mystrlen(s2);
    int smallerlen=s1len<s2len?s1len:s2len;
    if(s1len>s2len)
    {
        result=s1+1;
        greater=s1;
        len=s1len;
    }
    else{
        result=s2+1;
        greater=s2;
        len=s2len;
    }
    result[len+1]='\0';
        while(smallerlen>0)
        {
        s1len--;
        s2len--;
        result[len]=(((s1[s1len]-'0')+(s2[s2len]-'0')+carry)%10)+'0';
        carry=(((s1[s1len]-'0')+(s2[s2len]-'0')+carry)/10);
        len--;
        smallerlen--;
        }
        while(len>=1)
        {
            result[len]=(((greater[len-1]-'0')+carry)%10)+'0';
            carry=((greater[len-1]-'0')+carry)/10;
            len--;
        }
        if(carry>0)
            result[0]=carry+'0';
            else
                result[0]=' ';
       return result;
}
void test(int num_testcases)
{
    int i=0;
    for(i=0;i<num_testcases;i++)
    {
        int flag=1;
        char *res=stringAdder(t[i].str1,t[i].str2);
        int j=0;
        for(j=0;res[j]!='\0';j++)
        {
            if(res[j]==t[i].output[j])
                continue;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag)
            printf("pass\n");
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
