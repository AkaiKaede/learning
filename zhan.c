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
			printf("ջ�����˳���");
			break;
		}
		printf("��������Ҫ��ջ��ֵ��");
		scanf("%d", &value);
		*(pzhan->top) = value;
		pzhan->top++;
		printf("����ɹ�������0������ջ������1�������˵���");
		scanf("%d", &flag);
	}
	printf("\n");
}

int outzhan(Zhan* pzhan)
{
	if(pzhan->base==pzhan->top)
	{
		printf("ջ�գ��޷���ջ��");
		return -1;
	}
	int outnum = *(--pzhan->top);
	printf("��ջ�ɹ�!");
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
	creat(&zhan);                  //����һ��ջ
	while(1)
	{
		printf("����0�˳�������1��ջ������2��ջ������3���ջ��Ԫ�أ�");
		scanf("%d", &a);
		switch (a)
		{
		case 0:exit(0);
		case 1:
			Inzhan(&zhan); 
			break;
		case 2:
			outnum=outzhan(&zhan); 
			printf("��ջԪ��Ϊ��[%d]\n\n", outnum);
			break;
		case 3:
			printzhan(&zhan); 
			break;
		default: break;
		}
	}
	return 0;
}