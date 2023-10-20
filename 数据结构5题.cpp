#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char id[15];
    char name[12];
    char sex[4];
    int age;
    char c_lass[15];
    struct Node* next;
    struct Node* prior;
}Node;

void meun()                                //输出菜单
{
    printf("|-----------------------------------------|\n");
    printf("|      欢迎来到班级学生信息管理系统       |\n");
    printf("|-----------------------------------------|\n");
    printf("|              0.退出                     |\n");
    printf("|              1.录入学生信息             |\n");
    printf("|              2.插入学生信息             |\n");
    printf("|              3.删除学生信息             |\n");
    printf("|              4.按学号对学生信息进行排序 |\n");
    printf("|              5.查找学生信息             |\n");
    printf("|              6.输出学生信息             |\n");
    printf("|-----------------------------------------|\n");
    printf("请输入你要执行的操作：");
}

void printllist(Node* head)       //双向循环链表的输出
{
    Node* ptr;
    ptr = head->next;              /*  指向真正的起始   */
    printf("\n");
    printf("|------------------------------------------学生信息--------------------------------------------------------|\n");
    printf("|学号\t\t姓名\t性别\t年龄\t班级\t\n");
    while (ptr != head)          /*  链表遍历循环     */
    {
        printf("|%s\t%s\t%s\t%d\t%s\n", ptr->id,ptr->name,ptr->sex,ptr->age,ptr->c_lass);    /*  输出结点数据    */
        ptr = ptr->next;            /*  指向下一结点    */
    }
    printf("|----------------------------------------------------------------------------------------------------------|\n");
    printf("\n");
}

Node* createllist()  //数据录入函数
{
    int flag=0;
    Node* head;                     /*  链表的开始指针   */
    Node* ptr;
    Node* ptr1;
    /* 建立开头结点 */
    head = (Node*)malloc(sizeof(Node));  /*  分配内存  */
    if (!head)                       /*    检查指针      */
        return NULL;
    ptr = head;                    /* 将ptr指向链表开始 */
    while(flag==0)    
    {
        printf("请输入学生信息（学号 姓名 性别 年龄 班级）：");
        ptr1 = (Node*)malloc(sizeof(Node));
        if (!ptr1)
            return NULL;
        scanf("%s%s%s%d%s", ptr1->id, ptr1->name, ptr1->sex, &ptr1->age, ptr1->c_lass);
        ptr1->prior = ptr;
        ptr->next = ptr1;         
        ptr = ptr1;
        printf("录入成功!继续录入输入0，返回主菜单输入1：");
        scanf("%d", &flag);
    }
    ptr->next = head;
    head->prior = ptr;
    return head;
}

void insertllist(Node* head)
{
    Node* ptr,*ptr1;
    int loc,i=0,flag=0;
    while(flag==0)
    {
        printllist(head);                     //输出，让管理员浏览
        printf("请输入你要插入的位置：");
        scanf("%d", &loc);
        ptr = head;
        ptr1 = (Node*)malloc(sizeof(Node));   //建立新结点
        for (i = 0; i < loc; i++)             //指向要插入结点
            ptr = ptr->next;
        printf("请输入你要插入的学生信息（学号 姓名 性别 年龄 班级）：");
        scanf("%s%s%s%d%s", ptr1->id, ptr1->name, ptr1->sex, &ptr1->age, ptr1->c_lass);
        ptr1->next = ptr;
        ptr1->prior = ptr->prior;
        ptr->prior->next = ptr1;
        ptr->prior = ptr1;
        printf("插入成功!继续插入输入0，返回主菜单输入1：");
        scanf("%d", &flag);
    }
}

void deletellist(Node* head)
{
	Node* ptr,*ptr1;
    int loc,i=0,flag=0;
    while(flag==0)
    {
        printllist(head);                     //输出，让管理员浏览
        printf("请输入你要删除的信息位置：");
        scanf("%d", &loc);
        ptr = head;
        for (i = 0; i < loc; i++)             //指向要删除的结点
            ptr = ptr->next;
		ptr1=ptr->next;
		ptr->prior->next=ptr1;
		ptr1->prior=ptr->prior;
		free(ptr);
        printf("删除成功!继续删除输入0，返回主菜单输入1：");
        scanf("%d", &flag);
    }
}

