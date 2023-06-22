#include <stdio.h>
#include <stdlib.h>

struct Student {
   char studentName[50];
   int studentAge;
   float studentMarks;
};

int main() {
   int numOfStudents;
   printf("Enter the number of students: ");
   scanf("%d", &numOfStudents);

   struct Student *studentArray = (struct Student *)malloc(numOfStudents * sizeof(struct Student));

   if (studentArray == NULL) {
      printf("Memory allocation failed. Exiting...\n");
      return 1;
   }

   // Read data for numOfStudents students
   for (int i = 0; i < numOfStudents; i++) {
      printf("\nEnter details for student %d:\n", i + 1);
      printf("Name: ");
      scanf("%s", studentArray[i].studentName);
      printf("Age: ");
      scanf("%d", &studentArray[i].studentAge);
      printf("Marks: ");
      scanf("%f", &studentArray[i].studentMarks);
   }

   // Display data for numOfStudents students
   printf("\nStudent Data:\n");
   for (int i = 0; i < numOfStudents; i++) {
      printf("\nDetails of student %d:\n", i + 1);
      printf("Name: %s\n", studentArray[i].studentName);
      printf("Age: %d\n", studentArray[i].studentAge);
      printf("Marks: %.2f\n", studentArray[i].studentMarks);
   }

   // Free dynamically allocated memory
   free(studentArray);

   return 0;
}
