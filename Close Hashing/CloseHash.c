#include <stdio.h>
#include <stdlib.h>
#include "CloseHash.h"
#define INITIAL_SIZE 10
#define EMPTY '@'
#define DELETED '|'



void initDictionary(Dictionary *A) {
    A->size = INITIAL_SIZE;
    A->count = 0;
    A->array = (char *)malloc(A->size * sizeof(char));

    int i;
    for (i = 0; i < A->size; i++) {
        A->array[i] = EMPTY;
    }
}

void display(Dictionary *A) {
    int i;
    for (i = 0; i < A->size; i++) {
        printf("[%2d]  |  %c\n", i, A->array[i]);
    }
}

int hash(HashVal *A, int size, char B) {
    int i;
    for (i = 0; i < size; i++) {
        if (A[i].Element == B) {
            return A[i].Hash % size;
        }
    }
    return -1; // Not found
}

Boolean isMember(HashVal *A, Dictionary *B, char C) {
    int i, x = B->size;
    int index = hash(A, B->size, C);
    if (index == -1) return FALSE;
    Boolean checker = FALSE;

    for (i = index; i < B->size && i != x; i++) {
        if (i == B->size) {
            i = 0;
            x = index;
        }
        if (B->array[i] == C) {
            checker = TRUE;
        }
    }
    return checker;
}

void insert(HashVal *A, Dictionary *B, char C) {
    if ((float)B->count / B->size >= 0.65) {
        resize(B);
    }

    int index = hash(A, B->size, C);
    if (index == -1) return;
    int i = index;
    Boolean checker = FALSE;

    for (i = index; i < B->size && checker != TRUE; i++) {
        if (B->array[i] == EMPTY) {
            B->array[i] = C;
            checker = TRUE;
            B->count++;
        } else if (B->array[i] == C) {
            printf("Element Exist!\n");
            checker = TRUE;
        }
        if (i == B->size - 1) {
            i = -1;
        }
        if (i >= index && B->array[i] == DELETED) {
            B->array[i] = C;
            checker = TRUE;
            B->count++;
        }
    }
}

void deleteElement(HashVal *A, Dictionary *B, char C) {
    int index = hash(A, B->size, C);
    if (index == -1) return;
    int i = index;
    Boolean checker = FALSE;

    for (i = index; i < B->size && checker != TRUE; i++) {
        if (B->array[i] == C) {
            printf("%c is DELETED!\n", B->array[i]);
            B->array[i] = DELETED;
            checker = TRUE;
            B->count--;
        }
        if (i == B->size - 1) {
            i = -1;
        }
    }
}

void resize(Dictionary *A) {
    int newSize = A->size * 2;
    char *newArray = (char *)malloc(newSize * sizeof(char));

    int i;
    for (i = 0; i < newSize; i++) {
        newArray[i] = EMPTY;
    }

    for (i = 0; i < A->size; i++) {
        if (A->array[i] != EMPTY && A->array[i] != DELETED) {
            int newIndex = A->array[i] % newSize;
            while (newArray[newIndex] != EMPTY) {
                newIndex = (newIndex + 1) % newSize;
            }
            newArray[newIndex] = A->array[i];
        }
    }

    free(A->array);
    A->array = newArray;
    A->size = newSize;
}
