#include <stdio.h>
#include <stdlib.h>
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

void sortStudents(struct Student* students, int numStudents) {
  for (int i = 0; i < numStudents - 1; i++) {
    for (int j = 0; j < numStudents - i - 1; j++) {
      if (students[j].marks < students[j + 1].marks) {
        struct Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}

int main() {
  int numStudents;
  printf("Enter the number of students: ");
  scanf("%d", &numStudents);

  struct Student* students = malloc(numStudents * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < numStudents; i++) {
    printf("Enter details for student %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("ID: ");
    scanf("%d", &students[i].id);
    printf("Marks: ");
    scanf("%f", &students[i].marks);
  }

  printf("\nBefore sorting:\n");
  displayStudents(students, numStudents);

  sortStudents(students, numStudents);

  printf("\nAfter sorting:\n");
  displayStudents(students, numStudents);

  free(students);

  return 0;
}
