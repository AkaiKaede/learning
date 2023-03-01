#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int fi(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fi(n - 1) + fi(n - 2);
}

int main()
{
	int i;
	for (i = 1;i<=10; i++)
	{
		printf("%d ", fi(i));
		if (i == 5)
			printf("\n");
	}

	return 0;
}