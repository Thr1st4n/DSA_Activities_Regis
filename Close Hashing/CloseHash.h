#ifndef CLOSE_HASH
#define CLOSE_HASH
#include<stdbool.h>

typedef struct {
    char Element;
    int Hash;
} HashVal;

typedef struct {
    char *array;
    int size;
    int count;
} Dictionary;

typedef enum { TRUE, FALSE } Boolean;

void initDictionary(Dictionary *A);
void display(Dictionary *A);
int hash(HashVal *A, int size, char B);
void insert(HashVal *A, Dictionary *B, char C);
Boolean isMember(HashVal *A, Dictionary *B, char C);
void deleteElement(HashVal *A, Dictionary *B, char C);
void resize(Dictionary *A);






#endif
