#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *link;
};

struct Node *first = NULL; // Resultant polynomial
struct Node *h1 = NULL;    // First polynomial
struct Node *h2 = NULL;    // Second polynomial

void addPolynomial() {
    struct Node *temp1 = h1;
    struct Node *temp2 = h2;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            // Same exponent, add coefficients
            int newCoeff = temp1->coeff + temp2->coeff;
            if (newCoeff != 0) {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->coeff = newCoeff;
                newNode->exp = temp1->exp;
                newNode->link = first;
                first = newNode;
            }
            temp1 = temp1->link;
            temp2 = temp2->link;
        } else if (temp1->exp > temp2->exp) {
            // Add term from first polynomial
            newNode->coeff = temp1->coeff;
            newNode->exp = temp1->exp;
            newNode->link = first;
            first = newNode;
            temp1 = temp1->link;    
        } else {
            // Add term from second polynomial
            newNode->coeff = temp2->coeff;
            newNode->exp = temp2->exp;
            newNode->link = first;
            first = newNode;
            temp2 = temp2->link;
        }
    }

    // Add remaining terms from h1
    while (temp1 != NULL) {
        newNode->coeff = temp1->coeff;
        newNode->exp = temp1->exp;
        newNode->link = first;
        first = newNode;
        temp1 = temp1->link;
    }

    // Add remaining terms from h2
    while (temp2 != NULL) {
        newNode->coeff = temp2->coeff;
        newNode->exp = temp2->exp;
        newNode->link = first;
        first = newNode;
        temp2 = temp2->link;
    }
}

void printList() {
    struct Node *curr = first;

    while (curr != NULL) {
        printf("%d,%d ", curr->coeff, curr->exp);
        curr = curr->link;
    }

    printf("\n");
}

void createPolynomial(struct Node **head) {
    int n, exp, coeff;
    printf("Enter how many terms do you want to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (format: coeff,exp): ");
        scanf("%d,%d", &coeff, &exp);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->link = *head;
        *head = newNode;
    }
}

int main() {
    printf("Creating first polynomial:\n");
    createPolynomial(&h1);
    printf("Creating second polynomial:\n");
    createPolynomial(&h2);

    addPolynomial();
    printf("Resultant polynomial:\n");
    printList();

    return 0;
}











// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//     int coff;
//     int exp;
//     struct Node *link;
// };
// struct Node *first = NULL;
// struct Node *h1 = NULL;
// struct Node *h2 = NULL;

// void addPolynomial()
// {
//     if(h1 == NULL)
//     {
//         return;
//     }
//     if(h2 == NULL)
//     {
//         return;
//     }

//     h1->coff += h2->coff;
//     h1->exp += h2->exp;
// }

//     void printList() {
//         struct Node* curr = first;

//         while (curr != NULL) {
//             printf("%d,%d ", curr->coff, curr->exp);
//             curr = curr->link;

//         }

//         printf("\n");
//     }

//  int main()
// {
//     int n, exp, coeff;
//     printf("Enter how many nodes do you want to create : ");
//     scanf("%d", &n);

//     for (int i = 0; i < n;i++)
//     {
//         printf("Enter a first LL polynomial : ");
//         scanf("%d,%d ", &coeff, &exp);
//         addPolynomial();
//         printf("Enter a second LL polynomial : ");
//         scanf("%d,%d ", &coeff, &exp);
//         addPolynomial();
//     }

//     printList();
// }
