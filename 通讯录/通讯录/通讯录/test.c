#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contact.h"
void menu()
{
	printf("******************************\n");
	printf("****  1.添加      2.删除    **\n");
	printf("****  3.查找      4.修改    **\n");
	printf("****  5.显示      6.排序    **\n");
	printf("****  0.退出                **\n");
	printf("******************************\n");
}
int main()
{
	int input = 0;
	contact con;//通讯录
	initcontact(&con);
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			addcontact(&con);
			break;
		case 2:
			delcontact(&con);
			break;
		case 3:
			searchcontact(&con);
			break;
		case 4:
			modifycontact(&con);
			break;
		case 5:
			showcontact(&con);
			break;
		case 6:
			sortcontact(&con);
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}