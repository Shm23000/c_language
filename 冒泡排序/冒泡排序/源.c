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
//我本身的想法是通过scanf函数来录入你的数组，但是，vs要求数组必须用常量，所以数组不同的话，就改代码里的数组吧