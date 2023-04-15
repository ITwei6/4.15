#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void _mergesort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_mergesort(a, begin, mid, tmp);
	_mergesort(a, mid + 1, end, tmp);
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
//void _mergesort(int* a, int begin, int end, int*tmp )
//{
//	if (begin >= end)
//		return;
//	//1.先对序列分割--分成两边
//	int mid = (begin + end) / 2;
//	//不断的分割一分二，二分四……，左序列不断分，右序列不断分
//	_mergesort(a, begin, mid,tmp);//左序列分割---子区间递归分割
//	_mergesort(a, mid + 1, end,tmp);//右序列分割
//
//	//分割完后归并
//	// 【begin,mid】[mid,end]归并
//	//表示两个要合并的区间
	//int begin1 = begin, end1 = mid;
	//int begin2 = mid + 1, end2 = end;
	//int i = begin;
	//while (begin1<=end1&&begin2<=end2)
	//{
	//	if (a[begin1] < a[begin2])
	//		tmp[i++] = a[begin1++];
	//	else
	//	{
	//		tmp[i++] = a[begin2++];
	//	}
	//}
	//while (begin1 <= end1)
	//{
	//	tmp[i++] = a[begin1++];
	//}
	//while (begin2 <= end2)
	//{
	//	tmp[i++] = a[begin2++];
	//}
	////将合并好的数再拷贝回去
	////不一定在左边区间，所以要拷贝区间取决于begin的位置，
	////不加begin就一直拷贝左边区间
	//memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
//}

void mergesortNor(int* a,int n,int*tmp)
{
	int gap = 1;//表示每次合并的个数
	while (gap < n)
	{
	
	for (int i = 0; i < n; i += 2 * gap)
	{
		int begin1 = i, end1 = i + gap - 1;
		int begin2 = i + gap, end2 = i + 2 * gap - 1;
		int j = i;
		while (begin1 <= end1 && begin2 <= end2)
		{
			if (a[begin1] < a[begin2])
				tmp[j++] = a[begin1++];
			else
			{
				tmp[j++] = a[begin2++];
			}
		}
		while (begin1 <= end1)
		{
			tmp[j++] = a[begin1++];
		}
		while (begin2 <= end2)
		{
			tmp[j++] = a[begin2++];
		}
		//将合并好的数再拷贝回去
		//不一定在左边区间，所以要拷贝区间取决于begin的位置，
		//不加begin就一直拷贝左边区间
		memcpy(a , tmp, sizeof(int) * n);
	}
	gap *= 2;
	}

}
void mergesort(int* a, int n)//归并排序--非递归【恶心问题之边界修正】
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc");
	}
	mergesortNor(a, n, tmp);
}
int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(a) / sizeof(a[0]);
	mergesort(a,n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}