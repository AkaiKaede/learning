#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int num;
    struct Node* next;
    struct Node* prior;
}Node;

void printllist(Node* head)       //˫��ѭ����������
{
    Node* ptr;
    ptr = head->next;              /*  ָ����������ʼ   */
    while (ptr != head)          /*  �������ѭ��     */
    {
        printf("[%d]", ptr->num);    /*  ����������    */
        ptr = ptr->next;            /*  ָ����һ���    */
    }
    printf("\n");                  /*  ����           */
}

Node* createllist(int* array, int len)  //˫��ѭ������Ĵ���
{
    Node* head;                     /*  ����Ŀ�ʼָ��   */
    Node* ptr;
    Node* ptr1;
    int i;
    /* ������ͷ��� */
    head = (Node*)malloc(sizeof(Node));  /*  �����ڴ�  */
    if (!head)                       /*    ���ָ��      */
        return NULL;
    ptr = head;                    /* ��ptrָ������ʼ */
    for (i = 0; i < len; i++)    /* ������������·  */
    {
        ptr1 = (Node*)malloc(sizeof(Node));
        if (!ptr1)
            return NULL;
        ptr1->num = array[i];      /* �����������      */
        ptr1->prior = ptr;
        ptr->next = ptr1;          /* ���ӽ��          */
        ptr = ptr->next;           /* ָ����һ���      */
    }
    ptr->next = head;
    head->prior = ptr;
    return head;
}

Node* recombinellist(Node* head1, Node* head2)   //�������ǵݼ�������ϲ��ɷǵ�������ĺ���
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
    if(ptr1==head1)                              //��������㲹��
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
    head2 = createllist(b, 6);                //���������ǵݼ���˫��ѭ������
    printf("ԭ����1��");
    printllist(head1);
    printf("ԭ����2��");
    printllist(head2);
    head=recombinellist(head1,head2);
    printf("�ϲ��������");
    printllist(head);
	return 0;
}