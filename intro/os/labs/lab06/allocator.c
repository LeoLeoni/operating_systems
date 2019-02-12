#include <stdio.h>
#include <stdlib.h>

void malloc1();
void free();
void coalesce();
void view(); //view choose
int choose(); //handles user choice


typedef struct __node_t {

    int size;
    struct __node_t *next;
} node_t;

typedef struct __header_t {

    int size;  //size of allocated space 
    int magic; //unique identifier; NOT USED IN THIS ASSIGNMENT 
} header_t;

//struct node_t head = NULL;

int main(int argc, char* argv[]) {

    int h = atoi(argv[1]);
    
    int choice = choose();

    switch (choice) {

        case 1: //malloc
            break;

        case 2: //free
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
            return 0;
            break;
    }



    return 0;
}
 
void malloc1() {

    //struct node_t current = head;
    struct node_t current = NULL;
    current = (struct node_t*)malloc(sizeof(struct node_t));

}
void view() {

    //struct node_t current = head;
    struct node_t current = NULL;
    current = (struct node_t*)malloc(sizeof(struct node_t));
    while (current != NULL) {

        //calculate overhead info
        //print info

        current = current->next;
    }
}

int choose(){

    printf("%s", "\nALLOCATOR: ENTER AN OPTION\n  1. malloc\n  2. free\n  3. coalesce\n  4. view\n  5. quit\nCHOICE: ");
    int c;
    scanf("%d", &c);
    return c;
}