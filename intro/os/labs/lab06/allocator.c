#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void initHeap(int size);
void malloc1(int req);
//void free(); //optional
void view(); //view choice
int choose(); //handles user choice


typedef struct __node_t {

    int size;
    int free;
    struct __node_t *next;
} node_t;


struct node_t *head = NULL;

int offset = 0;
int count = 0;

int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("%s", "Invalid arguments. Use size as an argument\n");
        return 0;
    }
    int heapSize = atoi(argv[1]);
    head = malloc(heapSize);
    int heap = 0; //what is this?

    printf("%s %i %s %i", "\nheap: ", &head, ", 0, size=", heapSize);
    
    int choice = choose();

    switch (choice) {

        case 1: //malloc
            printf("%s", "ENTER THE SIZE IN BYTES: ");
            int size;
            scanf("%d", &size);
            malloc1(size);
	        break;

        case 2: //free
            //free();
            break;

        case 3: //coalesce
            break;

        case 4: //view
            //view();
            break;

        case 5: //quit
            return 0;
            break;

        default: //quit
            printf("%s", "Invalid input\n");
	    return 0;
            break;
    }



    return 0;
}
 
/*
void initHeap(int size) {
    //create an empty heap with 4KB of size
    nodeHead = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
    nodeHead->size = 4096 - sizeof(node_t);
    nodeHead->next = NULL;
}*/


void malloc1(int req) {
    // allocate memory from within the heap for N bytes

    offset += 4;
    count += 4;

    printf("ptr: %p, %i, %i", &head + count, offset, req);
    offset += req;

    
    node_t *current = head;

    while (current->size < req+4) {
        current = current->next;
        if (current==NULL) {
            printf("%s", "Error");
            break;
        }
    }
    node_t *old = NULL;
    old->next = current->next;
    old->size = current->size;

    //build new header
    
    current += req+4; //move pointer
}

//void free() {}


void view() {

    printf("%s", "Traversing linked list of free regions...\n\n");
    node_t *current = head;

    while (current != NULL) {

        //calculate overhead info
        //print info

        current = current->next;
    }
}

int choose(){

    printf("%s", "\n\nALLOCATOR: ENTER AN OPTION\n  1. malloc\n  2. free\n  3. coalesce\n  4. view\n  5. quit\nCHOICE: ");
    int c;
    scanf("%d", &c);
    return c;
}