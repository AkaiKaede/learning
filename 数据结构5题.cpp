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

void meun()                                //����˵�
{
    printf("|-----------------------------------------|\n");
    printf("|      ��ӭ�����༶ѧ����Ϣ����ϵͳ       |\n");
    printf("|-----------------------------------------|\n");
    printf("|              0.�˳�                     |\n");
    printf("|              1.¼��ѧ����Ϣ             |\n");
    printf("|              2.����ѧ����Ϣ             |\n");
    printf("|              3.ɾ��ѧ����Ϣ             |\n");
    printf("|              4.��ѧ�Ŷ�ѧ����Ϣ�������� |\n");
    printf("|              5.����ѧ����Ϣ             |\n");
    printf("|              6.���ѧ����Ϣ             |\n");
    printf("|-----------------------------------------|\n");
    printf("��������Ҫִ�еĲ�����");
}

void printllist(Node* head)       //˫��ѭ����������
{
    Node* ptr;
    ptr = head->next;              /*  ָ����������ʼ   */
    printf("\n");
    printf("|------------------------------------------ѧ����Ϣ--------------------------------------------------------|\n");
    printf("|ѧ��\t\t����\t�Ա�\t����\t�༶\t\n");
    while (ptr != head)          /*  �������ѭ��     */
    {
        printf("|%s\t%s\t%s\t%d\t%s\n", ptr->id,ptr->name,ptr->sex,ptr->age,ptr->c_lass);    /*  ����������    */
        ptr = ptr->next;            /*  ָ����һ���    */
    }
    printf("|----------------------------------------------------------------------------------------------------------|\n");
    printf("\n");
}

Node* createllist()  //����¼�뺯��
{
    int flag=0;
    Node* head;                     /*  ����Ŀ�ʼָ��   */
    Node* ptr;
    Node* ptr1;
    /* ������ͷ��� */
    head = (Node*)malloc(sizeof(Node));  /*  �����ڴ�  */
    if (!head)                       /*    ���ָ��      */
        return NULL;
    ptr = head;                    /* ��ptrָ������ʼ */
    while(flag==0)    
    {
        printf("������ѧ����Ϣ��ѧ�� ���� �Ա� ���� �༶����");
        ptr1 = (Node*)malloc(sizeof(Node));
        if (!ptr1)
            return NULL;
        scanf("%s%s%s%d%s", ptr1->id, ptr1->name, ptr1->sex, &ptr1->age, ptr1->c_lass);
        ptr1->prior = ptr;
        ptr->next = ptr1;         
        ptr = ptr1;
        printf("¼��ɹ�!����¼������0���������˵�����1��");
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
        printllist(head);                     //������ù���Ա���
        printf("��������Ҫ�����λ�ã�");
        scanf("%d", &loc);
        ptr = head;
        ptr1 = (Node*)malloc(sizeof(Node));   //�����½��
        for (i = 0; i < loc; i++)             //ָ��Ҫ������
            ptr = ptr->next;
        printf("��������Ҫ�����ѧ����Ϣ��ѧ�� ���� �Ա� ���� �༶����");
        scanf("%s%s%s%d%s", ptr1->id, ptr1->name, ptr1->sex, &ptr1->age, ptr1->c_lass);
        ptr1->next = ptr;
        ptr1->prior = ptr->prior;
        ptr->prior->next = ptr1;
        ptr->prior = ptr1;
        printf("����ɹ�!������������0���������˵�����1��");
        scanf("%d", &flag);
    }
}

void deletellist(Node* head)
{
	Node* ptr,*ptr1;
    int loc,i=0,flag=0;
    while(flag==0)
    {
        printllist(head);                     //������ù���Ա���
        printf("��������Ҫɾ������Ϣλ�ã�");
        scanf("%d", &loc);
        ptr = head;
        for (i = 0; i < loc; i++)             //ָ��Ҫɾ���Ľ��
            ptr = ptr->next;
		ptr1=ptr->next;
		ptr->prior->next=ptr1;
		ptr1->prior=ptr->prior;
		free(ptr);
        printf("ɾ���ɹ�!����ɾ������0���������˵�����1��");
        scanf("%d", &flag);
    }
}

void oderllist(Node* head)
{
	int i=0,j=0,length=0,flag=0,x;
	Node* ptr,*ptr1;
	while(flag==0)
	{
        printf("������������0��������������1��");
        scanf("%d", &x);
		ptr=head;
		do
		{
			ptr=ptr->next;
			length++;
		}while(ptr!=head);       //ͳ�����������
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
			if(j==i)                                    //ptrָ���Ϊ���ֵ
			{
				ptr1->next=ptr;
				ptr->prior=ptr1;
				ptr=ptr->next;
			}
		}
		ptr=head;
		for(i=0;i<length-1;i++)                        //��ptrָ�����������һ�����
			ptr=ptr->next;
		ptr->next=head;                                //��ȫѭ������
		head->prior=ptr;
		printf("����ɹ�!������������\n");
		printllist(head);
        printf("������������0���������˵�����1��");
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
        printf("����0��ѧ�Ų��ң�����1���������ң�");
        scanf("%d", &a);
        switch (a)
        {
        case 0:
            printf("��������Ҫ���ҵ�ѧ��ѧ�ţ�");
            scanf("%s", id);
            ptr = head->next;
            printf("|---------------------------------------�����ǲ��ҵ���ѧ����Ϣ---------------------------------------------|\n");
            printf("|ѧ��\t\t����\t�Ա�\t����\t�༶\t\n");
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
                printf("|��Ǹ��δ��ѯ�������ݣ�����ѧ���Ƿ�������ȷ��\n");
            printf("|----------------------------------------------------------------------------------------------------------|\n");
            break;
        case 1:
            printf("��������Ҫ���ҵ�ѧ��������");
            scanf("%s", name);
            ptr = head->next;
            printf("|---------------------------------------�����ǲ��ҵ���ѧ����Ϣ---------------------------------------------|\n");
            printf("|ѧ��\t\t����\t�Ա�\t����\t�༶\t\n");
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
                printf("|��Ǹ��δ��ѯ�������ݣ�����ѧ���Ƿ�������ȷ��|\n");
            printf("|----------------------------------------------------------------------------------------------------------|\n");
            break;
        default:break;
        }
        printf("������������0���������˵�����1��");
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