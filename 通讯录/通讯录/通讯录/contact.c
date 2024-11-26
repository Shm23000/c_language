#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


void initcontact(contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}//��ʼ��ͨѶ¼


void addcontact(contact* pc)
{
	assert(pc);
	if (pc->count == 100)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����������\n");
	scanf("%s", pc->data[pc->count].name);
	printf("����������\n");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("���ӳɹ�\n");
}//������Ϣ


void showcontact(const contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}//չʾͨѶ¼����


void delcontact(contact* pc)//ɾ��ͨѶ¼��Ϣ
{
	char name[maxname] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û�����ݿ���ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵�����\n");
	scanf("%s", name);
	//ɾ��
	//1.����
	int pos = findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2.ɾ��(��νɾ�����Ǻ����Ԫ����ǰ����,�����һ��զ���ܲ���Խ����ʰɣ����Ծ���i<pc->count-1,��count-1���Ͳ���Խ��
	// �����һ��զ�죬����count--��ֱ�ӾͲ��������������ʸ񣬲��ò�˵pg����Ĳ�����ѽ)
	for (int i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}


int findbyname(contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


void searchcontact(contact* pc)//������Ϣ
{
	assert(pc);
	char name[maxname] = { 0 };
	printf("������Ҫ�����˵�����\n");
	scanf("%s", name);
	int pos = findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


void modifycontact(contact* pc)//�޸�ָ����ϵ��
{
	//����
	assert(pc);
	char name[maxname] = { 0 };
	printf("������Ҫ�޸��˵�����\n");
	scanf("%s", name);
	int pos = findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	//�޸�
	printf("Ҫ�޸ĵ���ϵ�����ҵ�����ʼ�޸�\n");
	printf("����������\n");
	scanf("%s", pc->data[pos].name);
	printf("����������\n");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pos].sex);
	printf("������绰\n");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pos].addr);
	printf("�޸ĳɹ�\n");
}


int comperbyname(const void* e1, const void* e2)
{
	return strcmp(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
}
void sortcontact(contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(peoinfo), comperbyname);
	printf("����ɹ�\n");
}