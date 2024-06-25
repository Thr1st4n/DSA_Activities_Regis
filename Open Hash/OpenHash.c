#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "OpenHash.h"
#define LoadFactorTreshold 0.65
int numOfElem = 0;
int MAX = 10;


int openHash(char string[],int size){
	
	return (string[0] *31 - string[1]) % size;
	
}

void resizeHashTable(Info** HeadsIndex) {
    int i;
    int newMAX = MAX * 2; 
    
    Info* newTable = calloc(newMAX, sizeof(struct node*)); 
    
    for (i = 0; i < MAX; i++) {
        Info current = (*HeadsIndex)[i];
        while (current != NULL) {
            Info next = current->link;
            int newIndex = openHash(current->word,newMAX); 
            
            current->link = newTable[newIndex];
            newTable[newIndex] = current;
            
            current = next;
        }
    }
    
    free(*HeadsIndex);
    MAX = newMAX;
    *HeadsIndex = newTable;
}

void insertDict(Info* HeadsIndex[], char* givenWord) {
    if ((double)numOfElem / MAX > LoadFactorTreshold) {
        resizeHashTable(HeadsIndex);
    }
    
    int index = openHash(givenWord,MAX);
    
    Info *trav;
    for (trav = &(*HeadsIndex)[index]; *trav != NULL && strcmp((*trav)->word, givenWord) != 0; trav = &(*trav)->link);
    if (*trav == NULL) {
        Info newNode = malloc(sizeof(struct node));
        strcpy(newNode->word,givenWord);
        newNode->link = NULL;
        *trav = newNode;
        numOfElem++;
    } else {
        printf("Word %s already exists!\n", givenWord);
    }
}

void visualize(Info HeadsIndex[]) {
    int i;
     printf("Current Size: %d\n\n",MAX);
    printf("---Filipino Foods---\nDictionary Visualization:\n");
    for (i = 0; i < MAX; i++) {
        printf("index[%2d]: ", i);
        Info current;
        for (current = HeadsIndex[i]; current != NULL; current = current->link) {
            printf("%s -> ", current->word);
        }
        printf("NULL\n");
    }
}

