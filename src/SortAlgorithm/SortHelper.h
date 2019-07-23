#pragma once
#include <iostream>
#include <ctime>
#include <string>
namespace SortHelper
{
	int* GeneratorArray(int n, int downNum, int upNum) 
	{
		int* a = new int[n];
		std::srand((int)time(nullptr));
		for (int i = 0; i < n; i++) 
		{
			a[i] = rand() % (upNum - downNum) + downNum;
		}
		return a;
	}

	//���Խ����ȷ��
	template <typename T>
	bool TestSortCorrect(T arr[],int n)
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = i; j < n; j++) 
			{
				if (arr[i] > arr[j])
					return false;
			}
		}
		return true;
	}


	//������������ȷ��
	//template<typename T> 
	void SortTestFunc(void(*sort)(int[], int),int n,std::string sortName) 
	{
		int* arr = GeneratorArray(n, 0, n);
		sort(arr, n);
		if (TestSortCorrect(arr, n))
			std::cout << sortName << ":" << "�����ȷ" << std::endl;
		else
			std::cout << sortName << ":" << "�������" << std::endl;
		return;
	}

}
