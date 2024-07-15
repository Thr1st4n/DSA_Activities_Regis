#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    char vertex;
    struct node* next;
} Node;


typedef struct {
    int numVertices;
    Node** adjLists;
} Graph;


Node* createNode(char v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


void display(Graph* graph) {
	int i;
    char vertex = 'A';
    for (i = 0; i < graph->numVertices; i++) {
        printf("%c -> ", vertex++);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%c ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}


void addEdge(Graph* graph, char from, char to) {
    int fromIndex = from - 'A';
    int toIndex = to - 'A';
   
    Node* newNode = createNode(to);
    newNode->next = graph->adjLists[fromIndex];
    graph->adjLists[fromIndex] = newNode;

 
    newNode = createNode(from);
    newNode->next = graph->adjLists[toIndex];
    graph->adjLists[toIndex] = newNode;
    printf("Adding edge from %c to %c\n",from, to);
}


void removeEdge(Graph* graph, char from, char to) {
    int fromIndex = from - 'A';
    int toIndex = to - 'A';
    
    Node* prev = NULL;
    Node* curr = graph->adjLists[fromIndex];
    
    while (curr != NULL && curr->vertex != to) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        printf("Edge from %c to %c does not exist.\n", from, to);
        return;
    }
    
    if (prev == NULL) {
     
        graph->adjLists[fromIndex] = curr->next;
    } else {
       
        prev->next = curr->next;
    }
    
    free(curr);
    
    printf("Removed edge from %c to %c\n", from, to);
}


int main() {
    int i, numVertices = 5; 
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = malloc(numVertices * sizeof(Node*));

    
    for (i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    printf("Initialized adjacency list:\n");
    display(graph);

 
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'B', 'D');

    printf("\nAdjacency list after adding edges:\n");
    display(graph);
    
    
    
    removeEdge(graph,'A','B');
    display(graph);
    

    return 0;
}

