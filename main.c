#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

void processFile(const char* filename, Dictionary* dict) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        char* word = strtok(line, " \t\n");
        while (word != NULL) {
            // Converter para minúsculas para evitar duplicações
            for (int i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }

            // Adicionar a palavra ao dicionário
            addWordToDictionary(dict, word, line_number, 1);

            word = strtok(NULL, " \t\n");
        }
    }

    fclose(file);
}

int main() {
    Dictionary dict;
    initDictionary(&dict);

    processFile("input.txt", &dict);
    printInvertedIndex(&dict);

    freeDictionary(&dict);

    return 0;
}