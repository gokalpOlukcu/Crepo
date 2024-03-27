#include <stdio.h>

#define MAXSTUDENT	100

typedef struct {
  int id;
  float gpa;
  char class;
  char name[20];
} Student;

void main() {
  Student Ss[MAXSTUDENT];
  int numS = 0;
  int option;

  readSFile(Ss,&numS,"stu.dat");
  do {
  option = select();
  switch (option) {
    case 'I': case 'i':  
      insS(Ss,&numS); break;
    case 'R': case 'r':
      remS(Ss,&numS); break;
    case 'P': case 'p':
      prntS(Ss,numS); break;
    case 'S': case 's':
      sort(Ss,numS); break;
    case 'Q': case 'q': break;
  }
  printf("\n");
 } while ((option != 'Q') && (option != 'q'));
 prntSFile(Ss,numS,"stu.dat");
}