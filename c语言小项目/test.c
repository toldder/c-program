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
	printf("#####   3:Search  4:Modify  5：Show  ###########\n");
	printf("############  6:Sort######################\n");
	printf("################################################\n");
}

int main()
{
	//创建一个通讯录，people就是通讯录，包含一千个元素的数组和size
	struct info people;
	//初始化通讯录信息
	InitialContact(&people);
	int input;
	do {
		//打印菜单
		menu();
		printf("请选择->");
		scanf("%d",&input);
		switch(input)
		{
		case Exit:
			printf("退出通讯录\n");
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
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}