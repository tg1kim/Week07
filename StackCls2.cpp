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
{	// 스택이 비었는지에 따라 T/F를 반환한다.
	return true;
}

int Stack::IsFull()
{	// 스택이 가득 찼는지에 따라 T/F를 반환한다.
	return true;
}

int Stack::Push(Item nItem)
{	// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
	return true;
}

int Stack::Pop(Item& nItem)
{	// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	return true;
}

void Stack::Print()
{
	printf("|    |\n");
	for (int i = m_nTop; i >= 0; i--)
		printf("|%3d |\n", m_arItems[i]);
	printf("+----+\n\n");
}
