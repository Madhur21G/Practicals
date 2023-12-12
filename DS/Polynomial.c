#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};
typedef struct Term Term;

Term* createTerm(int coefficient, int exponent) {
    Term *term = (Term*)malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

void insertTerm(Term **poly, int coefficient, int exponent) {
    Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term *current = *poly;
        Term *prev = NULL;
        while (current != NULL && current->exponent > exponent) {
            prev = current;
            current = current->next;
        }
        if (current != NULL && current->exponent == exponent) {
            current->coefficient += coefficient;
            free(newTerm);
        } else {
            if (prev == NULL) {
                newTerm->next = *poly;
                *poly = newTerm;
            } else {
                prev->next = newTerm;
                newTerm->next = current;
            }
        }
    }
}

void displayPoly(Term *poly) {
    if (poly == NULL) {
        printf("0\n");
    } else {
        while (poly != NULL) {
            printf("%dx^%d", poly->coefficient, poly->exponent);
            poly = poly->next;
            if (poly != NULL) {
                printf(" + ");
            }
        }
        printf("\n");
    }
}

Term* addPolynomials(Term *poly1, Term *poly2) {
    Term *result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    Term *poly1 = NULL;
    Term *poly2 = NULL;
    Term *result = NULL;
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);
    insertTerm(&poly1, 2, 0);
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    result = addPolynomials(poly1, poly2);
    printf("Sum of the two polynomials: ");
    displayPoly(result);
    return 0;
}