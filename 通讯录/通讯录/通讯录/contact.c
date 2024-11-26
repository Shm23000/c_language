#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


void initcontact(contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}//初始化通讯录


void addcontact(contact* pc)
{
	assert(pc);
	if (pc->count == 100)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("请输入名字\n");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄\n");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("增加成功\n");
}//增加信息


void showcontact(const contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}//展示通讯录内容


void delcontact(contact* pc)//删除通讯录信息
{
	char name[maxname] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，没有内容可以删除\n");
		return;
	}
	printf("请输入要删除人的名字\n");
	scanf("%s", name);
	//删除
	//1.查找
	int pos = findbyname(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2.删除(所谓删除就是后面的元素向前覆盖,那最后一个咋办总不能越界访问吧，所以就是i<pc->count-1,给count-1，就不会越界
	// 那最后一个咋办，答案是count--，直接就不给你访问这个的资格，不得不说pg这里的操作妙呀)
	for (int i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
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


void searchcontact(contact* pc)//查找信息
{
	assert(pc);
	char name[maxname] = { 0 };
	printf("请输入要查找人的名字\n");
	scanf("%s", name);
	int pos = findbyname(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


void modifycontact(contact* pc)//修改指定联系人
{
	//查找
	assert(pc);
	char name[maxname] = { 0 };
	printf("请输入要修改人的名字\n");
	scanf("%s", name);
	int pos = findbyname(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	//修改
	printf("要修改的联系人已找到，开始修改\n");
	printf("请输入名字\n");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄\n");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别\n");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功\n");
}


int comperbyname(const void* e1, const void* e2)
{
	return strcmp(((peoinfo*)e1)->name, ((peoinfo*)e2)->name);
}
void sortcontact(contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(peoinfo), comperbyname);
	printf("排序成功\n");
}