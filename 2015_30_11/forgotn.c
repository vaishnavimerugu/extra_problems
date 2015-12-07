//aim: a person was building a sorted array and forgot the length. the conditions are n+1th element is >n and n+2th element is <n+1.
//also there are n number of zeros after n+2th element. find n
#include<stdio.h>
/*test cases
1.length>0
2.length=0
3.invalid input
*/
//this program works for unsigned numbers
int forgotn(int *arr,int n)
{
	int i,temp,power2=2;
	while(1)
	{
		if(arr[n+1]>arr[n]&&arr[n+2]<arr[n+1]) //if n is our expected length
			return n+1;
		else if(arr[n+1]<arr[n]&&arr[n-1]<arr[n]) //if n is our expected length+1 i.e n points to n+1
			return n;
		else if(arr[n-1]>arr[n]&&arr[n+1]<arr[n])// if n is our expected length +2 i.e n points to n+2
			return n-1;
		else if(arr[n]==0)
		{
			temp=n;
			for(i=0;;i++)
			{
				if(arr[temp]==0)
				{
					temp=n/2;
					temp=temp+temp/power2;
					power2*=2;
					//power2 is used to check multiples of 2 from temp
				}
				else
					return forgotn(arr,temp);//if current temp is not 0 check normally from temp
			}
		}
		else
			return forgotn(arr,n*2);//if we encounter an element that is not n,n+1,n+2 or 0 then n=n*2
	}
}
void main()
{
	int arr[]={5,10,13,18,21,26,32,41,43,49,54,51,0,0,0,0,0,0,0,0,0,0}; // length=10
	int len;  //length of array
	len=forgotn(arr,1);
	printf("length of array= %d\n",len);
	getchar();
}




