#include<stdio.h>
struct testcases{
	unsigned int x,y,z,result;
}t[5] = { { 5, 4, 3, 1 }, { 167895, 0, 256, 1 }, { 0, 0, 1, 0 }, { -11, 12, 13, 1 }, { 6, 7, 2, 0 } };
unsigned int modulo(unsigned int x, unsigned int y, unsigned int z)
{
	unsigned int firstmod = 0, previousmod = 0, result = 0;
	if (y == 0)
	{
		result = 1 % z;
		return result;
	}
	else
	{
		firstmod = x%z;
		previousmod = firstmod;
		while (y - 1 != 0)
		{
			result = (previousmod*firstmod) % z;
			previousmod = result;
			y--;
		}
		return result;
	}

}
void test(int num_testcases)
{
	for (int i = 0; i < num_testcases; i++)
	{
		unsigned int result = modulo(t[i].x, t[i].y, t[i].z);
		if (t[i].result == result)
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