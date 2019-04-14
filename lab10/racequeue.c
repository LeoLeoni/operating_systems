#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node
{
	int value;
	struct node *next;
};


int queueSize = 0;          //the number of elements in the queue
int maxSize;                //max size defined by command line args
struct node *head = NULL;   //The head of the queue. The next item out will be the head

//function to allocate space for a new node and return its address
struct node *createNode(int value)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = value;
	newNode->next = NULL;
}

int push (int value)
{	
	if (queueSize == maxSize) return 0;

	struct node *new = createNode(value);
	if (queueSize == 0) head = new;
	else
	{
		struct node* here = head;
		while (here->next != NULL) here = here->next;
		here->next = new;
	}
	queueSize++;
	return 1;
}

int pop()
{
	if (queueSize == 0) return -1;

	int value = head->value;
	head = head->next;
	queueSize--;
	return value;
}

void *raceThread(void* threadno)
{
	int i = *(int*)threadno;
	if (push(i)) printf("%s %i %s", "push(", i, ") success\n");
	else printf("%s %i %s", "push(", i, ") failed\n");

	if (pop() != -1) printf("%i %s", i, " <- pop()\n");
	else printf("pop() failed\n");
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
        printf("%s", "Invalid arguments. Use max queue size as an argument\n");
        return 0;
    }
	maxSize = atoi(argv[1]);
	int numThreads = atoi(argv[2]);

	pthread_t race;
	for (int i=0; i<numThreads; i++)
	{
		int *threadno = malloc(sizeof(*threadno));
		*threadno = i;
		pthread_create(&race, NULL, raceThread, threadno);
	}
	pthread_cancel(race);
	return 0;
}