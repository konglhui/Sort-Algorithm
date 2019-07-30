#pragma once
#include <algorithm>
#include <vector>
namespace SortAlgorithm
{

	//ѡ������
	template<typename T>
	void SelectSort(std::vector<T>& arr)
	{
		int n = arr.size();
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
	void InsertSort(std::vector<T>& arr)
	{
		int n = arr.size();
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
	void __MergeSort(std::vector<T>& arr, int l, int r, int median)
	{
		//��������
		std::vector<T> temp;
		temp.reserve(r - l + 1);
		std::copy(arr.begin() + l, arr.begin() + r + 1, std::back_inserter(temp));

		int tempMedian = median - l;
		int tempEnd = r - l;
		int m = 0, n = tempMedian + 1, i = l;

		for (; i <= r && m <= tempMedian && n <= tempEnd; i++)
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

		for (; m <= tempMedian; m++, i++)
		{
			arr[i] = temp[m];
		}
		for (; n <= tempEnd; n++, i++)
		{
			arr[i] = temp[n];
		}

	}


	//˽�й鲢���򷽷��Ķ����࣬[l,r]�����Ǳ�����
	template <typename T>
	void __PMergeSortClassify(std::vector<T>& arr, int l, int r)
	{
		if (l == r)
			return;
		int median = l + (r - l) / 2;
		__PMergeSortClassify(arr, l, median);
		__PMergeSortClassify(arr, median + 1, r);
		__MergeSort(arr, l, r, median);
	}


	template <typename T> 
	void MergeSort(std::vector<T>& arr)
	{
		int n = arr.size();
		__PMergeSortClassify(arr, 0, n - 1);
	}

}