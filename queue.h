#pragma once
typedef struct nodeRec
{
	int item;
	struct nodeRec* next;
} node;

typedef node* nodePtr;

typedef struct queue
{
	node* Head;
	node* Tail;
	int size;
	int limit;
} queue;

queue* createQueue(int limit)
{
	queue* myQueue = (queue*)malloc(sizeof(queue));
	myQueue->limit = limit;
	myQueue->size = 0;
	myQueue->Head = NULL;
	myQueue->Tail = NULL;
	return myQueue;
}

node* createNode(int item)
{
	node* newNode = (node*)malloc(sizeof(nodePtr));
	newNode->item = item;
	return newNode;
}

bool enque(queue* myQueue, node* newNode)
{
	if ((myQueue == NULL) || (newNode == NULL) || (myQueue->size >= myQueue->limit))
	{
		return false;
	}
	if (myQueue->size == 0)
	{
		myQueue->Head = newNode;
		myQueue->Tail = newNode;
		myQueue->size++;
		return true;
	}
	else
	{
		myQueue->Tail->next = newNode;
		myQueue->Tail = myQueue->Tail->next;
		myQueue->Tail->next = NULL;
		myQueue->size++;
		return true;
	}
	
}

bool isEmpty(queue* myQueue)
{
	if ((myQueue == NULL) || (myQueue->size != 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool deque(queue* myQueue)
{
	int itemToReturn = 0;
	if (isEmpty(myQueue) == true)
	{
		printf("\nThere are no nodes in the list.");
		return false;
	}
	else
	{
		itemToReturn = myQueue->Head->item;
		myQueue->Head = myQueue->Head->next;
		myQueue->size--;
		printf("\nThe next node is: %d", itemToReturn);
		return true;
	}
}

void showQueue(queue* myQueue)
{
	if (isEmpty(myQueue) == true)
	{
		printf("\nThere are no nodes in the list.");
	}
	int forLoop = myQueue->size;
	printf("\nDisplaying queue ..");
	for (int i = 0; i < forLoop; i++)
	{
		deque(myQueue);
	}
}

int queueSize(queue* myQueue)
{
	if (myQueue->size > 0)
	{
		return myQueue->size;
	}
	else if (myQueue->size == 0)
	{
		return 0;
	}
	else if (myQueue == NULL)
	{
		return -1;
	}
}