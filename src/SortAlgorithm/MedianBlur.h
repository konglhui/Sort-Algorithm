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
	return *(int*)a - *(int*)b;  
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
