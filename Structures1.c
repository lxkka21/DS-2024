#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Student
typedef struct {
    char name[50];
    int roll_number;
    float CGPA;
} Student;

// Function to read one Student object
void readStudent(Student *student) {
    printf("Enter student's name: ");
    scanf("%s", student->name);
    printf("Enter student's roll number: ");
    scanf("%d", &student->roll_number);
    printf("Enter student's CGPA: ");
    scanf("%f", &student->CGPA);
}

// Function to display one Student object
void displayStudent(Student *student) {
    printf("Name: %s, Roll Number: %d, CGPA: %.2f\n", student->name, student->roll_number, student->CGPA);
}

// Function to sort an array of Student structures according to the roll number
void sortStudents(Student *students, int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].roll_number > students[j].roll_number) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Dynamically allocate memory for the array of students
    Student *students = (Student *)malloc(num_students * sizeof(Student));

    // Read the details for each student
    for (int i = 0; i < num_students; i++) {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    // Sort the students by roll number
    sortStudents(students, num_students);

    // Display the sorted list of students
    printf("Displaying sorted list of students:\n");
    for (int i = 0; i < num_students; i++) {
        displayStudent(&students[i]);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
