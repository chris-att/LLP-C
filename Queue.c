#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#define limit 600

queue* loadQueue(queue* myQueue)
{
	int ch;
	FILE* fp;
	fp = fopen("C:\\Users\\attac129\\OneDrive\\Documents\\MCAST\\MCAST BSCSD MQF LVL6\\BSCSD_YR1\\Low Level Programming\\Home Assignment\\Home_Assignment\\numbers.txt.txt", "r");
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
	scanf_s("%d", &numToAdd);
	if (enque(myQueue, createNode(numToAdd)) == false)
	{
		printf("\n We were unable to add extra items to the queue.");
	}
	getchar();
}

void moreToServe(queue* myQueue)
{
	printf("\n%d more nodes to serve.", myQueue->size);
	getchar();
}

void exit()
{
	return 0;
}

void menu(queue* myQueue)
{
	int inputQ1 = 0;
	printf("\tMain Menu\n1. Load Queue\n2. Next Please!\n3. Add to Queue\n4. Show Queue\n5. How many more to serve?\n6. Exit\n\n Enter your choice: ");
	scanf_s("%d", &inputQ1);
	switch (inputQ1)
	{
	case 1: loadQueue(myQueue);
		getchar();
		system("cls"); 
		menu(myQueue);
	case 2: nextPlease(myQueue); 
		getchar();
		system("cls");
		menu(myQueue);
	case 3: addToQueue(myQueue);
		getchar();
		system("cls"); 
		menu(myQueue);
	case 4: showQueue(myQueue); 
		getchar();
		getchar();
		system("cls"); 
		menu(myQueue);
	case 5: moreToServe(myQueue); 
		getchar();
		system("cls"); 
		menu(myQueue);
	case 6: break; exit();
	default: printf("\nIncorrect choice .. now exiting.\n");
		getchar();
		system("cls");
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

