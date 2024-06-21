#ifndef SET_ARRAY
#define SET_ARRAY
#define MAX 7


typedef int SET[MAX];


void addElem(int *X,int* size,int elem);
int *findUnion(SET A, SET B, int *sizeC);
int *findIntersection(SET A, SET B,int *sizeC);
void display(int *X, int size);





#endif
