//gcc raid.c -o raid --std=c99
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	//argc error check
	if (argc != 5)
	{
		fprintf(stderr, "usage: ./raid <0 | 1> <filename> <numdisks> <blocksize>\n");
		return 1;
	}

	int raidType = atoi(argv[1]);
	char *filename = argv[2];
	int numDisks = atoi(argv[3]);
	int blockSize = atoi(argv[4]);

	//argument format error check
	if (raidType != 0 && raidType != 1)
	{
		fprintf(stderr, "error: RAID type must be 0 or 1\n");
		return 1;
	}
	else if (numDisks < 1 || numDisks > 9)
	{
		fprintf(stderr, "error: number of disks must be 1-9\n");
		return 1;
	}
	else if (blockSize < 1 || blockSize > 512)
	{
		fprintf(stderr, "error: block size must be 1-512\n");
		return 1;
	}

	//io error check
	FILE *in = fopen(filename, "r");
	if (in == NULL)
	{
		fprintf(stderr, "error: file does not exist\n");
		return 1;
	}

	//buffer to write
	char buf[10000];

	while (fgets((buf), 1000, in) != NULL)
	{

	}

	return 0;
}