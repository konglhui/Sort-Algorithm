// SortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SortHelper.h"
#include "Sort.h"


int main()
{
	int a = 0;
	SortHelper::SortTestFunc(SortAlgorithm::SelectSort, 10000, "选择排序");
	SortHelper::SortTestFunc(SortAlgorithm::InsertSort, 10000, "插入排序");
	SortHelper::SortTestFunc(SortAlgorithm::MergeSort, 10000, "归并排序");


	std::getchar();
	return 0;
}
