#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <vector>

namespace SortHelper
{


	static std::vector<int> g_arr;

	//生成随机数数组
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


	//生成部分随机数数组
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




	//测试结果正确性
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



	//测试排序函数正确性
	//template<typename T> 
	void SortTestFunc(void(*sort)(std::vector<int>&),int n,std::string sortName) 
	{
		//生成数据
		if(g_arr.empty())
			g_arr = GeneratorRandomArray(n, 0, n);
		std::vector<int> arr(g_arr);
		
		//int* arr = GeneratorRandomArray(n, 0, n);

		//统计时间
		auto start = std::chrono::steady_clock::now();
		sort(arr);
		auto end = std::chrono::steady_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		//for (int i = 0; i < n; i++) {
		//	std::cout << arr[i] << " ";
		//}
		std::cout << std::endl;


		//打印结果
		if (TestSortCorrect(arr))
			std::cout << sortName << ":" << "结果正确" << std::endl;
		else
			std::cout << sortName << ":" << "结果错误" << std::endl;

		std::cout << sortName << " 算法耗时"<< ":" << time.count() * 1000 <<"ms" << std::endl;
		return;
	}



}
