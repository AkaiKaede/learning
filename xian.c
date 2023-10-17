#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_INIT_SIZE    100
typedef struct {
	int* elem;
	int length;
	int listsize;
}SqList;


SqList listcreat()                                 //˳���Ĵ���
{
	int i = 0;
	int a[20];
	srand(time);
	for (i = 0; i < 20; i++)
		a[i] = rand()%100+1;                      //�������Ա�����
	static int b[LIST_INIT_SIZE] = {0};
	for (i = 0; i < 20; i++)
		b[i] = a[i];
	SqList list = { b,20,20 * sizeof(int) };
	return list;
}

int listinsert(SqList* plist, int loc, int data)   //˳���Ĳ���
{
	int i = 0;
	for (i = plist->length - 1; i >= loc - 1; i--)
		plist->elem[i + 1] = plist->elem[i];
	plist->elem[loc - 1] = data;
	plist->length += 1;
	plist->listsize += sizeof(int);
	return 0;
}

int listprint(SqList* plist)                      //˳�������
{
	int i = 0;
	for (i = 0; i < plist->length; i++)
		printf("%d ", plist->elem[i]);
	printf("\n");
	return 0;
}

int listchange(SqList* plist, int loc, int data)  //˳�����޸�
{
	plist->elem[loc - 1] = data;
	return 0;
}

int listinver(SqList* plist)                      
{
	int i = 0, j = 0;
	int t;
	for (i = 0, j = plist->length - 1; j > i; j--, i++)
	{
		t = plist->elem[i];
		plist->elem[i] = plist->elem[j];
		plist->elem[j] = t;
	}
}

int main()
{
	int data;
	SqList list;
	list = listcreat();             //˳���Ĵ���
	listprint(&list);                //���ԭ˳���
	data = rand() % 100 + 1;         //����һ��Ҫ���������
	listinsert(&list, 2, data);     //˳���Ĳ���
	listprint(&list);                //���������˳���
	data = rand() % 100 + 1;         //����һ��Ҫ�ı������
	listchange(&list, 4, data);     //˳�����޸�
	listprint(&list);              //����޸ĺ��˳���
	listinver(&list);              //˳��������
	listprint(&list);              //������ú��˳���
	return 0;
}