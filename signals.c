#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGUSR1){
    printf("%s\n","SIGUSR1");
    exit(0);
  }
  if(signo == SIGINT){
    printf("%s\n","SIGINT");
    exit(0);
  }
}

int main(){
  while(1){
    printf("%s\n","Hi");
    sleep(1);
    signal(SIGUSR1, sighandler);
    signal(SIGINT, sighandler);
  }
  return 0;
}
