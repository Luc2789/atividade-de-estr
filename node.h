#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int line_number;  // Número da linha
    int count;        // Quantidade de vezes que a palavra apareceu na linha
    struct Node* next; // Próximo nó na lista encadeada
} Node;

// Cria um novo nó
Node* createNode(int line_number, int count);

// Libera a memória de um nó
void freeNode(Node* node);

#endif