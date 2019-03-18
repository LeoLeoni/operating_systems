#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 100

char buf[BUF_SIZE];

void *printStuff()
{	
	while (1)
	{
		//print the things, then wait before printing again
		printf("%c", '\n');
		for(int hiddenCount = 0; buf[hiddenCount]; hiddenCount++)
		{
			for(int wordCount = 0; buf[wordCount]; wordCount++)
			{
				if(hiddenCount == wordCount) printf("%c", '@');
				else printf("%c", buf[wordCount]);
			}
			printf("%c", '\n');
		}
		usleep(2000000);
	}
}

void *processInput()
{
	gets(buf);
}

int main(int argc, char* argv[])
{
	//spawn one thread to do input and one thread for output
	pthread_t printThread;
	pthread_t inputThread;

	while (1)
	{
		//spawn the input thread first since we need input
		pthread_create(&inputThread, NULL, processInput, NULL);
		
		//wait for the input thread to complete before doing anything else
		//if an output thread is running it will continue to run alongside the input thread
		pthread_join(inputThread, NULL);

		//cancel any existing output threads before making a new one
		pthread_cancel(printThread);
		pthread_create(&printThread, NULL, printStuff, NULL);
	}
	return 0;
}