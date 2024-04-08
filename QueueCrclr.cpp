#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define N 	10

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
	int  AddQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item *pItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = 0;
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
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return true;
}

int IsFullQueue(QueuePtr pQueue)
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	return true;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	// rear를 증가하여 삽입
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item *pItem)
{	// 큐에서 삭제하여 pItem에 저장하는데 승패에 따라 T/F를 반환한다.
	// front를 증가하여 받아냄
	return true;
}

void PrintQueue(QueuePtr pQueue)
{
	int nCtr = (pQueue->nRear - pQueue->nFront + N) % N;
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
