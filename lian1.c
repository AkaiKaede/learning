#include<stdio.h>
#include<stdlib.h>

typedef struct Node                       /* 链表结构声明      */
{
    int num;                        /* 数据域          */
    struct Node* next;             /* 指针域      */
}Node;

void printllist(Node* head)       //链表的输出
{
    Node* ptr;
    ptr = head->next;              /*  指向真正的起始   */
    while (ptr != NULL)          /*  链表遍历循环     */
    {
        printf("[%d]", ptr->num);    /*  输出结点数据    */
        ptr = ptr->next;            /*  指向下一结点    */
    }
    printf("\n");                  /*  换行           */
}
 
Node* createllist(int* array, int len)  //链表的创建
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
        ptr1->next = NULL;         /* 设定指针初值      */
        ptr->next = ptr1;          /* 连接结点          */
        ptr = ptr->next;           /* 指向下一结点      */
    }
    return head;
}
 
void insertnode(Node* head, int loc, int value)    //链表的结点插入
{
    int i = 0;
    Node* Mnew,*ptr;    
    ptr = head;
    Mnew = (Node*)malloc(sizeof(Node));  /* 建立新结点 */
    if (!Mnew)
        return NULL;
    Mnew->num = value;              /* 建立结点内容      */
    Mnew->next = NULL;              /* 设定指针初值      */
    for (i = 0; i < loc - 1; i++)
        ptr = ptr ->next;           //将工作指针遍历要插入结点的前一结点
    Mnew->next = ptr->next;
    ptr->next = Mnew;
}
 
void deletenode(Node* head, int loc)            //链表的结点删除
{
    int i;
    Node* ptr,*ptr1;
    ptr = head;
    for (i = 0; i < loc-1; i++)
        ptr = ptr->next;
    ptr1 = ptr->next;
    ptr->next = ptr1->next;
    free(ptr1);                     
}
int findllist(Node* head, int loc)              //链表的查找
{
    int i;
    Node* ptr;
    ptr = head;
    for (i = 0; i < loc; i++)
        ptr = ptr->next;
    return ptr->num;
}
 
void main()
{
    int a;
    int llist1[6] = { 1, 2, 3, 4, 5, 6 };   /*数组内容   */
    Node* head;                          /* 指向链表开始      */
    head = createllist(llist1, 6);       /* 建立链表         */
    if (!head)
    {
        printf("内存分配失败! \n");
        exit(1);
    }
    printllist(head);               /* 输出链表      */
    insertnode(head, 2, 0); /* 插入新结点      */
    if (!head)
    {
        printf("内存分配失败! \n");
        exit(1);
    }
    printllist(head);               /*    输出插入后的结果    */
    deletenode(head, 4);
    printllist(head);              /*    输出删除后的结果    */
    a=findllist(head, 3);          //查找第三个结点的值返回给a
    printf("%d", a);
}