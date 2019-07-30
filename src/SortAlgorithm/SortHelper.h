#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <vector>

namespace SortHelper
{


	static std::vector<int> g_arr;

	//�������������
	std::vector<int> GeneratorRandomArray(int n, int downNum, int upNum)
	{
		std::vector<int> arr;
		arr.reserve(n);
		std::srand((int)time(nullptr));
		for (int i = 0; i < n; i++) 
		{
			arr.push_back(rand() % (upNum - downNum) + downNum);
		}
		return arr;
	}


	//���ɲ������������
	std::vector<int> GeneratorArray(int n, int start, int RandomNum)
	{
		std::vector<int> a;
		a.reserve(n);
		std::srand((int)time(nullptr));
		for (int i = 0; i < n; i++)
		{
			a.push_back(start + i);
		}
		for (int i = 0; i < RandomNum; i++)
		{
			std::swap(a[rand() % (n - 1)], a[rand() % (n - 1)]);
		}
		return a;
	}




	//���Խ����ȷ��
	template <typename T>
	bool TestSortCorrect(std::vector<T> arr)
	{
		int n = arr.size();
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
	void SortTestFunc(void(*sort)(std::vector<int>&),int n,std::string sortName) 
	{
		//��������
		if(g_arr.empty())
			g_arr = GeneratorRandomArray(n, 0, n);
		std::vector<int> arr(g_arr);
		
		//int* arr = GeneratorRandomArray(n, 0, n);

		//ͳ��ʱ��
		auto start = std::chrono::steady_clock::now();
		sort(arr);
		auto end = std::chrono::steady_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		//for (int i = 0; i < n; i++) {
		//	std::cout << arr[i] << " ";
		//}
		std::cout << std::endl;


		//��ӡ���
		if (TestSortCorrect(arr))
			std::cout << sortName << ":" << "�����ȷ" << std::endl;
		else
			std::cout << sortName << ":" << "�������" << std::endl;

		std::cout << sortName << " �㷨��ʱ"<< ":" << time.count() * 1000 <<"ms" << std::endl;
		return;
	}



}
