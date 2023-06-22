#include <stdio.h>
#include <string.h>

struct Student {
  char name[20];
  int id;
  float marks;
};

void displayStudents(struct Student* students, int numStudents) {
  for (int i = 0; i < numStudents; i++) {
    printf("Student %d:\n", i + 1);
    printf("Name: %s\n", students[i].name);
    printf("ID: %d\n", students[i].id);
    printf("Marks: %.2f\n", students[i].marks);
  }
}

int main() {
  struct Student students[3];
  strcpy(students[0].name, "John ");
  students[0].id = 12345;
  students[0].marks = 98.5;
  strcpy(students[1].name, "Jane ");
  students[1].id = 67890;
  students[1].marks = 89.2;
  strcpy(students[2].name, "Michael ");
  students[2].id = 34567;
  students[2].marks = 78.1;

  displayStudents(students, 3);

  return 0;
}
