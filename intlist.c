#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "intlist.h"

void init_list(intlist *l) {
    l->arr = (int *)malloc(1 * sizeof(int));
    l->size = 0;
}

void add(intlist *l, int num) {
    l->arr = (int *)realloc(l->arr, (l->size + 1) * sizeof(int));
    l->arr[l->size] = num;
    l->size++;
}

void addArray(intlist *l, int array[], int size) {
    int *newarr = (int *)realloc(l->arr, (l->size + size) * sizeof(int));
    if(newarr != NULL) {
        for(int i = l->size; i < l->size + size; i++) {
            l->arr[i] = array[i - l->size];
        }
        l->arr = newarr;
        l->size += size;
    }
}

bool contains(intlist *l, int key) {
    for(int i = 0; i < l->size; i++) {
        if(l->arr[i] == key) {
            return true;
        }
    }
    return false;
}

int get(intlist *l, int idx) {
    if(idx < 0 || idx >= l->size) {
        printf("Index out of bounds!\nReturn value is -1\n");
        return -1;
    }
    return l->arr[idx];
}

void set(intlist *l, int idx, int num) {
    if(idx < 0 || idx >= l->size) {
        printf("Index out of bounds!\n");
        return;
    } else {
        l->arr[idx] = num;
    }
}

int indexOf(intlist *l, int key) {
    if(contains(l, key)) {
        for(int i = 0; i < l->size; i++) {
            if(l->arr[i] == key) {
                return i;
            }
        }
    }
    printf("List does NOT contain!\n");
    return -1;
}

void deleteByKey(intlist *l, int key) {
    if(!contains(l, key)) {
        printf("List does NOT contain!\n");
        return;
    }
    for(int i = indexOf(l, key); i < l->size - 1; i++) {
        l->arr[i] = l->arr[i+1];
    }
    int *newarr = (int *)realloc(l->arr, (l->size - 1) * sizeof(int));
    if(newarr != NULL) {
        l->arr = newarr;
        l->size--;
    }
}

void deleteByIdx(intlist *l, int idx) {
    if(idx < 0 || idx >= l->size) {
        printf("Index out of bounds!\n");
        return;
    }
    for(int i = idx; i < l->size - 1; i++) {
        l->arr[i] = l->arr[i+1];
    }
    int *newarr = (int *)realloc(l->arr, (l->size - 1) * sizeof(int));
    if(newarr != NULL) {
        l->arr = newarr;
        l->size--;
    }
}

void printList(const intlist *l) {
    printf("[");
    for(int i = 0; i < l->size - 1; i++) {
        printf("%d, ", l->arr[i]);
    }
    printf("%d]", l->arr[l->size-1]);
}

int size(intlist *l) {
    return l->size;
}

void freeList(intlist *l) {
    free(l->arr);
    l->size = 0;
}
