#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define N 	10
#define	ADD	1
#define	DELETE	2

typedef int Item;

typedef struct {
	Item items[N];
	int nFront;
	int nRear;
	int nAddDel;
}	Queue, *QueuePtr;

void main()
{
	int  IsEmptyQueue(QueuePtr pQueue);
	int  IsFullQueue(QueuePtr pQueue);
	int  AddQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item *pItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = 0;
	aQueue.nAddDel = DELETE;
	while (1) {
		int nItem;
		printf("-2:Exit -1:Delete, 0~:Add ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		else if (nItem == -1) {
			if (DeleteQueue(&aQueue, &nItem) == false)
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
	return pQueue->nFront == pQueue->nRear && pQueue->nAddDel == DELETE;
}

int IsFullQueue(QueuePtr pQueue)
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return pQueue->nRear == pQueue->nFront && pQueue->nAddDel == ADD;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFullQueue(pQueue))
		return false;
	pQueue->items[pQueue->nRear = (pQueue->nRear + 1) % N] = nItem;	// rear�� �����Ͽ� ����
	pQueue->nAddDel = ADD;
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item *pItem)
{	// ť���� �����Ͽ� pItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmptyQueue(pQueue))
		return false;
	*pItem = pQueue->items[pQueue->nFront = (pQueue->nFront + 1) % N];	// front�� �����Ͽ� �޾Ƴ�
	pQueue->nAddDel = DELETE;
	return true;
}

void PrintQueue(QueuePtr pQueue)
{
	int nCtr = (pQueue->nRear - pQueue->nFront + N) % N;
	nCtr += IsFullQueue(pQueue) * N;
	for (int i = 1; i <= nCtr; i++)
		printf("--%d-", (pQueue->nFront + i) % N);
	printf("--\n");
	for (int i = 1; i <= nCtr; i++)
		printf("%3d ", pQueue->items[(pQueue->nFront + i) % N]);
	printf("\n");
	for (int i = 1; i <= nCtr; i++)
		printf("----");
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
