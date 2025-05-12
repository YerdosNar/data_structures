#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
} IntList;

void init_list(IntList *l);
void add(IntList *l, int num);
void addArray(IntList *l, int array[], int size);
void set(IntList *l, int idx, int num);
int get(IntList *l, int idx);
int indexOf(IntList *l, int value);
bool contains(IntList *l, int value);
void deleteByValue(IntList *l, int value);
void deleteByIdx(IntList *l, int idx);
void printList(const IntList *l);
int size(IntList *l);
void freeList(IntList *l);

#endif
