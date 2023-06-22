#include <stdio.h>
#define MAX_STUDENTS 5

// Student structure type declaration
struct Student {
    char studentName[100];
    int studentRoll;
    float studentMarks;
};

int main() {
    // Declare array of structure variables
    struct Student students[MAX_STUDENTS];
    int i;

    // Read all 5 student details from user
    printf("Enter %d student details\n", MAX_STUDENTS);
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d name: ", (i + 1));
        fgets(students[i].studentName, sizeof(students[i].studentName), stdin);
        students[i].studentName[strcspn(students[i].studentName, "\n")] = '\0'; // Remove newline character

        printf("Student %d roll no: ", (i + 1));
        scanf("%d", &students[i].studentRoll);

        printf("Student %d marks: ", (i + 1));
        scanf("%f", &students[i].studentMarks);
        getchar(); // Eat extra newline character

        printf("\n");
    }

    // Print all student details
    printf("\nStudent details\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Name : %s\n", students[i].studentName);
        printf("Roll : %d\n", students[i].studentRoll);
        printf("Marks: %.2f\n", students[i].studentMarks);
        printf("\n");
    }

    return 0;
}
