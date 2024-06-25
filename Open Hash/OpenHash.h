#ifndef OPEN_HASH
#define OPEN_HASH
extern int MAX;

typedef struct node{
	char word[20];
	struct node* link;
}*Info;

int openHash(char string[],int size);
void resizeHashTable(Info** HeadsIndex);
void insertDict(Info* HeadsIndex[], char* givenWord);
void visualize(Info HeadsIndex[]);
	





#endif
