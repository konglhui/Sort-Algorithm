#pragma once
#include <algorithm>

namespace SortAlgorithm
{

	//—°‘Ò≈≈–Ú
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
}