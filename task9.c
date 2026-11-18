#include <stdio.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int i, searchId, found, choice;
    float total;

    do {
        printf("\n1. Create file (5 employees)\n2. Display all\n3. Search by ID\n4. Total salary\n5. Delete file\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fp = fopen("employees.dat", "wb");      
            for (i = 0; i < 5; i++) {
                printf("Employee %d - ID, Name, Salary: ", i + 1);
                scanf("%d %s %f", &e.id, e.name, &e.salary);
                fwrite(&e, sizeof(e), 1, fp);       
            }
            fclose(fp);
        }
        else if (choice == 2) {
            fp = fopen("employees.dat", "rb");      
            if (fp == NULL) {
                printf("No file found.\n");
            } else {
                while (fread(&e, sizeof(e), 1, fp) == 1)  
                    printf("ID: %d  Name: %s  Salary: %.2f\n", e.id, e.name, e.salary);
                fclose(fp);
            }
        }
        else if (choice == 3) {
            fp = fopen("employees.dat", "rb");
            if (fp == NULL) {
                printf("No file found.\n");
            } else {
                printf("Enter Employee ID: ");
                scanf("%d", &searchId);
                found = 0;
                while (fread(&e, sizeof(e), 1, fp) == 1) {
                    if (e.id == searchId) {
                        printf("Found! ID: %d  Name: %s  Salary: %.2f\n", e.id, e.name, e.salary);
                        found = 1;
                    }
                }
                if (found == 0)
                    printf("Employee not found.\n");
                fclose(fp);
            }
        }
        else if (choice == 4) {
            fp = fopen("employees.dat", "rb");
            if (fp == NULL) {
                printf("No file found.\n");
            } else {
                total = 0;
                while (fread(&e, sizeof(e), 1, fp) == 1)
                    total = total + e.salary;
                printf("Total monthly salary: %.2f\n", total);
                fclose(fp);
            }
        }
        else if (choice == 5) {
            if (remove("employees.dat") == 0)
                printf("File deleted.\n");
            else
                printf("No file to delete.\n");
        }
    } while (choice != 0);

    return 0;
}
