#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contact.h"
void menu()
{
	printf("******************************\n");
	printf("****  1.���      2.ɾ��    **\n");
	printf("****  3.����      4.�޸�    **\n");
	printf("****  5.��ʾ      6.����    **\n");
	printf("****  0.�˳�                **\n");
	printf("******************************\n");
}
int main()
{
	int input = 0;
	contact con;//ͨѶ¼
	initcontact(&con);
	do
	{
		menu();
		printf("��ѡ��\n");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}