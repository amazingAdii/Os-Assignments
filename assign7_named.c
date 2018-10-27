#include<stdio.h>
#include<string.h>

#define READ 0
#define WRITE 1

char *phrase = "Ashirwad pipes";

main(){

    
    char message[100];
    int fd[2];
    int bytes;
    
    pipe( fd );
    
    //int pid = fork();
    
    if( fork () == 0){
        close(fd[READ]);
        write(fd[WRITE], phrase, strlen(phrase) +1);
        close(fd[WRITE]);
        printf("Child just wrote %s to pipe\n", phrase);
                
    }else{
        wait();
        close(fd[WRITE]);
        bytes = read(fd[READ], message,100);
        printf("Parent just got the length %d to pipe\n", bytes);
        close(fd[READ]);
    }
}
