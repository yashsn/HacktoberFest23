#include <stdio.h>
#include <stdlib.h>

struct details {
    char name[30];
    int eid;
    int salary;
};

struct details emp[30];

void disp(int r);
void emp_search(int r);
void greater(int r);
void updateEmployee(int r);
void deleteEmployee(int *r);
void addEmployees(int *r);

int main() {
    int n = 0, ch;
    
    addEmployees(&n);

    while(1) {
        printf("\nMENU");
        printf("\n-------------------------");
        printf("\nEnter\n1 for display\n2 for searching salary > 10000\n3 for searching by employee ID\n4 to update employee details\n5 to delete employee\n6 to add more employees\n7 to exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: disp(n); break;
            case 2: greater(n); break;
            case 3: emp_search(n); break;
            case 4: updateEmployee(n); break;
            case 5: deleteEmployee(&n); break;
            case 6: addEmployees(&n); break;
            case 7: exit(0); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}

void addEmployees(int *r) {
    int num, i;
    printf("How many employees do you want to add?: ");
    scanf("%d", &num);
    
    for (i = *r; i < *r + num; i++) {
        printf("\n-------------------------");
        printf("\nEnter details of employee %d", i + 1);
        printf("\n-------------------------");
        printf("\nEnter name: ");
        scanf("%s", emp[i].name);
        printf("\nEnter employee ID: ");
        scanf("%d", &emp[i].eid);
        printf("\nEnter employee salary: ");
        scanf("%d", &emp[i].salary);
    }
    *r += num;
}

void disp(int r) {
    printf("\nEmployee details are as follows:");
    printf("\n-------------------------------------");
    printf("\nNAME\tEID\tSALARY\t");

    for (int i = 0; i < r; i++) {
        printf("\n\n%s", emp[i].name);
        printf("\t%d", emp[i].eid);
        printf("\t%d", emp[i].salary);
        printf("\n-------------------------------------");
    }
}

void greater(int r) {
    printf("Employee(s) having salary more than 10000:");
    for (int i = 0; i < r; i++) {
        if (emp[i].salary >= 10000) {
            printf("\nNAME\tEID\tSALARY\t\n%s\t%d\t%d", emp[i].name, emp[i].eid, emp[i].salary);
        }
    }
}

void emp_search(int r) {
    int k, i;
    printf("\nEnter the E ID you want to search: ");
    scanf("%d", &k);
    printf("\n-------------------------------------");
    for (i = 0; i < r; i++) {
        if (emp[i].eid == k) {
            printf("\nNAME\tEID\tSALARY\t\n%s\t%d\t%d", emp[i].name, emp[i].eid, emp[i].salary);
        }
    }
}

void updateEmployee(int r) {
    int id, found = 0;
    printf("Enter the employee ID to update details: ");
    scanf("%d", &id);
    
    for (int i = 0; i < r; i++) {
        if (emp[i].eid == id) {
            found = 1;
            printf("Updating details for %s\n", emp[i].name);
            printf("Enter new name: ");
            scanf("%s", emp[i].name);
            printf("Enter new salary: ");
            scanf("%d", &emp[i].salary);
            printf("Details updated successfully.\n");
            break;
        }
    }
    if (found==0) {
        printf("Employee with ID %d not found.\n", id);
    }
}

void deleteEmployee(int *r) {
    int id, found = 0;
    printf("Enter the employee ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *r; i++) {
        if (emp[i].eid == id) {
            found = 1;
            for (int j = i; j < *r - 1; j++) {
                emp[j] = emp[j + 1];
            }
            (*r)--;
            printf("Employee with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (found==0) {
        printf("Employee with ID %d not found.\n", id);
    }
}
