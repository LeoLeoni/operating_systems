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
    struct __node_t *next;
} node_t;

typedef struct __header_t {

    int size;  //size of allocated space 
    int magic; //unique identifier; NOT USED IN THIS ASSIGNMENT 
} header_t;

struct node_t *nodeHead = NULL;
struct header_t *head = NULL;

int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("%s", "Invalid arguments. Use size as an argument\n");
        return 0;
    }
    int heapSize = atoi(argv[1]);
    nodeHead = malloc(heapSize);
    int heap = 0; //what is this?

    printf("%s %i %s %i", "\nheap: ", &nodeHead, ", 0, size=", heapSize);
    
    int choice = choose();

    switch (choice) {

        case 1: //malloc
            printf("%s", "ENTER THE SIZE IN BYTES: ");
            int size;
            scanf("%d", &size);
         malloc1(size);
	        break;

        case 2: //free optional
            //free();
            break;

        case 3: //coalesce optional
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

    node_t *current = nodeHead;

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
    header_t *newHead = malloc(req);
    
    current += req+4; //move pointer
    
}

//void free() {}


void view() {


    printf("%s", "Traversing linked list of free regions...\n\n");
    node_t *current = nodeHead;

    while (current != NULL) {

        //calculate overhead info
        //print info

        current = current->next;
    }
}

int choose(){

    printf("%s", "\n\nALLOCATOR: ENTER AN OPTION\n  1. malloc1\n  2. free\n  3. coalesce\n  4. view\n  5. quit\nCHOICE: ");
    int c;
    scanf("%d", &c);
    return c;
}