#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};

int main() {
    struct Student student, *ptr;
    ptr = &student;

    
    printf("Enter roll number: ");
    scanf("%d", &ptr->roll_no);
    printf("Enter name: ");
    scanf("%s", ptr->name);
    printf("Enter branch: ");
    scanf("%s", ptr->branch);
    printf("Enter batch number: ");
    scanf("%d", &ptr->batch_no);


    printf("\nStudent Details:\n");
    printf("Roll No: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch No: %d\n", ptr->batch_no);

    return 0;
}
