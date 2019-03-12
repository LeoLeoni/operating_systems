#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 100

char buf[SIZE];

void *printStuff()
{
	int bufSize = sizeof(buf)/sizeof(char);
	
	while (1){
		usleep(2000000);
		for(int hiddenCount = 0; buf[hiddenCount]; hiddenCount++)
		{
			for(int wordCount = 0; buf[wordCount]; wordCount++)
			{
				if(hiddenCount == wordCount) printf("%c", '@');
				else printf("%c", buf[wordCount]);
			}
			printf("%c", '\n');
		}
		printf("%c", '\n');
	}
}

int main(int argc, char* argv[])
{
	//have the main thread process input and the spawned thread process output
	gets(buf);
	pthread_t printThread;

	while(1) {
		pthread_create(&printThread, NULL, printStuff, NULL);
		gets(buf);
		pthread_join(printThread, NULL);
	}
	return 0;
}