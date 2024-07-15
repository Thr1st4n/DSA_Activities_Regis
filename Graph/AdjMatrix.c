#include <stdio.h>
#include <stdlib.h>

void display(int arr[][5], int rows, int columns) {
    char vertex = 'A'; 
    int i, j;
    printf("  "); 
    for (i = 0; i < columns; i++) {
        printf("%c ", vertex++);
    }
    printf("\n");
	vertex = 'A'; 
    for (i = 0; i < rows; i++) {
        printf("%c ", vertex++);
        for (j = 0; j < columns; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addEdge(int arr[][5], char from, char to) {
    int fromIndex = from - 'A';
    int toIndex = to - 'A';
    printf("Adding edge from %c to %c\n", from, to);
    arr[fromIndex][toIndex] = 1;
    arr[toIndex][fromIndex] = 1;
}

void removeEdge(int arr[][5], char from, char to) {
    int fromIndex = from - 'A';
    int toIndex = to - 'A';


    if (arr[fromIndex][toIndex] == 0) {
        printf("Edge from %c to %c does not exist.\n", from, to);
        return;
    }

    arr[fromIndex][toIndex] = 0;
    arr[toIndex][fromIndex] = 0;

    printf("Removed edge from %c to %c\n", from, to);
}

int main() {
    int matrix[5][5] = {{0}};

    printf("Initialized matrix:\n");
    display(matrix, 5, 5);

    addEdge(matrix, 'A', 'B');
    addEdge(matrix, 'B', 'D');

    printf("\nMatrix after adding edges:\n");
    display(matrix, 5, 5);
    
    removeEdge(matrix,'B','D');
    display(matrix,5,5);

    return 0;
}

