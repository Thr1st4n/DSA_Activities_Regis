#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Set_Array.h"




void addElem(int *X,int* size,int elem){
	X[*size] = elem;
	(*size)++;
}

int *findUnion(SET A, SET B, int *sizeC) {
    int i, j, exist, newSize = 0;
    int *C = malloc(sizeof(int) * (MAX * 2));
   
    for (i = 0; i < MAX; i++) {
        addElem(C, &newSize, A[i]);
    }
    
    for (i = 0; i < MAX; i++) {
        exist = 0;
        for (j = 0; j < newSize; j++) {
            if (B[i] == C[j]) {
                exist = 1;
                break;
            }
        }
        if (exist == 0) {
            addElem(C, &newSize, B[i]);
        }
    }
    
    C = realloc(C, sizeof(int) * newSize);
    *sizeC = newSize;
    return C;
    
    
}


int *findIntersection(SET A, SET B,int *sizeC){
	
	int i, j, exist, newSize = 0;
    int *C = malloc(sizeof(int) * (MAX * 2));
   
    for (i = 0; i < MAX; i++) {
        exist = 0;
        for (j = 0; j < MAX; j++) {
            if (A[i] == B[j]) {
                exist = 1;
                break;
            }
        }
        if (exist == 1) {
            addElem(C, &newSize, A[i]);
        }
    }
    
    C = realloc(C, sizeof(int) * newSize);
    *sizeC = newSize;
    return C;
	
	
	
}

void display(int *X, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");
}


