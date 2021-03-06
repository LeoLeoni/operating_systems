//one.c
#include <stdio.h> 
#include <unistd.h> 
int main() {
    
    int gen = 0; //num. generations removed from original process 
    int forknum = 0; 
    
    //fork #1 
    int pid = fork();
    
    if (pid == 0) { 
        
        forknum = 1; //identifying which fork was used 
        gen++; 
    } else wait(); 
    
    printf("gen=%d:fork=%d:pid=%d:ppid=%d\n", gen, forknum, getpid(), getppid()); 
    return 0; 
}