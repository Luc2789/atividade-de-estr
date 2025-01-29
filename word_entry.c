#include "word_entry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

WordEntry* createWordEntry(const char* word) {
    WordEntry* newEntry = (WordEntry*)malloc(sizeof(WordEntry));
    if (newEntry == NULL) {
        perror("Erro ao alocar memória para a entrada de palavra");
        exit(EXIT_FAILURE);
    }
    strncpy(newEntry->word, word, MAX_WORD_LENGTH);
    newEntry->occurrences = NULL;
    newEntry->next = NULL;
    return newEntry;
}

void addOccurrence(WordEntry* wordEntry, int line_number, int count) {
    Node* newNode = createNode(line_number, count);
    newNode->next = wordEntry->occurrences;
    wordEntry->occurrences = newNode;
}

void freeWordEntry(WordEntry* wordEntry) {
    if (wordEntry != NULL) {
        Node* current = wordEntry->occurrences;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            freeNode(temp);
        }
        free(wordEntry);
    }
}