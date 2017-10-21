#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {

  pid_t pid;
  printf("argc:%d\n", argc);
  for(int i=0; i<argc; i++) {
    printf("%s\n", argv[i]);
    argv[i] = argv[i+1];
  }
  argv[argc-1] = 0;
  pid = fork();

  //error
  if(pid<0) {
    fprintf(stderr, "fork failed");
    exit(-1);
  }

  //child
  else if(pid==0) {
    int pid = getpid();
    int ppid = getppid();
    printf("pid: %d\nppid:%d\n", pid, ppid);
    execvp(argv[0], &argv[0]);
  }

  //parent
  else {
    wait((int *)0);
    printf("child completed\n");
    exit(0);
  }
}
