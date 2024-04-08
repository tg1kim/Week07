//[Main.cpp]
#include "Queue.h"

void main()
{
	int Error(char *sMsg);
	Queue aQueue = Queue();		// Create Queue
	Queue *pQ = &aQueue;
	while (1) {
		int nItem;
		printf("-2:Exit -1:Delete, *:Add ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		else if (nItem == -1) {
			if (pQ->Delete(nItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", nItem);
		}
		else {
			if (pQ->Add(nItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", nItem);
		}
		pQ->Print();
	}
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}

//[Queue.h]
#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define N 10

int Error(const char* sMsg);

typedef int Item;

class Queue {
	// m_arItems
	// m_nFront
	// m_nRear
	// constructor
	// IsEmpty
	// CanNotShift
	// IsFull
	// Add
	// Delete
	// Print
};

[Queue.cpp]
#include "Queue.h"

int Queue::IsEmpty()
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return true;
}

int Queue::CanNotShift()
{	// 빈 공간이 있으면 데이터를 이동시키는데 큐의 가득 여부에 따라 T/F를 반환한다.
	return true;
}

int Queue::IsFull()
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	return true;
}

int Queue::Add(Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	return true;
}

int Queue::Delete(Item& nItem)
{	// 큐에서 삭제하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	return true;
}

void Queue::Print()
{
	for (int i = m_nFront + 1; i <= m_nRear; i++)
		printf("--%d-", i);
	printf("--\n");
	for (int i = m_nFront + 1; i <= m_nRear; i++)
		printf("%3d ", m_arItems[i]);
	printf("\n");
	for (int i = m_nFront + 1; i <= m_nRear; i++)
		printf("----");
	printf("--\n\n");
}
