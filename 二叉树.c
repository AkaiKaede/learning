#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maxnum;                                   //ȫ�ֱ������������Ĳ���

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}Bnode;


Bnode* treein(Bnode* root, int value)         //�����뺯��
{
	Bnode* back=NULL;            //currut�ĸ����
	Bnode* currut;               //������
	Bnode* newnode;              //�½ڵ�
	newnode = (Bnode*)malloc(sizeof(Bnode));
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->data = value;       //��ֵ���½��
	if (!root)                   //rootΪ�������½�㼴Ϊ�����
		root = newnode;
	else
	{
		currut = root;
		while (currut != NULL)              //ʹcurrutָ��Ҫ������λ��
		{
			back = currut;
			if (currut->data > value)
				currut = currut->lchild;
			else
				currut = currut->rchild;
		}
		if (back->data > value)             //����back�������½��
			back->lchild = newnode;
		else
			back->rchild = newnode;
	}
	return root;
}

void midtrip(Bnode* root)                   //�����������    
{
	if(root)
	{
		midtrip(root->lchild);
		printf("[%d]", root->data);
		midtrip(root->rchild);
	}
}

void fronttrip(Bnode* root)                 //�����������
{
	if (root)
	{
		printf("[%d]", root->data);
		fronttrip(root->lchild);
		fronttrip(root->rchild);
	}
}

void backtrip(Bnode* root)                  //�����������
{
	if (root)
	{
		backtrip(root->lchild);
		backtrip(root->rchild);
		printf("[%d]", root->data);
	}
}

void numtree(Bnode* root)                    //�������Ĳ�������
{
	static int num = 0;                     //���ڴ��浱ǰ���� 
	if (root)
	{
		num++;
		if (num > maxnum)
			maxnum = num;
		numtree(root->lchild);
		numtree(root->rchild);
		num--;
	}
}

int nodenumber(Bnode* root)                   //��������������
{
	static int nodenum=0;                     //����������
	if (root)
	{
		nodenum++;
		nodenumber(root->lchild);
		nodenumber(root->rchild);
	}
	return nodenum;
}

int main()
{
	int num,nodenum;
	int a[10] = { 23,43,56,25,26,42,63,74,6,27 }; //����һ���������
	int len = 10, i = 0;
	Bnode* root=NULL;                          //����һ��������root==NULL
	for (i = 0; i < len; i++)
		root=treein(root, a[i]);               //������в���ڵ㣨�������������С�����˳����룩
	printf("���������");
	midtrip(root);                             //�������root��
	printf("\n");
	printf("���������");                
	fronttrip(root);                           //�������root��
	printf("\n");
	printf("���������");                      
	backtrip(root);                            //��������root��
	printf("\n");
	printf("������ȣ�");                    
	maxnum = 0;                                //��ʼ������Ϊ0
	numtree(root);                             //�������Ĳ���
	printf("%d",maxnum);                       //������Ĳ���
	printf("\n");
	printf("���ĸ�����");
	nodenum=nodenumber(root);                  //���������
	printf("%d", nodenum);                     //���������
	return 0;
}