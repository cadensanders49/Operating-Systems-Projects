#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  int pid;
  int p[2];
  pipe(p);
  pid = fork();

  //error
  if(pid<0) {
    fprintf(stderr, "fork failed");
    exit(-1);
  }

  //read
  else if(pid==0) {
    close(0);
    dup(p[0]);
    close(p[0]);
    close(p[1]);
    execl("./sort.c", "./sort.c", (char *)0);
  }

  //write
  else {
    close(1);
    dup(p[1]);
    close(p[1]);
    close(p[0]);
    execl("./pre.c", "./pre.c", (char *)0);
  }

}
