#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int studentID;
    char studentName[20];
    float studentMarks;
};

void parseString(const char* str, struct Student* students, int numStudents) {
    char temp[20];
    int i = 0;
    int index = 0;

    while (sscanf(str + index, "%d %[A-Za-z] %f", &students[i].studentID, temp, &students[i].studentMarks) == 3) {
        strcpy(students[i].studentName, temp);
        i++;
        index += strcspn(str + index, " \n") + 1;  // Move the index to the next token
    }
}

int main() {
    int numStudents = 3;
    struct Student students[numStudents];
    char str[100];

    printf("Enter student details: ");
    fgets(str, sizeof(str), stdin);

    parseString(str, students, numStudents);

    printf("\nStudent details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student ID: %d, Name: %s, Marks: %.2f\n", students[i].studentID, students[i].studentName, students[i].studentMarks);
    }

    return 0;
}
