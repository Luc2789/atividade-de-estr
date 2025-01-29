#ifndef WORD_ENTRY_H
#define WORD_ENTRY_H

#include "node.h"

#define MAX_WORD_LENGTH 100

typedef struct WordEntry {
    char word[MAX_WORD_LENGTH]; // Palavra
    Node* occurrences;          // Lista de ocorrências (nós)
    struct WordEntry* next;     // Próxima entrada no dicionário
} WordEntry;

// Cria uma nova entrada de palavra
WordEntry* createWordEntry(const char* word);

// Adiciona uma ocorrência a uma entrada de palavra
void addOccurrence(WordEntry* wordEntry, int line_number, int count);

// Libera a memória de uma entrada de palavra
void freeWordEntry(WordEntry* wordEntry);

#endif