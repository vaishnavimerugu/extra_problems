//aim: to convert a binary number into octal number.
#include<stdio.h>
//testcases
//numbers having no.of digits exactly as a multiple of 3
//numbers having no.of digits as multiple of 3 plus 2 extra digits
//numbers having no.of digits as multiple of 3 plus 1 digit extra
//not a binary number
int mystrlen(char *s)
{
    //calculates the length of a given string
    int len=0;
    while(s[len]!='\0')
    {
        len++;
    }
    return len;
}
char * binaryToOctal(char *s)
{
    //calculating the length of string to find out the number of triplets possible
    int i=mystrlen(s),k=0;
    int j=3-i%3;
    i=0;
    //storing the result in the same string. i is now acting as the index of insertion.
    if(j==1)
    {
        //handling case for all triplets and one duplet at the start. since the first digit will be 0, multiplying the
        //remaining with binary powers of 2
        s[i]=((s[k]-'0')*2+(s[k+1]-'0')*1)+'0';
        k=k+2;
        i++;
    }
    else if(j==2)
    {
        //handling case for all triplets and one singlet at the start. since first 2 digits will be 0, multiplying the
        //remaining 1 digit with 1
        s[i]=((s[k]-'0')*1)+'0';
        k=k+1;
        i++;

    }
        while(s[k]!='\0')
        {
            //when the number of digits are an exact multiple of 3 and also the code that runs after processing the odd digits
            //calculating corresponding octal value for each triplet
            //terminates when null pointer is reached, end of processing.
            s[i]=((s[k]-'0')*4+(s[k+1]-'0')*2+(s[k+2]-'0')*1)+'0';
            k=k+3;
            i++;
        }
        s[i]='\0';
        return s;
    }
int main()
{
    char str2[17]="01101011010";
    char *s=binaryToOctal(str2);
    int j=0;
        for(j=0;s[j]!='\0';j++)
        {
            printf("%c",s[j]);
}
getchar();
return 0;
}
