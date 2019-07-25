#pragma once
#include <list>

using namespace std;

class  Node
{
public:
	int value;
	Node* front;
	Node* next;
};


int cmp(const void* a, const void* b)

{

	return *(int*)a - *(int*)b;  //升序排序

  //return *(int *)b - *(int *)a; //降序排序

  /*可见：参数列表是两个空指针，现在他要去指向你的数组元素。所以转型为你当前的类型，然后取值。

		  升序排列时，若第一个参数指针指向的“值”大于第二个参数指针指向的“值”，则返回正；若第一个参数指针指向的“值”等于第二个参数指针指向的“值”，则返回零；若第一个参数指针指向的“值”小于第二个参数指针指向的“值”，则返回负。

		  降序排列时，则刚好相反。

  */

}

class MyList:public Node
{
private:
	Node* front;
	Node* back;

	size_t size;

	Node* medianNode;


public:
	MyList()
	{

	}

	MyList(int* values, int len):size(len)
	{
		Node* temp = front;
		std::qsort(values, len, 4, cmp);
		for (int i = 0; i < len; i++)
		{
			temp->next->value = values[i];
			temp = temp->next;
		}
		temp->next = back;

		//
		medianNode = getMedianlist();
	}

	Node* getMedianlist()
	{
		if (medianNode != nullptr)
			return medianNode;
		else
		{
			medianNode = front;
			for (int i = 0; i < size/2; i++)
			{
				medianNode = medianNode->next;
			}
		}
	}



	int moveAndGetResult(int left, int right)
	{
		get
		return a;
	}





	size_t getSize()
	{
		return size;
	}

	Node* getFront()
	{
		return front;
	}

	Node* getBack()
	{
		return back;
	}



};
