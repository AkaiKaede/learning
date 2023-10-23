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
	pzhan->base = (int *)malloc(MAXSIZE*sizeof(int));
	if (!pzhan->base)
		exit(-1);
	pzhan->top = pzhan->base;
	pzhan->stacksize = MAXSIZE;
}

void Inzhan(Zhan* pzhan)
{
	int flag=0;
	int value = 0;
	while (flag==0)
	{
		if(pzhan->top-pzhan->base== pzhan->stacksize)
		{
			printf("栈满，退出！");
			break;
		}
		printf("请输入你要入栈的值：");
		scanf("%d", &value);
		*(pzhan->top) = value;
		pzhan->top++;
		printf("输入成功，输入0继续入栈，输入1返回主菜单：");
		scanf("%d", &flag);
	}
	printf("\n");
}

int outzhan(Zhan* pzhan)
{
	if(pzhan->base==pzhan->top)
	{
		printf("栈空，无法出栈！");
		return -1;
	}
	int outnum = *(--pzhan->top);
	printf("出栈成功!");
	return  outnum;
}

void printzhan(Zhan* pzhan)
{
	int* p;
	int i;
	p = pzhan->base;
	for (i = 0; i < pzhan->top - pzhan->base; i++)
	{
		printf("[%d]", *p);
		p++;
	}
	printf("\n");
}

int main()
{
	int outnum;
	int flag = 0;
	int a;
	Zhan zhan;
	creat(&zhan);                  //创建一个栈
	while(1)
	{
		printf("输入0退出，输入1入栈，输入2出栈，输入3输出栈内元素：");
		scanf("%d", &a);
		switch (a)
		{
		case 0:exit(0);
		case 1:
			Inzhan(&zhan); 
			break;
		case 2:
			outnum=outzhan(&zhan); 
			printf("出栈元素为：[%d]\n\n", outnum);
			break;
		case 3:
			printzhan(&zhan); 
			break;
		default: break;
		}
	}
	return 0;
}