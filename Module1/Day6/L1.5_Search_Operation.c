#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char studentName[20];
  int studentRollNo;
  float studentMarks;
};

int searchStudentByName(struct Student *students, int numStudents, const char *name) {
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(students[i].studentName, name) == 0) {
      return i; // Return the index of the found student
    }
  }
  return -1; // Return -1 if the student is not found
}

int main() {
  int numStudents;
  printf("Enter the number of students: ");
  scanf("%d", &numStudents);

  // Dynamically allocate memory for the array of structures
  struct Student *students = malloc(numStudents * sizeof(struct Student));
  if (students == NULL) {
    printf("Memory allocation failed. Exiting program.\n");
    return 1;
  }

  // Input student details
  for (int i = 0; i < numStudents; i++) {
    printf("Enter details for student %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", students[i].studentName);
    printf("Roll No: ");
    scanf("%d", &students[i].studentRollNo);
    printf("Marks: ");
    scanf("%f", &students[i].studentMarks);
  }

  char searchName[20];
  printf("Enter the name to search: ");
  scanf("%s", searchName);

  int foundIndex = searchStudentByName(students, numStudents, searchName);
  if (foundIndex != -1) {
    printf("Student found at index %d:\n", foundIndex);
    printf("Name: %s\n", students[foundIndex].studentName);
    printf("Roll No: %d\n", students[foundIndex].studentRollNo);
    printf("Marks: %.2f\n", students[foundIndex].studentMarks);
  } else {
    printf("Student not found.\n");
  }

  // Free the dynamically allocated memory
  free(students);

  return 0;
}
