#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void initDictionary(Dictionary* dict) {
    dict->head = NULL;
}

void addWordToDictionary(Dictionary* dict, const char* word, int line_number, int count) {
    WordEntry* current = dict->head;
    WordEntry* prev = NULL;

    while (current != NULL && strcmp(current->word, word) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        WordEntry* newEntry = createWordEntry(word);
        addOccurrence(newEntry, line_number, count);
        if (prev == NULL) {
            dict->head = newEntry;
        } else {
            prev->next = newEntry;
        }
    } else {
        Node* node = current->occurrences;
        while (node != NULL && node->line_number != line_number) {
            node = node->next;
        }
        if (node == NULL) {
            addOccurrence(current, line_number, count);
        } else {
            node->count++;
        }
    }
}

void printInvertedIndex(Dictionary* dict) {
    WordEntry* current = dict->head;
    while (current != NULL) {
        printf("%s : ", current->word);
        Node* node = current->occurrences;
        while (node != NULL) {
            printf("(%d,%d)", node->line_number, node->count);
            if (node->next != NULL) {
                printf(", ");
            }
            node = node->next;
        }
        printf("\n");
        current = current->next;
    }
}

void freeDictionary(Dictionary* dict) {
    WordEntry* current = dict->head;
    while (current != NULL) {
        WordEntry* temp = current;
        current = current->next;
        freeWordEntry(temp);
    }
}