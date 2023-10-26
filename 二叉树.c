#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maxnum;                                   //全局变量，储存树的层数

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}Bnode;


Bnode* treein(Bnode* root, int value)         //结点插入函数
{
	Bnode* back=NULL;            //currut的父结点
	Bnode* currut;               //插入结点
	Bnode* newnode;              //新节点
	newnode = (Bnode*)malloc(sizeof(Bnode));
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->data = value;       //赋值给新结点
	if (!root)                   //root为空数，新结点即为根结点
		root = newnode;
	else
	{
		currut = root;
		while (currut != NULL)              //使currut指向要插入结点位置
		{
			back = currut;
			if (currut->data > value)
				currut = currut->lchild;
			else
				currut = currut->rchild;
		}
		if (back->data > value)             //利用back结点插入新结点
			back->lchild = newnode;
		else
			back->rchild = newnode;
	}
	return root;
}

void midtrip(Bnode* root)                   //中序遍历函数    
{
	if(root)
	{
		midtrip(root->lchild);
		printf("[%d]", root->data);
		midtrip(root->rchild);
	}
}

void fronttrip(Bnode* root)                 //先序遍历函数
{
	if (root)
	{
		printf("[%d]", root->data);
		fronttrip(root->lchild);
		fronttrip(root->rchild);
	}
}

void backtrip(Bnode* root)                  //后序遍历函数
{
	if (root)
	{
		backtrip(root->lchild);
		backtrip(root->rchild);
		printf("[%d]", root->data);
	}
}

void numtree(Bnode* root)                    //计算数的层数函数
{
	static int num = 0;                     //用于储存当前层数 
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

int nodenumber(Bnode* root)                   //计算结点数量函数
{
	static int nodenum=0;                     //储存结点数量
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
	int a[10] = { 23,43,56,25,26,42,63,74,6,27 }; //建立一组测试数据
	int len = 10, i = 0;
	Bnode* root=NULL;                          //创建一个空树，root==NULL
	for (i = 0; i < len; i++)
		root=treein(root, a[i]);               //向空树中插入节点（按从中序遍历从小到大的顺序插入）
	printf("中序遍历：");
	midtrip(root);                             //中序遍历root树
	printf("\n");
	printf("先序遍历：");                
	fronttrip(root);                           //先序遍历root树
	printf("\n");
	printf("后序遍历：");                      
	backtrip(root);                            //后续遍历root树
	printf("\n");
	printf("树的深度：");                    
	maxnum = 0;                                //初始话层数为0
	numtree(root);                             //计算树的层数
	printf("%d",maxnum);                       //输出树的层数
	printf("\n");
	printf("结点的个数：");
	nodenum=nodenumber(root);                  //计算结点个数
	printf("%d", nodenum);                     //输出结点个数
	return 0;
}