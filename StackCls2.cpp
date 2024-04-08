//[Main.cpp]
#include "Stack.h"

void main()
{
	Stack aStack = Stack();		// Create Stack
	while (1) {
		int Error(char *sMsg);
		Item nItem;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		else if (nItem == -1) {
			if (aStack.Pop(nItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", nItem);
		}
		else {
			if (aStack.Push(nItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", nItem);
		}
		aStack.Print();
	}
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}

[Stack.h]
#include <stdio.h>

#define N 10
#pragma warning (disable: 4326 4996 6031)

int Error(const char* sMsg);

typedef	int	Item;

class Stack {
	// m_arItems
	// m_nTop
	// constructor
	// IsEmpty
	// IsFull
	// Push
	// Pop
	// Print
};

//[Stack.cpp]
#include "Stack.h"

int Stack::IsEmpty()
{	// ������ ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Stack::IsFull()
{	// ������ ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Stack::Push(Item nItem)
{	// ���ÿ� nItem�� push�ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Stack::Pop(Item& nItem)
{	// ���ÿ��� pop�Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

void Stack::Print()
{
	printf("|    |\n");
	for (int i = m_nTop; i >= 0; i--)
		printf("|%3d |\n", m_arItems[i]);
	printf("+----+\n\n");
}
