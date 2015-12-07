#include<stdio.h>
struct testcase{
	unsigned int a;
	unsigned int b;
	unsigned int result;
}t[5] = { { 100, -25, -2500 }, { 2, 0, 0 }, { 422, 3, 1266 }, { -21, 2, -42 }, { -4, -2, 8 } };
unsigned int mult(unsigned int a,unsigned int b)
{
	unsigned int result = 0;
	while (b!= 0)
	{
		if (b %2== 1)
		{
			result += a;
		}
		b >>= 1;
		a <<= 1;
	}
	printf("%d\n", result);
	return result;
}
void test(int num_testcases)
{
	for (int i = 0; i < num_testcases; i++)
	{
		unsigned int res = mult(t[i].a, t[i].b);
		if (res == t[i].result)
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