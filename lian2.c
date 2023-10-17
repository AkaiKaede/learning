#include<stdio.h>
#include<stdlib.h>

typedef struct Node                       /* ����ṹ����      */
{
    int num;                        /* ������          */
    struct Node* next;             /* ָ����      */
}Node;

void printllist(Node* head)       //��������
{
    while (head!= NULL)          /*  �������ѭ��     */
    {
        printf("[%d]", head->num);    /*  ����������    */
        head = head->next;            /*  ָ����һ���    */
    }
    printf("\n");                  /*  ����           */
}

Node* createllist(int* array, int len)  //����Ĵ���
{
    Node* head;                     /*  ����Ŀ�ʼָ��   */
    Node* ptr;
    Node* ptr1;
    int i;
    /* ������ͷ��� */
    head = (Node*)malloc(sizeof(Node));  /*  �����ڴ�  */
    if (!head)                       /*    ���ָ��      */
        return NULL;
    ptr = head;
    ptr->num = array[0];     
    ptr->next = NULL;
    for (i = 1; i < len; i++)    /* ������������·  */
    {
        ptr1 = (Node*)malloc(sizeof(Node));
        if (!ptr1)
            return NULL;
        ptr1->num = array[i];      /* �����������      */
        ptr1->next = NULL;         /* �趨ָ���ֵ      */
        ptr->next = ptr1;          /* ���ӽ��          */
        ptr = ptr->next;           /* ָ����һ���      */
    }
    return head;
}

Node* insertnode(Node* head, int loc, int value)    //����Ľ�����
{
    int i = 0;
    Node* Mnew, * ptr;
    ptr = head;
    Mnew = (Node*)malloc(sizeof(Node));  /* �����½�� */
    if (!Mnew)
        return NULL;
    Mnew->num = value;              /* �����������      */
    Mnew->next = NULL;              /* �趨ָ���ֵ      */
    if (loc == 1)
    {
        Mnew->next = head;
        head = Mnew;
    }
    else
    {
        for (i = 0; i < loc - 2; i++)
            ptr = ptr->next;           //������ָ�����Ҫ�������ǰһ���
        Mnew->next = ptr->next;
        ptr->next = Mnew;
    }
    return head;
}

Node* deletenode(Node* head, int loc)            //����Ľ��ɾ��
{
    int i;
    Node* ptr, * ptr1;
    ptr = head;
    if (loc == 1)
    {
        head = head->next;
        free(ptr);
    }
    else
    {
        for (i = 0; i < loc - 2; i++)
            ptr = ptr->next;
        ptr1 = ptr->next;
        ptr->next = ptr1->next;
        free(ptr1);
    }
}
int findllist(Node* head, int loc)              //����Ĳ���
{
    int i;
    Node* ptr;
    ptr = head;
    for (i = 0; i < loc-1; i++)
        ptr = ptr->next;
    return ptr->num;
}

void main()
{
    int a;
    int llist1[6] = { 1, 2, 3, 4, 5, 6 };   /*��������   */
    Node* head;                          /* ָ������ʼ      */
    head = createllist(llist1, 6);       /* ��������         */
    if (!head)
    {
        printf("�ڴ����ʧ��! \n");
        exit(1);
    }
    printllist(head);               /* �������      */
    head=insertnode(head, 1, 0); /* �����½��      */
    if (!head)
    {
        printf("�ڴ����ʧ��! \n");
        exit(1);
    }
    printllist(head);               /*    ��������Ľ��    */
    deletenode(head, 4);
    printllist(head);              /*    ���ɾ����Ľ��    */
    a = findllist(head, 3);          //���ҵ���������ֵ���ظ�a
    printf("%d", a);
}