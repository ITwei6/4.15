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
//	//1.�ȶ����зָ�--�ֳ�����
//	int mid = (begin + end) / 2;
//	//���ϵķָ�һ�ֶ��������ġ����������в��Ϸ֣������в��Ϸ�
//	_mergesort(a, begin, mid,tmp);//�����зָ�---������ݹ�ָ�
//	_mergesort(a, mid + 1, end,tmp);//�����зָ�
//
//	//�ָ����鲢
//	// ��begin,mid��[mid,end]�鲢
//	//��ʾ����Ҫ�ϲ�������
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
	////���ϲ��õ����ٿ�����ȥ
	////��һ����������䣬����Ҫ��������ȡ����begin��λ�ã�
	////����begin��һֱ�����������
	//memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
//}

void mergesortNor(int* a,int n,int*tmp)
{
	int gap = 1;//��ʾÿ�κϲ��ĸ���
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
		//���ϲ��õ����ٿ�����ȥ
		//��һ����������䣬����Ҫ��������ȡ����begin��λ�ã�
		//����begin��һֱ�����������
		memcpy(a , tmp, sizeof(int) * n);
	}
	gap *= 2;
	}

}
void mergesort(int* a, int n)//�鲢����--�ǵݹ顾��������֮�߽�������
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