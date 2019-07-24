#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>

namespace SortHelper
{
	//生成随机数数组
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


	//生成部分随机数数组
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




	//测试结果正确性
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



	//测试排序函数正确性
	//template<typename T> 
	void SortTestFunc(void(*sort)(int[], int),int n,std::string sortName) 
	{
		//生成数据
		int* arr = GeneratorArray(n, 0, n);
		//int* arr = GeneratorRandomArray(n, 0, n);

		//统计时间
		auto start = std::chrono::steady_clock::now();
		sort(arr, n);
		auto end = std::chrono::steady_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		for (int i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;


		//打印结果
		if (TestSortCorrect(arr, n))
			std::cout << sortName << ":" << "结果正确" << std::endl;
		else
			std::cout << sortName << ":" << "结果错误" << std::endl;

		std::cout << sortName << " 算法耗时"<< ":" << time.count() * 1000 <<"ms" << std::endl;
		return;
	}



}
