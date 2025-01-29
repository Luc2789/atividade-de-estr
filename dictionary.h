#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "word_entry.h"

typedef struct {
    WordEntry* head; // Cabeça da lista de entradas de palavras
} Dictionary;

// Inicializa um dicionário vazio
void initDictionary(Dictionary* dict);

// Adiciona uma palavra ao dicionário
void addWordToDictionary(Dictionary* dict, const char* word, int line_number, int count);

// Imprime o índice invertido
void printInvertedIndex(Dictionary* dict);

// Libera a memória do dicionário
void freeDictionary(Dictionary* dict);

#endif