#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Size 6

typedef struct {                                                   //队列结构体
	int *list;
	int front;
	int rear;
}List;

typedef struct node{                                               //结点
	int data;
	struct node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
}Lian;

void Listcreat(List *plist)                                        
{
	plist->list = (int*)malloc((Size + 1) * sizeof(int));          //创建一个队列
	plist->rear = 1;                                               //队尾下标
	plist->front = 0;                                              //队首下标
}

void Listin(List* plist, int value)
{
	if (plist->front == plist->rear)
		printf("队满，无法入队");
	else
	{
		plist->list[plist->rear] = value;
		plist->rear = (plist->rear + 1) % (Size + 1);
	}
}

int Listout(List* plist)
{
	if ((plist->front + 1) % (Size + 1) == plist->rear)
	{
		printf("队空，无法出队");
		return -1;
	}
	else
	{
		plist->front = (plist->front + 1) % (Size + 1);
		return plist->list[plist->front];
	}
}

void Listprint(List* plist)
{
	int i=0;
	if ((plist->front + 1) % (Size + 1) == plist->rear)
	{
		printf("队空，无法输出");
		return -1;
	}
	else
	{
		for (i = (plist->front + 1) % (Size + 1); i != plist->rear; i = (++i) % (Size + 1))
			printf("[%d]", plist->list[i]);
		printf("\n");
	}
}

void Liancreat(Lian* plian)
{
	plian->rear = (Node*)malloc(sizeof(Node));                     //建立头结点(队首)
	if (!plian->front)
	{
		printf("内存错误，退出！");
		exit(0);
	}
	plian->front = plian->rear;
	plian->front->next = NULL;
}

void Lianin(Lian* plian,int value)
{
	Node* ptr;
	ptr= (Node*)malloc(sizeof(Node));
	if (!ptr)
	{
		printf("内存错误，退出！");
		exit(0);
	}
	ptr->data = value;
	ptr->next = NULL;
	plian->rear->next = ptr;
	plian->rear = ptr;
}

void Lianprint(Lian* plian)
{
	Node* ptr;
	ptr = plian->front->next;
	while (ptr != NULL)
	{
		printf("[%d]", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int Lianout(Lian* plian)
{
	Node* ptr;
	ptr = plian->front->next;
	plian->front->next = ptr->next;
	return ptr->data;
}

int main()
{
	printf("-------------循环队列-------------\n");
	int outnum;
	List list;
	Listcreat(&list);                                              //创建一个循环队列
	int i = 0;
	srand(time);
	for(i=0;i<Size;i++)
	{
		Listin(&list, rand() % 10 + 1);                            //利用随机函数生成测试数据,并入队
	}
	printf("第一次入队后的队列：");
	Listprint(&list);                                              //输出入队后的队列
	outnum=Listout(&list);                                         //出队一个数
	printf("出队的元素：[%d]\n", outnum);                          //输出出队元素
	printf("出队后的队列：");       
	Listprint(&list);                                              //输出出队后的队列
	Listin(&list, rand() % 10 + 1);                                //第二次入队
	printf("第二次入队后的队列：");
	Listprint(&list);                                              //输出第二次入队后的队列
	printf("-------------链队列--------------\n");
	Lian lian;
	Liancreat(&lian);                                              //创建一个链队列
	for (i = 0; i < Size; i++)
	{
		Lianin(&lian, rand() % 10 + 1);                            //利用随机函数生成测试数据,并入队
	}
	printf("第一次入队后的队列：");
	Lianprint(&lian);                                              //输出入队后的队列
	outnum = Lianout(&lian);                                       //出队一个数
	printf("出队的元素：[%d]\n", outnum);                          //输出出队元素
	printf("出队后的队列：");
	Lianprint(&lian);                                              //输出出队后的队列
	Lianin(&lian, rand() % 10 + 1);                                //第二次入队
	printf("第二次入队后的队列：");
	Lianprint(&lian);                                              //输出第二次入队后的队列
	return 0;
}