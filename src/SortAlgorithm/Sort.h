#pragma once
#include <algorithm>

namespace SortAlgorithm
{

	//ѡ������
	template<typename T>
	void SelectSort(T arr[],int n)
	{
		for (int i = 0; i < n; i++) 
		{
			int minIndex = i;
			for (int j = i + 1 ; j < n; j++)
			{
				if (arr[j] < arr[minIndex])
					minIndex = j;
			}
			std::swap(arr[minIndex], arr[i]);
		}
	}

	//��������
	template<typename T>
	void InsertSort(T arr[], int n)
	{
		for (int i = 1; i < n; i++)
		{
			int temp = arr[i]; 
			int j = i - 1;
			for (; j >= 0; j--)
			{
				if (temp < arr[j])
					arr[j + 1] = arr[j];
				else
					break;				
				arr[j] = temp;
			}
		}
	}

	//�Թ鲢���ֺ������ݽ�������
	template <typename T>
	void __MergeSort(T arr[], int l, int r,int median)
	{
		//��������
		T* temp = new T[r - l + 1];
		memcpy(temp, arr, sizeof(T) * (r - l + 1));

		int tempMedian = median - l;
		int tempEnd = r - median;
		int m = 0, n = tempMedian + 1, i = l;

		for ( ; i <= r && m <= tempMedian && n <= tempEnd; i++)
		{
			if (temp[m] < temp[n])
			{
				arr[i] = temp[m];
				m++;
			}
			else
			{
				arr[i] = temp[n];
				n++;
			}
		}

		for (; m <= tempMedian; m++,i++) 
		{
			arr[i] = temp[m];
		}
		for(; n <= tempEnd; n ++,i ++)
		{
			arr[i] = temp[n];
		}

		delete[] temp;
	}


	//˽�й鲢���򷽷��Ķ����࣬[l,r]�����Ǳ�����
	template <typename T>
	void __PMergeSortClassify(T arr[], int l, int r)
	{
		if (l == r)
			return;
		int median = l + (r - l) / 2;
		__PMergeSortClassify(arr, l, median);
		__PMergeSortClassify(arr, median + 1, r);
		__MergeSort(arr, l, r, median);
	}


	template <typename T> 
	void MergeSort(T arr[], int n)
	{
		__PMergeSortClassify(arr, 0, n - 1);
	}


}