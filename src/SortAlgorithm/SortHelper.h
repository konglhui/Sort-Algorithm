#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>

namespace SortHelper
{
	//�������������
	int* GeneratorRandomArray(int n, int downNum, int upNum) 
	{
		int* a = new int[n];
		std::srand((int)time(nullptr));
		for (int i = 0; i < n; i++) 
		{
			a[i] = rand() % (upNum - downNum) + downNum;
		}
		return a;
	}


	//���ɲ������������
	int* GeneratorArray(int n, int start, int RandomNum)
	{
		int* a = new int[n];
		std::srand((int)time(nullptr));
		for (int i = 0; i < n; i++)
		{
			a[i] = start + i;
		}
		for (int i = 0; i < RandomNum; i++)
		{
			std::swap(a[rand() % (n - 1)], a[rand() % (n - 1)]);
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
		//��������
		int* arr = GeneratorArray(n, 0, n);
		//int* arr = GeneratorRandomArray(n, 0, n);

		//ͳ��ʱ��
		auto start = std::chrono::steady_clock::now();
		sort(arr, n);
		auto end = std::chrono::steady_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		for (int i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;


		//��ӡ���
		if (TestSortCorrect(arr, n))
			std::cout << sortName << ":" << "�����ȷ" << std::endl;
		else
			std::cout << sortName << ":" << "�������" << std::endl;

		std::cout << sortName << " �㷨��ʱ"<< ":" << time.count() * 1000 <<"ms" << std::endl;
		return;
	}



}
