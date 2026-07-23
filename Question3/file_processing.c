#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} Employee;

int main() {
    FILE *fp;

    Employee e1 = {101, "Alice"};
    Employee e2 = {102, "Bob"};
    Employee e3 = {103, "Charlie"};

    fp = fopen("employee.dat", "wb");

    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    fwrite(&e1, sizeof(Employee), 1, fp);
    fwrite(&e2, sizeof(Employee), 1, fp);
    fwrite(&e3, sizeof(Employee), 1, fp);

    fclose(fp);

    printf("Employee records written successfully.\n");

    fp = fopen("employee.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nEmployee Records:\n");

    Employee temp;

    while (fread(&temp, sizeof(Employee), 1, fp) == 1) {
        printf("ID: %d Name: %s\n", temp.id, temp.name);
    }

    fclose(fp);

    return 0;
}

