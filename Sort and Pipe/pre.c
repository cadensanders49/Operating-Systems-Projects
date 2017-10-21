#include <stdio.h>
#include <stdlib.h>

int main() {

  int numStudents = 0;
  struct student {
    char name[255];
    float GPA;
    int print;
  };

  struct student students[255];
  struct student *students_pointer;

  students_pointer = students;

  while(!feof(stdin)) {
    scanf("%255s", students_pointer[numStudents].name);
    scanf("%f", &students_pointer[numStudents].GPA);
    students_pointer[numStudents].print = 1;
    if(students_pointer[numStudents].GPA > 3.0) {
      students_pointer[numStudents].print =  0;
    }
    numStudents++;
  }

  printf("\n\n\n");
  for(int i=0;i<numStudents; i++) {
    if(students_pointer[i].GPA >= 3.0) {
      printf("%s\n", students_pointer[i].name);
    }
  }

}
