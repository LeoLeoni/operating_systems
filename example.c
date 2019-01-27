#include <stdio.h>

int main() {

	int pid;
	int ppid;
	char name[50];

	fgets(name, sizeof(name), stdin);
	
	while(scanf("%d %d", &pid, &ppid) !=EOF) {

		fgets(name, sizeof(name), stdin);
		printf("%d %s %s", pid, ppid, name);
	}
}
