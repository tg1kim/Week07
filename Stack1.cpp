#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define N 10

typedef int Item;

void main()
{
	int  IsEmptyStack(int nTop);
	int  IsFullStack(int nTop);
	int  Push(Item aStack[], int& nTop, Item nItem);
	int  Pop(Item aStack[], int& nTop, Item& nItem);
	void PrintStack(Item aStack[], int nTop);
	int  Error(const char *sMsg);

	/** Create Stack **/
	Item aStack[N];
	int nTop;

	nTop = -1;
	while (1) {
		Item nItem;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		if (nItem == -1) {
			if (Pop(aStack, nTop, nItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", nItem);
		}
		else {
			if (Push(aStack, nTop, nItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", nItem);
		}
		PrintStack(aStack, nTop);
	}
}

int IsEmptyStack(int nTop)
{	// ������ ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int IsFullStack(int nTop)
{	// ������ ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Push(Item aStack[], int& nTop, Item nItem)
{	// ���ÿ� nItem�� push�ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// top�� �����Ͽ� ����
	return true;
}

int Pop(Item aStack[], int& nTop, Item& nItem)
{	// ���ÿ��� pop�Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// �޾Ƴ��� top�� ����
	return true;
}

void PrintStack(Item aStack[], int nTop)
{
	printf("|    |\n");
	for (int i = nTop; i >= 0; i--)
		printf("|%3d |\n", aStack[i]);
	printf("+----+\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
