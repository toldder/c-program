#define _CRT_SECURE_NO_WARNINGS 1
#include<memory.h>
#include "contact.h"
void InitialContact(struct info* ptr)
{
	memset(ptr->data, 0, MAX);
	ptr->size = 0;//���ͨѶ¼������Ϊ0��
}
void ContactAdd(struct info* ptr)
{
	if (ptr->data == MAX)
	{
		printf("ͨѶ¼�����������޷����\n");
	}
	else
	{
		//�������ͨѶ¼��ʵ��
		printf("������������");
		scanf("%s", ptr->data[ptr->size].name);
		printf("�������Ա�");
		scanf("%s", ptr->data[ptr->size].sex );
		printf("���������䣺");
		scanf("%d", &(ptr->data[ptr->size].age));
		printf("������绰��");
		scanf("%s", ptr->data[ptr->size].tele);
		(ptr->size)++;
		printf("��ӳɹ�\n");
	}
}
void ContactShow(const struct info* ptr)
{
	if (ptr->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
      int i;
	  //����
	  printf("%-20s\t%-20s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰");
	  //����
	   for (i = 0; i < ptr->size; i++)
	   {
		   printf("%-20s\t%-20s\t%-20d\t%-20s\n", 
			   (ptr->data[i]).name, (ptr->data[i]).sex, (ptr->data[i]).age, (ptr->data[i]).tele);
	   }
	}
}
//��Ҫ�޸�һ��
void ContactSub(struct info* ptr)
{
	char arr[10];
	printf("��������Ҫɾ�ĵ���ϵ������:");
	scanf("%s", arr);
	int i;
	for (i = 0; i < sizeof((ptr->data[i])); i++)
	{
		if (!strncmp(arr, (ptr->data[i]).name, sizeof((ptr->data[i]).name)))
		{
			break;
		}
	}
	if (i == sizeof(arr))
	{
		printf("δ�ҵ�����ϵ��\n");
	}
	else
	{
		while (i< sizeof(ptr->data[i])-1)
		{
			ptr->data[i] = ptr->data[i + 1];
			i++;
		}
		memset(&(ptr->data[i]), 0, 1);
		ptr->size--;
	}
}
//��Ҫ��װһ�º���
void ContactSearch(struct info* ptr)
{
	char arr[10];
	printf("�����������˵�����\n");
	scanf("%s", arr);
	int i;
	for (i = 0; i < sizeof(ptr->data); i++)
	{
		if (!strncmp(arr, (ptr->data[i]).name, sizeof((ptr->data[i]).name)))
		{
			printf("%-20s\t%-20s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰");
			printf("%-20s\t%-20d\t%-20s\t%-20s\n",
				(ptr->data[i]).name, (ptr->data[i]).sex, (ptr->data[i]).age, (ptr->data[i]).tele);
			return;
		}
	}
	printf("δ�ҵ�����ϵ��");
}
void ContactSort(struct info* ptr)
{
	int m;
	for (m = 1; m < sizeof(ptr->data);m++)//ð����������
	{
		int i;
		int flag = 1;
		for (i = 0; i < sizeof(ptr->data) - m; i++)//ÿ���������������ֱȽϴ���
		{
			if (strcmp((ptr->data[i]).name, (ptr->data[i + 1]).name) < 0)
			{
				int j;
				for (j = 0; j < sizeof((ptr->data[0]).name) - 1; j++)
				{
					char arr[10];
					arr[j] = (ptr->data[i]).name[j];
					(ptr->data[i]).name[j] = (ptr->data[i + 1]).name[j];
					(ptr->data[i + 1]).name[j] = arr[j];
				}
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
void ContactModify(struct info* ptr)
{

}