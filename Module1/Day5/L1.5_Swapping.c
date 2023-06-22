#include <stdio.h>
#include <string.h>

// Structure definition
struct Person
{
   char personName[50];
   float personScore;
};

// Swap the fields of two structures
void swap(struct Person *p1, struct Person *p2)
{
   struct Person temp;
   strcpy(temp.personName, p1->personName);
   temp.personScore = p1->personScore;

   strcpy(p1->personName, p2->personName);
   p1->personScore = p2->personScore;

   strcpy(p2->personName, temp.personName);
   p2->personScore = temp.personScore;
}

int main()
{
   // Create two Person structures
   struct Person personX, personY;

   // Read personX data
   printf("Enter details of personX:\n");
   printf("Name: ");
   fgets(personX.personName, sizeof(personX.personName), stdin);
   personX.personName[strcspn(personX.personName, "\n")] = '\0'; // Remove newline character
   printf("Score: ");
   scanf("%f", &personX.personScore);
   getchar(); // Clearing the newline character from input buffer

   // Read personY data
   printf("\nEnter details of personY:\n");
   printf("Name: ");
   fgets(personY.personName, sizeof(personY.personName), stdin);
   personY.personName[strcspn(personY.personName, "\n")] = '\0';
   printf("Score: ");
   scanf("%f", &personY.personScore);

   // Print the initial details
   printf("\nInitial details:\n");
   printf("personX: Name = %s, Score = %.2f\n", personX.personName, personX.personScore);
   printf("personY: Name = %s, Score = %.2f\n", personY.personName, personY.personScore);

   // Swapping persons
   swap(&personX, &personY);

   // Print the swapped details
   printf("\nAfter swapping:\n");
   printf("personX: Name = %s, Score = %.2f\n", personX.personName, personX.personScore);
   printf("personY: Name = %s, Score = %.2f\n", personY.personName, personY.personScore);

   return 0;
}
