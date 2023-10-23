#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Size 6

typedef struct {                                                   //���нṹ��
	int *list;
	int front;
	int rear;
}List;

typedef struct node{                                               //���
	int data;
	struct node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
}Lian;

void Listcreat(List *plist)                                        
{
	plist->list = (int*)malloc((Size + 1) * sizeof(int));          //����һ������
	plist->rear = 1;                                               //��β�±�
	plist->front = 0;                                              //�����±�
}

void Listin(List* plist, int value)
{
	if (plist->front == plist->rear)
		printf("�������޷����");
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
		printf("�ӿգ��޷�����");
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
		printf("�ӿգ��޷����");
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
	plian->rear = (Node*)malloc(sizeof(Node));                     //����ͷ���(����)
	if (!plian->front)
	{
		printf("�ڴ�����˳���");
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
		printf("�ڴ�����˳���");
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
	printf("-------------ѭ������-------------\n");
	int outnum;
	List list;
	Listcreat(&list);                                              //����һ��ѭ������
	int i = 0;
	srand(time);
	for(i=0;i<Size;i++)
	{
		Listin(&list, rand() % 10 + 1);                            //��������������ɲ�������,�����
	}
	printf("��һ����Ӻ�Ķ��У�");
	Listprint(&list);                                              //�����Ӻ�Ķ���
	outnum=Listout(&list);                                         //����һ����
	printf("���ӵ�Ԫ�أ�[%d]\n", outnum);                          //�������Ԫ��
	printf("���Ӻ�Ķ��У�");       
	Listprint(&list);                                              //������Ӻ�Ķ���
	Listin(&list, rand() % 10 + 1);                                //�ڶ������
	printf("�ڶ�����Ӻ�Ķ��У�");
	Listprint(&list);                                              //����ڶ�����Ӻ�Ķ���
	printf("-------------������--------------\n");
	Lian lian;
	Liancreat(&lian);                                              //����һ��������
	for (i = 0; i < Size; i++)
	{
		Lianin(&lian, rand() % 10 + 1);                            //��������������ɲ�������,�����
	}
	printf("��һ����Ӻ�Ķ��У�");
	Lianprint(&lian);                                              //�����Ӻ�Ķ���
	outnum = Lianout(&lian);                                       //����һ����
	printf("���ӵ�Ԫ�أ�[%d]\n", outnum);                          //�������Ԫ��
	printf("���Ӻ�Ķ��У�");
	Lianprint(&lian);                                              //������Ӻ�Ķ���
	Lianin(&lian, rand() % 10 + 1);                                //�ڶ������
	printf("�ڶ�����Ӻ�Ķ��У�");
	Lianprint(&lian);                                              //����ڶ�����Ӻ�Ķ���
	return 0;
}