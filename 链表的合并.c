#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int num;
    struct Node* next;
    struct Node* prior;
}Node;

void printllist(Node* head)       //双向循环链表的输出
{
    Node* ptr;
    ptr = head->next;              /*  指向真正的起始   */
    while (ptr != head)          /*  链表遍历循环     */
    {
        printf("[%d]", ptr->num);    /*  输出结点数据    */
        ptr = ptr->next;            /*  指向下一结点    */
    }
    printf("\n");                  /*  换行           */
}

Node* createllist(int* array, int len)  //双向循环链表的创建
{
    Node* head;                     /*  链表的开始指针   */
    Node* ptr;
    Node* ptr1;
    int i;
    /* 建立开头结点 */
    head = (Node*)malloc(sizeof(Node));  /*  分配内存  */
    if (!head)                       /*    检查指针      */
        return NULL;
    ptr = head;                    /* 将ptr指向链表开始 */
    for (i = 0; i < len; i++)    /* 建立其它结点回路  */
    {
        ptr1 = (Node*)malloc(sizeof(Node));
        if (!ptr1)
            return NULL;
        ptr1->num = array[i];      /* 建立结点内容      */
        ptr1->prior = ptr;
        ptr->next = ptr1;          /* 连接结点          */
        ptr = ptr->next;           /* 指向下一结点      */
    }
    ptr->next = head;
    head->prior = ptr;
    return head;
}

Node* recombinellist(Node* head1, Node* head2)   //将两个非递减的链表合并成非递增链表的函数
{
    Node*ptr1,*ptr2,*ptr;
    ptr = head1;
    ptr1 = head1->prior;
    ptr2 = head2->prior;
    while (ptr1 != head1 && ptr2 != head2)
        if (ptr1->num >= ptr2->num)
        {
            ptr->next = ptr1;
            ptr1 = ptr1->prior;
            ptr1->next->prior = ptr;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = ptr2;
            ptr2 = ptr2->prior;
            ptr2->next->prior = ptr;
            ptr = ptr->next;
        }
    if(ptr1==head1)                              //将后续结点补上
        while(ptr2!=head2)
        {
            ptr->next = ptr2;
            ptr2 = ptr2->prior;
            ptr2->next->prior = ptr;
            ptr = ptr->next;
        }
    else
        while (ptr1 != head1)
        {
            ptr->next = ptr1;
            ptr1 = ptr1->prior;
            ptr1->next->prior = ptr;
            ptr = ptr->next;
        }
    head1->prior = ptr;
    ptr->next = head1;
    return head1;
}

int main()
{
    Node* head1, * head2, * head;
    int a[6] = { 1,2,5,6,6,9 };
    int b[6] = { 4,4,6,8,9,10 };
    head1 = createllist(a, 6);
    head2 = createllist(b, 6);                //创建两个非递减的双向循环链表
    printf("原链表1：");
    printllist(head1);
    printf("原链表2：");
    printllist(head2);
    head=recombinellist(head1,head2);
    printf("合并后的链表：");
    printllist(head);
	return 0;
}