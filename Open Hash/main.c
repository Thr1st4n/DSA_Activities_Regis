#include <stdio.h>
#include <stdlib.h>
#include "OpenHash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	int startingSize = MAX;
	Info* HeadsIndex = calloc(MAX, sizeof(struct node*));
    
    insertDict(&HeadsIndex, "Lumpia");
    insertDict(&HeadsIndex, "Adobo");
    insertDict(&HeadsIndex, "Sinigang");
    insertDict(&HeadsIndex, "Bibingka");
    insertDict(&HeadsIndex, "Sisig");
    insertDict(&HeadsIndex, "Lechon");
    insertDict(&HeadsIndex, "Puto"); //before reaching load factor 
    insertDict(&HeadsIndex, "Pancit"); 
  
    printf("Starting size: %d\n",startingSize);
    visualize(HeadsIndex);
    
    free(HeadsIndex);
    
    return 0;
}
