#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
#define Exit 0
#define Add 1
#define Sub 2
#define Search 3
#define Modify 4
#define Show 5
#define Sort 6
void menu()
{
	printf("################################################\n");
	printf("#####   0:Exit    1:Add    2:Sub   #############\n");
	printf("#####   3:Search  4:Modify  5��Show  ###########\n");
	printf("############  6:Sort######################\n");
	printf("################################################\n");
}

int main()
{
	//����һ��ͨѶ¼��people����ͨѶ¼������һǧ��Ԫ�ص������size
	struct info people;
	//��ʼ��ͨѶ¼��Ϣ
	InitialContact(&people);
	int input;
	do {
		//��ӡ�˵�
		menu();
		printf("��ѡ��->");
		scanf("%d",&input);
		switch(input)
		{
		case Exit:
			printf("�˳�ͨѶ¼\n");
			break;
		case Add:
			ContactAdd(&people);
			break;
		case Sub:
			ContactSub(&people);
			break;
		case Search:
			ContactSearch(&people);
			break;
		case Modify:
			ContactModify(&people);
			break;
		case Show:
			ContactShow(&people);
			break;
		case Sort:
			ContactSort(&people);
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}