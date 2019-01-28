#include <stdio.h>
#include <stdlib.h>

struct node {
	int pid;
	int ppid;
	int ppid_index;
	struct node *children[10];
	struct node *parent;
	int size;
	int depth;
};

struct node root;
struct node *here = &root;
struct node *visited[10];

int check(int ppid);

int main() {
	
	int pid; //id of the process
	int ppid; //id of the parent
	
	char name[50]; //name of the process
	
	
	root.pid = 1;
	root.ppid = 0;
	root.size = 0;
	root.depth = 0;
	root.parent = NULL;
	visited[0] = &root;
	int visitdepth = 1;

	fgets(name, sizeof(name), stdin);
	
	while(scanf("%d %d", &pid, &ppid) !=EOF) {

		fgets(name, sizeof(name), stdin);
		//look in here's children
		if (check(ppid) != 1000) {
			here = here->children[check(ppid)];
		}
			
			while (ppid != here->pid && visitdepth !=0) {
				//printf("%s", "backing up\n");
				visited[visitdepth] = NULL;
				
				visitdepth--;here = visited[visitdepth];
			}
			struct node newNode;
			newNode.pid = pid;
			newNode.ppid = ppid;
			newNode.ppid_index = here->size;
			newNode.parent = here;
			newNode.depth = here->depth+1;
			newNode.size = 0;
			here->children[here->size] = &newNode;
			visited[visitdepth] = &newNode;
			here->size++;
	
		for (int i=0;i<newNode.depth;i++) printf("%s", ">");
		printf("%d %d %s", here->pid, here->ppid, name);
		here = here->children[here->size-1];
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