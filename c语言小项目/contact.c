#define _CRT_SECURE_NO_WARNINGS 1
#include<memory.h>
#include "contact.h"
void InitialContact(struct info* ptr)
{
	memset(ptr->data, 0, MAX);
	ptr->size = 0;//最初通讯录的人数为0；
}
void ContactAdd(struct info* ptr)
{
	if (ptr->data == MAX)
	{
		printf("通讯录人数已满，无法添加\n");
	}
	else
	{
		//具体添加通讯录的实现
		printf("请输入姓名：");
		scanf("%s", ptr->data[ptr->size].name);
		printf("请输入性别：");
		scanf("%s", ptr->data[ptr->size].sex );
		printf("请输入年龄：");
		scanf("%d", &(ptr->data[ptr->size].age));
		printf("请输入电话：");
		scanf("%s", ptr->data[ptr->size].tele);
		(ptr->size)++;
		printf("添加成功\n");
	}
}
void ContactShow(const struct info* ptr)
{
	if (ptr->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
      int i;
	  //标题
	  printf("%-20s\t%-20s\t%-20s\t%-20s\n", "名字", "性别", "年龄", "电话");
	  //数据
	   for (i = 0; i < ptr->size; i++)
	   {
		   printf("%-20s\t%-20s\t%-20d\t%-20s\n", 
			   (ptr->data[i]).name, (ptr->data[i]).sex, (ptr->data[i]).age, (ptr->data[i]).tele);
	   }
	}
}
//需要修改一下
void ContactSub(struct info* ptr)
{
	char arr[10];
	printf("请输入需要删改的联系人姓名:");
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
		printf("未找到该联系人\n");
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
//需要封装一下函数
void ContactSearch(struct info* ptr)
{
	char arr[10];
	printf("请输入搜索人的姓名\n");
	scanf("%s", arr);
	int i;
	for (i = 0; i < sizeof(ptr->data); i++)
	{
		if (!strncmp(arr, (ptr->data[i]).name, sizeof((ptr->data[i]).name)))
		{
			printf("%-20s\t%-20s\t%-20s\t%-20s\n", "名字", "性别", "年龄", "电话");
			printf("%-20s\t%-20d\t%-20s\t%-20s\n",
				(ptr->data[i]).name, (ptr->data[i]).sex, (ptr->data[i]).age, (ptr->data[i]).tele);
			return;
		}
	}
	printf("未找到该联系人");
}
void ContactSort(struct info* ptr)
{
	int m;
	for (m = 1; m < sizeof(ptr->data);m++)//冒号排序趟数
	{
		int i;
		int flag = 1;
		for (i = 0; i < sizeof(ptr->data) - m; i++)//每个数字与其他数字比较次数
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