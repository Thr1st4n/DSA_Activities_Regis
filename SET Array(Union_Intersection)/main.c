#include <stdio.h>
#include <stdlib.h>
#include "Set_Array.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
    SET A = {1, 2, 3, 4, 5, 6, 7};
    SET B = {1, 2, 3, 8, 9, 10, 11};
    int sizeC;
    
   	printf("SET A: ");
   	display(A,MAX);
    printf("SET B: ");
   	display(B,MAX);
   
    printf("Union: ");
    int *C = findUnion(A, B,&sizeC);
  	display(C,sizeC);
  	free(C);

  	printf("Intersection: ");
    C = findIntersection(A, B,&sizeC);
    display(C,sizeC);
    

    return 0;
}