void oderllist(Node* head)
{
	int i=0,j=0,length=0,flag=0,x;
	Node* ptr,*ptr1;
	while(flag==0)
	{
        printf("升序排序输入0，降序排序输入1：");
        scanf("%d", &x);
		ptr=head;
		do
		{
			ptr=ptr->next;
			length++;
		}while(ptr!=head);       //统计链表结点个数
		ptr=ptr->next;
		for(i=0;i<length-1;i++)
		{
			ptr1=head;
			for(j=0;j<i;j++)
			{
				ptr1=ptr1->next;
                if(x==0)
				    if(strcmp(ptr->id,ptr1->id)<0)
				    {
					    ptr=ptr->next;
					    ptr->prior->prior=ptr1->prior;
					    ptr->prior->next=ptr1;
					    ptr1->prior->next=ptr->prior;
					    ptr1->prior=ptr->prior;
                        break;
				    }
                if(x==1)
                    if (strcmp(ptr->id, ptr1->id) > 0)
                    {
                        ptr = ptr->next;
                        ptr->prior->prior = ptr1->prior;
                        ptr->prior->next = ptr1;
                        ptr1->prior->next = ptr->prior;
                        ptr1->prior = ptr->prior;
                        break;
                    }
			}
			if(j==i)                                    //ptr指向的为最大值
			{
				ptr1->next=ptr;
				ptr->prior=ptr1;
				ptr=ptr->next;
			}
		}
		ptr=head;
		for(i=0;i<length-1;i++)                        //将ptr指向排序后的最后一个结点
			ptr=ptr->next;
		ptr->next=head;                                //补全循环链表
		head->prior=ptr;
		printf("排序成功!以下是排序结果\n");
		printllist(head);
        printf("重新排序输入0，返回主菜单输入1：");
        scanf("%d", &flag);
	}
}

void findllist(Node* head)
{
    char id[15],name[12];
    int a,flag=0,flag1=0;
    Node* ptr;
    while(flag==0)
    {
        flag1 = 0;
        printf("输入0按学号查找，输入1按姓名查找：");
        scanf("%d", &a);
        switch (a)
        {
        case 0:
            printf("请输入你要查找的学生学号：");
            scanf("%s", id);
            ptr = head->next;
            printf("|---------------------------------------以下是查找到的学生信息---------------------------------------------|\n");
            printf("|学号\t\t姓名\t性别\t年龄\t班级\t\n");
            while (ptr != head)
            {
                if (strcmp(ptr->id, id) == 0)
                {
                    printf("|%s\t%s\t%s\t%d\t%s\n", ptr->id, ptr->name, ptr->sex, ptr->age, ptr->c_lass);
                    flag1 = 1;
                }
                ptr = ptr->next;
            }
            if (flag1 == 0)
                printf("|抱歉，未查询到该数据，请检查学号是否输入正确！\n");
            printf("|----------------------------------------------------------------------------------------------------------|\n");
            break;
        case 1:
            printf("请输入你要查找的学生姓名：");
            scanf("%s", name);
            ptr = head->next;
            printf("|---------------------------------------以下是查找到的学生信息---------------------------------------------|\n");
            printf("|学号\t\t姓名\t性别\t年龄\t班级\t\n");
            while (ptr != head)
            {
                if (strcmp(ptr->name, name) == 0)
                {
                    printf("|%s\t%s\t%s\t%d\t%s\n", ptr->id, ptr->name, ptr->sex, ptr->age, ptr->c_lass);
                    flag1 = 1;
                }
                ptr = ptr->next;
            }
            if (flag1 == 0)
                printf("|抱歉，未查询到该数据，请检查学号是否输入正确！|\n");
            printf("|----------------------------------------------------------------------------------------------------------|\n");
            break;
        default:break;
        }
        printf("继续查找输入0，返回主菜单输入1：");
        scanf("%d", &flag);
    }
}

int main()
{
    Node* head=NULL;
    int a=0;
    while(1)
    {
        meun();
        scanf("%d", &a);
        switch (a)
        {
        case 0:exit(0);
        case 1:head = createllist(); break;
        case 2:insertllist(head); break;
        case 3:deletellist(head); break;
        case 4:oderllist(head); break;
        case 5:findllist(head); break;
        case 6:printllist(head); break;
        }
    }
    return 0;
}