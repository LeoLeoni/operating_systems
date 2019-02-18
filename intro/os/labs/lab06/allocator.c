#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void initHeap(int size);
void mallocator(int req);
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

    int heapSize = atoi(argv[1]);
    int heap = 0; //what is this?
    //initHeap(heapSize);

    printf("%s %i %s %i", "\nheap: ", heap, ", 0, size=", heapSize);
    
    int choice = choose();

    switch (choice) {

        case 1: //mallocator
            mallocator(sizeof(node_t));
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


void mallocator(int req) {
    // allocate memory from within the heap for N bytes

    printf("%s", "ENTER THE SIZE IN BYTES: ");
    int size = 0;
    scanf("%d", &size);

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
    
    malloc(size);
    current += req+4; //move pointer
    //new node_t = {size = old->size - req - 4, next = old->next} -> &current;
    
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

    printf("%s", "\nALLOCATOR: ENTER AN OPTION\n  1. mallocator\n  2. free\n  3. coalesce\n  4. view\n  5. quit\nCHOICE: ");
    int c;
    scanf("%d", &c);
    return c;
}