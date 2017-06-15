#pragma once
/*How a node will be represented on the queue*/
typedef struct nodeRec
{
	int item;
	struct nodeRec* next;
} node;

/*Defining node**/
typedef node* nodePtr;

/*The structure on the queue*/
typedef struct queue
{
	node* Head;
	node* Tail;
	int size;
} queue;

void clearBuffer()
{
	int buffer = 0;
	while ((buffer = getchar()) != '\n' && buffer != EOF)
	{
	
	}
}

queue* createQueue()
{
	/*Allocates memory for a new Queue and sets pointers*/
	queue* myQueue = (queue*)malloc(sizeof(queue));
	if(myQueue == NULL)
	{
		return NULL;
	}
	myQueue->size = 0;
	myQueue->Head = NULL;
	myQueue->Tail = NULL;
	return myQueue;
}

nodePtr createNode(int item)
{
	/*Creates a new node from an integer. Returns pointer*/
	if((item == (int)NULL) || item < -2147483648 || item > 2147483647)
	{
		return NULL;
	}
	else
	{	
		nodePtr newNode = (node*)malloc(sizeof(nodePtr));
		if(newNode == NULL)
		{
			return NULL;
		}
		newNode->item = item;
		return newNode;
	}
}

bool enque(queue* myQueue, node* newNode)
{
	if ((myQueue == NULL) || (newNode == NULL))
	{
		return false;
	}
	/*Handling the instance of enqueueing onto an empty queue*/
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
	/*Returns true if the queue is empty*/
	if ((myQueue == NULL) || (myQueue->size != 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool deque(queue* myQueue, int* dequeuedValue)
{
	/*Services one item from the queue*/
	if (isEmpty(myQueue) == true)
	{
		return false;
	}
	else
	{	
		*dequeuedValue = myQueue->Head->item;
		
		/*Freeing the memory of the dequeued value*/
		nodePtr headCurrent = myQueue->Head;
		nodePtr headNext = myQueue->Head->next;
		free(headCurrent);
		
		myQueue->Head = headNext;
		myQueue->size--;
		
		return true;
	}
}

void showQueue(queue* myQueue)
{
	/*Prints the queue without servicing any of the nodes.*/
	if(myQueue->size == 0)
	{
		printf("\nQueue is empty, nothing to display");
	}
	nodePtr crawler = myQueue->Head; //A crawler node will allow us to traverse the queue
	for(int i = 0; i < myQueue->size; i++)
	{
		printf("%d\n", crawler->item);
		crawler = crawler->next;
	}	
}

int queueSize(queue* myQueue)
{
	if (myQueue->size == 0)
	{
		return 0;
	}
	else
	{
		return (int)myQueue->size;
	}
}

void destroyQueue(queue* myQueue)
{
	/*Freeing memory allocated for all nodes in the current queue*/
	/*Alternatively, this method can call the deque method for size amount of times*/
	for(int i = 0; i < myQueue->size; i++)
	{
		nodePtr headCurrent = myQueue->Head;
		nodePtr headNext = myQueue->Head->next;
		free(headCurrent);
		
		myQueue->Head = headNext;
	}	
	
	free(myQueue); //freeing the memory of the current queue
}