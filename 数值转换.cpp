#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct {
	int* top;
	int* base;
	int stacksize;
}Zhan;

void creat(Zhan* pzhan)          //ջ�Ĵ���
{
	pzhan->base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!pzhan->base)
	{
		printf("����ջʧ��");
		exit(-1);
	}
	pzhan->top = pzhan->base;
	pzhan->stacksize = MAXSIZE;
}

void Inzhan(Zhan* pzhan,int value)
{
	if (pzhan->top - pzhan->base == pzhan->stacksize)
	{
		printf("ջ�����˳���");
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
	if (pzhan->base == pzhan->top)                   //ջ��
		return -1;
	else
		return  *(--pzhan->top);
}

int main()
{
	Zhan zhan;
	int a=0,outnum=0;
	printf("��������Ҫת���ɰ˽��Ƶ�ʮ����������");
	scanf("%d", &a);
	creat(&zhan);
	while(a)
	{
		Inzhan(&zhan, a % 8);
		a = a / 8;
	}
	printf("ת����İ˽�����Ϊ��");
	while ((outnum = outzhan(&zhan)) != -1)
	{
		printf("%d", outnum);
	}
	return 0;
}