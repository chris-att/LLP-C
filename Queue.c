#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#define limit 600

queue* loadQueue(queue* myQueue)
{
	free(myQueue);
	myQueue = createQueue(limit);
	int ch;
	FILE* fp;
	fp = fopen("/home/attac129/Documents/LLP_1/LLP-C/numbers", "r");
	if (!fp) //fp is null report error
	{
		printf("Error opening file");
	}
	else //file opened without errors
	{
		while ((ch = getc(fp)) != EOF) //get ch from file
		{
			fscanf(fp, "%d", &ch);
			enque(myQueue, createNode(ch)); // display ch on screen
		}
	}
	fclose(fp);
	return myQueue;
}

void nextPlease(queue* myQueue)
{
	deque(myQueue);
	getchar();
}

void addToQueue(queue* myQueue)
{
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
	printf("\n%d more nodes to serve.", myQueue->size);
	getchar();
}

void clearBuffer()
{
	int buffer = 0;
	while ((buffer = getchar()) != '\n' && buffer != EOF)
	{
		
	}
}

void exitProgram()
{
	exit(0);
}

void menu(queue* myQueue)
{
	int inputQ1 = 0;
	printf("\tMain Menu\n1. Load Queue\n2. Next Please!\n3. Add to Queue\n4. Show Queue\n5. How many more to serve?\n6. Exit\n\n Enter your choice: ");
	scanf("%d", &inputQ1);
	switch (inputQ1)
	{
	case 1: loadQueue(myQueue);
		getchar();
		system("clear");
		menu(myQueue);
	case 2: nextPlease(myQueue); 
		getchar();
		system("clear");
		menu(myQueue);
	case 3: addToQueue(myQueue);
		getchar();
		system("clear");
		menu(myQueue);
	case 4: showQueue(myQueue); 
		getchar();
		getchar();
		system("clear");
		menu(myQueue);
	case 5: moreToServe(myQueue); 
		getchar();
		system("clear");
		menu(myQueue);
	case 6: break; exitProgram();
	default: printf("\nIncorrect choice .. now exiting.\n");
		getchar();
		getchar();
		system("clear");
		menu(myQueue);
	}
}

int main(void)
{
	queue* myQueue = createQueue(limit);
	myQueue = loadQueue(myQueue);
	nodePtr head = myQueue->Head; //points to the start of the queue
	nodePtr tail = myQueue->Tail; //points to the end of the queue
	menu(myQueue);
}

