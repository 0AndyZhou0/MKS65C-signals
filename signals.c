#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static void sighandler(int signo){
  if(signo == SIGUSR1){
    printf("%d\n",getppid());
  }
  if(signo == SIGINT){
    printf("%s\n","SIGINT");
    int thing = open("note.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
    write(thing,"Nico Nico Niiiiiii\n",19);
    close(thing);
    exit(0);
  }
}

int main(){
  while(1){
    printf("%d\n",getpid());
    signal(SIGUSR1, sighandler);
    signal(SIGINT, sighandler);
    sleep(1);
  }
  return 0;
}
