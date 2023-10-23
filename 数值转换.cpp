#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct {
	int* top;
	int* base;
	int stacksize;
}Zhan;

void creat(Zhan* pzhan)          //栈的创建
{
	pzhan->base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!pzhan->base)
	{
		printf("创建栈失败");
		exit(-1);
	}
	pzhan->top = pzhan->base;
	pzhan->stacksize = MAXSIZE;
}

void Inzhan(Zhan* pzhan,int value)
{
	if (pzhan->top - pzhan->base == pzhan->stacksize)
	{
		printf("栈满，退出！");
		exit(-1);
	}
	else	
	{
		*(pzhan->top) = value;
		pzhan->top++;
	}
}

int outzhan(Zhan* pzhan)
{
	if (pzhan->base == pzhan->top)                   //栈空
		return -1;
	else
		return  *(--pzhan->top);
}

int main()
{
	Zhan zhan;
	int a=0,outnum=0;
	printf("请输入你要转换成八进制的十进制正数：");
	scanf("%d", &a);
	creat(&zhan);
	while(a)
	{
		Inzhan(&zhan, a % 8);
		a = a / 8;
	}
	printf("转换后的八进制数为：");
	while ((outnum = outzhan(&zhan)) != -1)
	{
		printf("%d", outnum);
	}
	return 0;
}