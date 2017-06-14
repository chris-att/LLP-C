#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Queue.h"

queue* loadQueue(queue* myQueue)
{
	destroyQueue(myQueue); //frees memory allocated for all nodes and the current queue.
	myQueue = createQueue(); //recreating the queue as requested.
	int ch;
	FILE* fp;
	fp = fopen("/home/attac129/Documents/workspace/LLP-C/LLP-C/Other Files/numbers", "r");
	if (!fp) //fp is null report error
	{
		printf("Error opening file");
	}
	else //file opened without errors
	{
		while (fscanf(fp, "%d", &ch) == 1) //if scanf returns no errors the value read will be enqueued.
		{
			enque(myQueue, createNode(ch)); // display ch on screen
		}
	}
	fclose(fp);
	return myQueue; //return a pointer to myQueue
}

void nextPlease(queue* myQueue)
{	
	int adr = 0;
	/*adr will be a variable on the stack of which its address will be passed to the deque() to processes it there*/
	if(deque(myQueue, &adr))
	{
		printf("\nThe next node is: %d", adr);
	}
	else printf("\nThere are no more nodes to dequeue");
	
	getchar();
}

void addToQueue(queue* myQueue)
{
	/*Adds a new item to the queue passed as a param via the the enqueue()*/
	int numToAdd;
	printf("\nEnter a number to add to queue: ");
	scanf("%d", &numToAdd);
	if (enque(myQueue, createNode(numToAdd)) == false)
	{
		printf("\n We were unable to add extra items to the queue.");
	}
}

void moreToServe(queue* myQueue)
{
	/*Uses myQueue->size as an indicator of items remaining*/
	if(isEmpty(myQueue) == true)
	{
		printf("\nNo more items to serve.");
	}
	else
	{	
		printf("\n%d more nodes to serve.", myQueue->size);
	}
	getchar();
}

void exitProgram()
{
	/*Simply exits program.*/
	exit(0);
}

void menu(int inputQ1, queue* myQueue)
{
	/*Menu handling*/
	switch (inputQ1)
	{
	case 1: loadQueue(myQueue);
		getchar();
		system("clear");
		break;
	case 2: nextPlease(myQueue);
		getchar();
		system("clear");
		break;
	case 3: addToQueue(myQueue);
		getchar();
		system("clear");
		break;
	case 4: showQueue(myQueue);
		getchar();
		getchar();
		system("clear");
		break;
	case 5: moreToServe(myQueue);
		getchar();
		system("clear");
		break;
	case 6: exitProgram(); break;
	default: printf("\nIncorrect choice .. now exiting.\n");
		getchar();
		getchar();
		system("clear");
		break;
	}
}

int main(int argc, char *argv[])
{
	queue* myQueue = createQueue();
	myQueue = loadQueue(myQueue);
	int inputQ1 = 0;
	do
	{
		printf("\tMain Menu\n1. Load Queue\n2. Next Please!\n3. Add to Queue\n4. Show Queue\n5. How many more to serve?\n6. Exit\n\n Enter your choice: ");
		scanf("%d", &inputQ1);
		menu(inputQ1, myQueue);
	}
	while(inputQ1 != 6);
}