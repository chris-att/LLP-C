#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#define limit 600
//-
queue* loadQueue(queue* myQueue)
{
	free(myQueue);
	myQueue = createQueue(limit);
	int ch;
	FILE* fp;
	fp = fopen("/home/attac129/Documents/workspace/LLP-C/LLP-C/Other Files/numbers", "r");
	if (!fp) //fp is null report error
	{
		printf("Error opening file");
	}
	else //file opened without errors
	{
		while (fscanf(fp, "%d", &ch) == 1) //get ch from file
		{
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

void menu(int inputQ1, queue* myQueue)
{
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
	case 4: showQueue(myQueue->Head);
		getchar();
		getchar();
		system("clear");
		break;
	case 5: moreToServe(myQueue);
		getchar();
		system("clear");
		break;
	case 6: break; exitProgram();
	default: printf("\nIncorrect choice .. now exiting.\n");
		getchar();
		getchar();
		system("clear");
		break;
	}
}

int main(void)
{
	queue* myQueue = createQueue(limit);
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

