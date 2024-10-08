#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
} intlist;

void init_list(intlist *l);
void add(intlist *l, int num);
void set(intlist *l, int idx, int num);
int get(intlist *l, int idx);
int indexOf(intlist *l, int key);
bool contains(intlist *l, int key);
void deleteByKey(intlist *l, int key);
void deleteByIdx(intlist *l, int idx);
void printList(const intlist *l);
int size(intlist *l);
void freeList(intlist *l);

#endif
