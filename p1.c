// Create a structure Employee with emp_id, name, salary. Write a program
// to ask the user how many employees(n) they want to enter, dynamically
// allocate memory for n employees using malloc()and Input details and
// display them.

#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
    int emp_id;
    char name[20];
    float sal;
} EMP;

int main()
{
    EMP *emp1;
    int n;
    printf("Enter the number of employees data you want to input: ");
    scanf("%d", &n);
    emp1 = (EMP *)malloc(n * sizeof(EMP));
    if (emp1 == NULL)
    {
        printf("Failed to allocate memory.\n");
        return 1;
    }
    printf("Enter the data for %d employees bellow: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Name: ");
        scanf("%s", emp1[i].name);
        printf("Employee ID: ");
        scanf("%d", &emp1[i].emp_id);
        printf("Salary :");
        scanf("%f", &emp1[i].sal);
    }
    printf("\ndisplaying the stored input:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\n", emp1[i].name);
        printf("Employee ID: %d\n", emp1[i].emp_id);
        printf("Salary : %.2f\n\n", emp1[i].sal);
    }
    free(emp1);
    return 0;
}