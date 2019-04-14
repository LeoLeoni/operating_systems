//gcc skew.c -o skew --std=c99
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//arg error
	if (argc != 4)
	{
		fprintf(stderr, "usage: ./skew <filename.dat> <skew | interleaving> <offset>\n");
		return 1;
	}
	
	char *filename = argv[1];
	char *mode = argv[2];
	int offset = atoi(argv[3]);

	//io error check
	FILE *in = fopen(filename, "r");
	if (in == NULL)
	{
		fprintf(stderr, "File does not exist\n");
		return 1;
	}
	
	//buffer to write 
	char buf[10000];
  
	size_t linelen = -1;
	int linecount = 0;
  
	while (fgets(buf, 100, in) != NULL)
	{
		//check that the line lengths are all equal: if not, exit; otherwise, continue
		if (linelen == -1) //should only be true for first loop
		{
			linelen = strlen(buf) - 1;
		}
		else
		{
			size_t l = strlen(buf) - 1;
			if (linelen != l)
			{
				fprintf(stderr, "File has varying line lengths. All lines must be the same length\n");
				return 1;
			}
		}
		
		//correct skew mode
		if (strcmp(mode, "skew") == 0)
		{
			//calculate the skew
			int skew = linecount * offset;
			if (skew > linelen)
			{
				skew -= linelen;
			}
		 
			char newline[linelen];
			//place each skew character in front
			for (int i = 0; i < skew; i++)
			{
				newline[i] = buf[linelen - skew + i];
			}
			//place each subsequent character in the back
			for (int i = 0; i < linelen - skew; i++)
			{
				newline[skew + i] = buf[i];
			}
			//print the line char by char
			for (int i = 0; i < linelen; i++) printf("%c", newline[i]);
			printf("\n");
		}
		//interleaving mode
		else if (strcmp(mode, "interleaving") == 0)
		{
			int lineiterations = 0;
			int currentindex = 0;
			char newline[linelen];
			int o = offset + 1;
			for (int i = 0; i < linelen; i++)
			{
				if (currentindex >= linelen)
				{
					lineiterations++;
					currentindex = lineiterations;
				}
				 
				newline[currentindex] = buf[i];
				 
				currentindex += o;
			}
			//print the array
			for (int i = 0; i < linelen; i++)
			{
				printf("%c", newline[i]);
			}
			printf("\n");
		}
		linecount++;	 
	}
	printf("\n")
	return 0;
}
