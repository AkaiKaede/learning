#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_INIT_SIZE    100
typedef struct {
	int* elem;
	int length;
	int listsize;
}SqList;


SqList listcreat()                                 //顺序表的创建
{
	int i = 0;
	int a[20];
	srand(time);
	for (i = 0; i < 20; i++)
		a[i] = rand()%100+1;                      //产生线性表数据
	static int b[LIST_INIT_SIZE] = {0};
	for (i = 0; i < 20; i++)
		b[i] = a[i];
	SqList list = { b,20,20 * sizeof(int) };
	return list;
}

int listinsert(SqList* plist, int loc, int data)   //顺序表的插入
{
	int i = 0;
	for (i = plist->length - 1; i >= loc - 1; i--)
		plist->elem[i + 1] = plist->elem[i];
	plist->elem[loc - 1] = data;
	plist->length += 1;
	plist->listsize += sizeof(int);
	return 0;
}

int listprint(SqList* plist)                      //顺序表的输出
{
	int i = 0;
	for (i = 0; i < plist->length; i++)
		printf("%d ", plist->elem[i]);
	printf("\n");
	return 0;
}

int listchange(SqList* plist, int loc, int data)  //顺序表的修改
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
	list = listcreat();             //顺序表的创建
	listprint(&list);                //输出原顺序表
	data = rand() % 100 + 1;         //生成一个要插入的数据
	listinsert(&list, 2, data);     //顺序表的插入
	listprint(&list);                //输出插入后的顺序表
	data = rand() % 100 + 1;         //生成一个要改变的数据
	listchange(&list, 4, data);     //顺序表的修改
	listprint(&list);              //输出修改后的顺序表
	listinver(&list);              //顺序表的逆置
	listprint(&list);              //输出逆置后的顺序表
	return 0;
}