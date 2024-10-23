#include <stdio.h>
#include <stdlib.h>

// Define structure for Date of Birth (DOB)
struct DOB {
    int day;
    int month;
    int year;
};

// Define structure for Address
struct Address {
    int house_number;
    int zip_code;
    char state[30];
};

// Define structure for Employee
struct Employee {
    char name[50];
    struct DOB dob;
    struct Address address;
};

// Function to read employee data
void readEmployeeData(struct Employee *e, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for Employee %d\n", i + 1);

        printf("Enter Name: ");
        scanf(" %[^\n]", e[i].name); // To read string with spaces

        printf("Enter Date of Birth (day month year): ");
        scanf("%d %d %d", &e[i].dob.day, &e[i].dob.month, &e[i].dob.year);

        printf("Enter Address (house number, zip code, state): ");
        scanf("%d %d %[^\n]", &e[i].address.house_number, &e[i].address.zip_code, e[i].address.state);
    }
}

// Function to display employee data
void displayEmployeeData(struct Employee *e, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nDetails of Employee %d\n", i + 1);
        printf("Name: %s\n", e[i].name);
        printf("Date of Birth: %02d/%02d/%d\n", e[i].dob.day, e[i].dob.month, e[i].dob.year);
        printf("Address: House Number: %d, Zip Code: %d, State: %s\n", e[i].address.house_number, e[i].address.zip_code, e[i].address.state);
    }
}

int main() {
    int n;

    // Ask for the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n employees
    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));

    // Read employee data
    readEmployeeData(employees, n);

    // Display employee data
    displayEmployeeData(employees, n);

    // Free allocated memory
    free(employees);

    return 0;
}
