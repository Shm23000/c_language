#pragma once
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define max 100
#define maxname 20
#define maxsex 10
#define maxtele 12
#define maxaddr 30

//�˵���Ϣ
typedef struct peoinfo
{
	char name[maxname];
	int age;
	char sex[maxsex];
	char tele[maxtele];
	char addr[maxaddr];
}peoinfo;

//ͨѶ¼
typedef struct contact
{
	peoinfo data[100];//����˵���Ϣ
	int count;//ͨѶ¼���˵ĸ���
}contact;

void initcontact(contact* pc);//��ʼ��ͨѶ¼

void addcontact(contact* pc);//������Ϣ

void showcontact(const contact* pc);//��ӡͨѶ¼�е���Ϣ

void delcontact(contact* pc);//ɾ��ͨѶ¼�е�����

int findbyname(contact* pc, char name);//�������ֲ�����Ϣ�ĺ���

void searchcontact(contact* pc);//����ָ����ϵ��

void modifycontact(contact* pc);//�޸�ָ����ϵ��

void sortcontact(contact* pc);//ͨ����������ϵ�˽�������