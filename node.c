#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node* createNode(int line_number, int count) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro ao alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->line_number = line_number;
    newNode->count = count;
    newNode->next = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (node != NULL) {
        free(node);
    }
}