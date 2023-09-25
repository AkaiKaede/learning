#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void GetOdd(int a[], int* b, int* m)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (a[i] % 2 != 0)
		{
			*b = a[i];
			b++;
			(*m)++;
		}
	}
}

int main()
{
	int i = 0, a[9] = { 0 }, b[9] = {0},m=0;
	for (i = 0; i < 9; i++)
		scanf("%d", &a[i]);
	GetOdd(a, b, &m);
	if (m == 0)
		printf("NO");
	else
		for (i = 0; i < m; i++)
		{
			printf("%d ", b[i]);
		}

	return 0;
}
