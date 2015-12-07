//aim: to convert a number from decimal to base -2
#include<stdio.h>
#include<conio.h>
/*test cases
1.singe digit number
2.zero
3.negative number
4.a regular number
5.not a number
*/
//this code only works for positive numbers and 0
int mystrlen(char *s)
{
    //to calculate the length of a string
    int len=0;
    while(s[len]!='\0')
    {
        len++;
    }
    return len;
}
void mystrrev(char *s)
{
    //to reverse a given string
    int len=mystrlen(s)-1,i;
    for(i=0;i<len/2;i++)
    {
        char temp=s[i];
        s[i]=s[len];
        s[len]=temp;
        len--;
    }
    return;
}
 char *convertToBase(int num)
 {
     //num is the decimal number to be converted
      int i=0;
     //rem stores the remainder at each step which is appended into the string
     char result[100];//storing the resultant base -2 in a string
     if(num==0)
     {
         result[i]=0+'0';
         result[i+1]='\0';
         return result;
     }
     for(i=0;num!=0;i++)
     {
         int temp=num%-2;//gives remainder after dividing by -2 since it is base -2
         if(temp<0)
            temp+=2;//if it is less than 0 adding 2 to make it positive as digits in base -2 cannot be negative
         result[i]=temp+'0';
         //printf("%d %d\n",num,temp);
         if(num<0)
         num=(num/-2)+1;//when number is less than 0 adding 1 to make it suitable for processing
         else
            num/=-2;
    }
     result[i]='\0';
     mystrrev(result);
     return result;

 }
 int main()
 {
     int num;
     printf("enter the number in base 10 that you wish to convert:");
     scanf("%d",&num);
     char *s;
     s=convertToBase(num);
     printf("%s",s);
     getch();
 }

