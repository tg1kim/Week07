#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define N 10

typedef int Item;

typedef struct {
	Item items[N];
	int nFront;
	int nRear;
}	Queue, *QueuePtr;

void main()
{
	int  IsEmptyQueue(QueuePtr pQueue);
	int  IsFullQueue(QueuePtr pQueue);
	int  AddQueue(QueuePtr aQueue, Item nItem);
	int  DeleteQueue(QueuePtr aQueue, Item& anItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = -1;
	while (1) {
		int nItem;
		printf("-2:Exit -1:Delete, 0~:Add ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		if (nItem == -1) {
			if (DeleteQueue(&aQueue, nItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", nItem);
		}
		else {
			if (AddQueue(&aQueue, nItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", nItem);
		}
		PrintQueue(&aQueue);
	}
}

int IsEmptyQueue(QueuePtr pQueue)
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return pQueue->nFront == pQueue->nRear;
}

int IsFullQueue(QueuePtr pQueue)
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	int CanNotShift(QueuePtr pQueue);
	if (pQueue->nFront == pQueue->nRear && pQueue->nFront != -1)
		pQueue->nFront = pQueue->nRear = -1;
	return pQueue->nRear == N - 1 && CanNotShift(pQueue);
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFullQueue(pQueue))
		return false;
	pQueue->items[++pQueue->nRear] = nItem;		// rear�� �����Ͽ� ����
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmptyQueue(pQueue))
		return false;
	nItem = pQueue->items[++pQueue->nFront];	// front�� �����Ͽ� �޾Ƴ�
	return true;
}

int CanNotShift(QueuePtr pQueue)
{	// ���ʿ� �� ������ ������ �����͸� �̵���Ű�µ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (pQueue->nFront == -1)
		return true;
	int nTo = 0;
	for (int nFr = pQueue->nFront + 1; nFr <= pQueue->nRear; nTo++, nFr++)
		pQueue->items[nTo] = pQueue->items[nFr];
	pQueue->nRear = nTo;
	pQueue->nFront = -1;
	return false;
}

void PrintQueue(QueuePtr pQueue)
{
	for (int i = pQueue->nFront + 1; i <= pQueue->nRear; i++)
		printf("--%d-", i);
	printf("--\n");
	for (int i = pQueue->nFront + 1; i <= pQueue->nRear; i++)
		printf("%3d ", pQueue->items[i]);
	printf("\n");
	for (int i = pQueue->nFront + 1; i <= pQueue->nRear; i++)
		printf("----");
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
