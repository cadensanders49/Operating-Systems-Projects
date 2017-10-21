#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int numStudents = 0;
  int curr = 0;
  int down = 0;
  int i = 0;
  struct student {
    char name[255];
  };
  struct student students[255];
  struct student temp;

  while(!feof(stdin)) {
    scanf("%s", students[numStudents].name);

    if(numStudents != 0) {
      down = 1;
    }
    i = 0;
    curr = numStudents;

    while(down==1) {
      if(students[curr].name[i] > students[curr-1].name[i]) {
        down = 0;
      }
      else if(students[curr].name[i] == students[curr-1].name[i]) {
        i++;
      }
      else {
        if(curr != 0) {
          temp = students[curr-1];
          students[curr-1] = students[curr];
          students[curr] = temp;
          i = 0;
          curr--;
        }
        else {
          down = 0;
        }
      }
    }

    numStudents++;
  }

  printf("\n\n\n");
  for(int j = 0; j<numStudents; j++) {
    printf("%s\n", students[j].name);
  }
}
