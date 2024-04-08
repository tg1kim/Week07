//[Main]
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
	// m_nAddDel
	// constructor
	// IsEmpty
	// IsFull
	// Add
	// Delete
	// Print
};

[Queue.cpp]
#include "Queue.h"

int Queue::IsEmpty()
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Queue::IsFull()
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Queue::Add(Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Queue::Delete(Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

void Queue::Print()
{
	int nCtr = (m_nRear - m_nFront + N) % N;
	nCtr += IsFull() * N;
	for (int i = 1; i <= nCtr; i++)
		printf("--%d-", (m_nFront + i) % N);
	printf("--\n");
	for (int i = 1; i <= nCtr; i++)
		printf("%3d ", m_arItems[(m_nFront + i) % N]);
	printf("\n");
	for (int i = 1; i <= nCtr; i++)
		printf("----");
	printf("--\n\n");
}
