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
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Queue::CanNotShift()
{	// �� ������ ������ �����͸� �̵���Ű�µ� ť�� ���� ���ο� ���� T/F�� ��ȯ�Ѵ�.
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
