#include<stdio.h>
#define MAX 1000
struct Data
{
	char name[10];
	char sex[5];
	int age;
	int tele[12];
};
struct info
{
	struct Data data[MAX];//����û���Ϣ
	int size;//�Ѵ���û�����
};
void InitialContact(struct info* ptr);
void ContactAdd(struct info* ptr);
void ContactSub(struct info* ptr);
void ContactSearch(const struct info* ptr);
void ContactModify(struct info* ptr);
void ContactShow(const struct info* ptr);
void ContactSort(struct info* ptr);