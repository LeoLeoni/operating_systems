#include <stdio.h>
#include <stdlib.h>

struct node {
	int pid;
	int ppid;
	struct node *children[10];
	int size;
	int depth;
};

struct node root;
struct node *here = &root;
struct node *visited[50];

int check(int ppid);

int main() {
	
	int pid; //id of the process
	int ppid; //id of the parent
	
	char name[50]; //name of the process
	
	
	root.pid = 1;
	root.ppid = 0;
	root.size = 0;
	root.depth = 0;
	visited[0] = &root;
	int visitdepth = 1;

	fgets(name, sizeof(name), stdin);
	
	while(scanf("%d %d", &pid, &ppid) !=EOF) {

		fgets(name, sizeof(name), stdin);
		//look in here's children
		if (check(ppid) != 1000) {
			here = here->children[check(ppid)];
		}
			//back up as needed
			while (ppid != here->pid && visitdepth !=0) {
				visited[visitdepth] = NULL;
				visitdepth--;
				//here->depth--;
				here = visited[visitdepth];
			}
			struct node newNode;
			newNode.pid = pid;
			newNode.ppid = ppid;
			newNode.depth = here->depth+1;
			newNode.size = 0;
			here->children[here->size] = &newNode;
			visited[visitdepth] = &newNode;
			visitdepth++;
			here->size++;
	
		//this is the part that prints the "tree"
		for (int i=0;i<newNode.depth;i++) printf("%s", ">");
		printf("%d %s", here->pid, name);
		//here = here->children[here->size-1];
	}

}

int check(int ppid) {
	//checks the children of here to see if one of their id's matches a given ppid
	//returns the index of that child if it does
	for (int i=0;i<here->size;i++) {
		if (ppid == here->children[i]->pid) return i;
	}
	return 1000;
}