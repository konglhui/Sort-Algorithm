// SortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SortHelper.h"
#include "Sort.h"


int main()
{

    std::cout << "Hello World!\n";
	int a = 0;
	SortHelper::SortTestFunc(SortAlgorithm::SelectSort, 1000, "选择排序");
}
