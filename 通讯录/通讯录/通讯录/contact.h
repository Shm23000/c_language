#pragma once
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define max 100
#define maxname 20
#define maxsex 10
#define maxtele 12
#define maxaddr 30

//人的信息
typedef struct peoinfo
{
	char name[maxname];
	int age;
	char sex[maxsex];
	char tele[maxtele];
	char addr[maxaddr];
}peoinfo;

//通讯录
typedef struct contact
{
	peoinfo data[100];//存放人的信息
	int count;//通讯录中人的个数
}contact;

void initcontact(contact* pc);//初始化通讯录

void addcontact(contact* pc);//增加信息

void showcontact(const contact* pc);//打印通讯录中的信息

void delcontact(contact* pc);//删除通讯录中的数据

int findbyname(contact* pc, char name);//根据名字查找信息的函数

void searchcontact(contact* pc);//查找指定联系人

void modifycontact(contact* pc);//修改指定联系人

void sortcontact(contact* pc);//通过姓名对联系人进行排序