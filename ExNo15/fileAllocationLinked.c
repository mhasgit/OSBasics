#include <stdio.h>
#include <conio.h>
#include <string.h>

struct EmployeeRecord
{
    char empname[20];
    int age;
    float salary;
};

typedef struct EmployeeRecord Employee;
FILE *employeeFile;

void main()
{
    Employee employee;
    int i, n;
    FILE *fp;

    printf("How many records: ");
    scanf("%d", &n);

    fp = fopen("PEOPLE.txt", "w");

    for (i = 0; i < n; i++)
    {
        printf("Enter employee information %d (EmpName, Age, Salary): ", i + 1);
        scanf("%s %d %f", employee.empname, &employee.age, &employee.salary);

        fwrite(&employee, sizeof(Employee), 1, fp);
    }

    fclose(fp);

    int recordNumber, result;
    employeeFile = fopen("PEOPLE.txt", "r");

    printf("Which record do you want to read from the file? ");
    scanf("%d", &recordNumber);

    while (recordNumber >= 0)
    {
        fseek(employeeFile, recordNumber * sizeof(Employee), SEEK_SET);
        result = fread(&employee, sizeof(Employee), 1, employeeFile);

        if (result == 1)
        {
            printf("\nRECORD %d\n", recordNumber);
            printf("Employee name: %s\n", employee.empname);
            printf("Age: %d years\n", employee.age);
            printf("Current salary: $%.2f\n\n", employee.salary);
        }
        else
        {
            printf("\nRECORD %d not found!\n\n", recordNumber);
        }

        printf("Which record do you want (0 to 3): ");
        scanf("%d", &recordNumber);
    }

    fclose(employeeFile);

    getch();
}
