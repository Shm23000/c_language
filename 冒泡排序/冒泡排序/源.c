#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void maopao(int arr[], int sz)
{
	int i = 0;
	while (i < sz - 1)
	{
		int j = 0;
		while (j < sz - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				int jhgj = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = jhgj;
			}
			j++;
		}
		i++;
	}

}
int main()
{

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	maopao(arr, sz);
	while (i < sz)
	{
		printf("%d", arr[i]);
		i++;
	}
	return 0;
}
//�ұ�����뷨��ͨ��scanf������¼��������飬���ǣ�vsҪ����������ó������������鲻ͬ�Ļ����͸Ĵ�����������