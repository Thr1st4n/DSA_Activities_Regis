#include <stdio.h>
#include <stdlib.h>
#include "CloseHash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	HashVal HV[] = { {'a',3},{'b',9},{'c',4},{'d',3},{'e',9},{'f',0},{'g',1},{'h',3},{'i',0},{'j',3} };

    Dictionary D;
    initDictionary(&D);

    insert(HV, &D, 'a');
    insert(HV, &D, 'b');
    insert(HV, &D, 'c');
    insert(HV, &D, 'd');
    insert(HV, &D, 'e');
    insert(HV, &D, 'f');
    insert(HV, &D, 'i');
    insert(HV, &D, 'x');
    
    deleteElement(HV, &D, 'a');
    display(&D);

    Boolean checker = isMember(HV, &D, 'g');
    if (checker == TRUE) {
        printf("\nA member");
    } else {
        printf("\nNot a member");
    }


    free(D.array);

    return 0;
}
