#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void initHeap(int size);
int malloc1(int req);
void free1();
void view(int usedRegions); //view choice
void coalesce();
int choose(); //handles user choice


typedef struct __node_t {

    int size;
    int free;
    struct __node_t *next;
} node_t;


node_t *head = NULL;


int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("%s", "Invalid arguments. Use size as an argument\n");
        return 0;
    }
    int heapSize = atoi(argv[1]);
    head = malloc(heapSize);
    head->size = heapSize;
    head->free = 1; 

    int usedSpace = 0;
    int usedRegions = 0;
    int freeRegions= 1;


    while (1) {
        printf("%s %i %s %i", "\nheap: ", &head, ", 0, size=", heapSize);
        
        int choice = choose();

        switch (choice) {

            case 1: //malloc
                printf("%s", "ENTER THE SIZE IN BYTES: ");
                int size;
                scanf("%d", &size);
                int mal = malloc1(size);
                if (mal) {
                    usedSpace += size + 16;
                    usedRegions++;
                }
                break;

            case 2: //free
                free1();
                break;

            case 3: //coalesce
                coalesce();
                break;

            case 4: //view
                view(usedRegions);
                break;

            case 5: //quit
                return 0;
                break;

            default: //quit
                printf("%s", "Invalid input\n");
            return 0;
                break;
        }
    }

    return 0;
}

void coalesce() {
    node_t *current = head;

    //there is probably an easier way to do this
    if (current->next != NULL) {
        if (current->free == 1 && current->next->free == 1) {
            current->size += current->next->size;
            if (current->next->next==NULL) {current->next = NULL;}
            else {current->next = current->next->next;}
        }
    }

    while(current->next != NULL) {
        current = current->next;
        if (current->free == 1 && current->next->free == 1) {
            current->size += current->next->size;
            if (current->next->next==NULL) {current->next = NULL;}
            else {current->next = current->next->next;}
        }
    }
}


int malloc1(int req) {
    // allocate memory from within the heap for N bytes

    
    node_t *currentent = head;

    while (currentent->size < req+4 && currentent->free==1) {
        currentent = currentent->next;
        if (currentent==NULL) {
            printf("%s", "Error");
            break;
        }
    }

    currentent->size = currentent->size - req - 16;

    //create node for used region
    node_t *prev = malloc(sizeof(node_t));
    prev->next = NULL;
    prev->size = req;
    prev->free = 0;


    //build new header
    while(currentent->next != NULL) {
        currentent = currentent->next;
    }
    currentent -> next = prev;


    //hold the old data
    node_t * old = malloc(sizeof(node_t));
    old = currentent;
    currentent += req + 4; //increment pointer
    //head = currentent;
    return 1;
}

void free1() {

    node_t * currentent = head;
    int offset = 0;
    int nodeCount = 0;

    //traverses the whole list
    while (currentent != NULL) {

        //we only want the used regions
        if(currentent->free == 0) {

            printf("%d.vAddr=%p, offset=%d, size=%d, free=%d, \n", nodeCount, currentent, offset, currentent->size, currentent->free);
            offset+= (currentent->size + 16); 
            nodeCount++;
        }
        currentent = currentent->next;
    }


    printf("SELECT NODE TO FREE: ");
    int choice;
    scanf("%d",&choice);

    currentent = head;
    for (int i=0; i<=choice; i++) {

        currentent = currentent->next;
    }
    currentent->free = 1;
}


void view(int usedRegions) {


    printf("%s", "Traversing linked list of free regions...\n");

    node_t * currentent = head;
    int offset = 0;
    int nodeCount = 0;

    //traverses the whole list
    while (currentent != NULL) {

        printf("%d.vAddr=%p, offset=%d, size=%d, free=%d, \n", nodeCount, currentent, offset, currentent->size, currentent->free);
        offset+= (currentent->size + 16); 
        nodeCount++;
    
        currentent = currentent->next;
    }


}

int choose(){

    printf("%s", "\n\nALLOCATOR: ENTER AN OPTION\n  1. malloc\n  2. free\n  3. coalesce\n  4. view\n  5. quit\nCHOICE: ");
    int c;
    scanf("%d", &c);
    return c;
}
