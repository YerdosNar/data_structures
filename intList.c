#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "intList.h"

void init_list(IntList *l) {
    l->arr = (int *)malloc(1 * sizeof(int));
    l->size = 0;
}

void add(IntList *l, int num) {
    l->arr = (int *)realloc(l->arr, (l->size + 1) * sizeof(int));
    l->arr[l->size] = num;
    l->size++;
}

void addArray(IntList *l, int array[], int size) {
    int *newarr = (int *)realloc(l->arr, (l->size + size) * sizeof(int));
    if(newarr != NULL) {
        for(int i = l->size; i < l->size + size; i++) {
            l->arr[i] = array[i - l->size];
        }
        l->arr = newarr;
        l->size += size;
    }
}

void set(IntList *l, int idx, int num) {
    if(idx < 0 || idx >= l->size) {
        printf("Index out of bounds!\n");
        return;
    } else {
        l->arr[idx] = num;
    }
}

int get(IntList *l, int idx) {
    if(idx < 0 || idx >= l->size) {
        printf("Index out of bounds!\nReturn value: -1\n");
        return -1;
    }
    return l->arr[idx];
}

int indexOf(IntList *l, int value) {
    for(int i = 0; i < l->size; i++) {
        if(l->arr[i] == value) {
            return i;
        }
    }
    printf("List does NOT contain!\n");
    return -1;
}

bool contains(IntList *l, int value) {
    for(int i = 0; i < l->size; i++) {
        if(l->arr[i] == value) {
            return true;
        }
    }
    return false;
}

void deleteByValue(IntList *l, int value) {
    if(!contains(l, value)) {
        printf("List does NOT contain!\n");
        return;
    }
    for(int i = indexOf(l, value); i < l->size - 1; i++) {
        l->arr[i] = l->arr[i+1];
    }
    int *newarr = (int *)realloc(l->arr, (l->size - 1) * sizeof(int));
    if(newarr != NULL) {
        l->arr = newarr;
        l->size--;
    }
}

void deleteByIdx(IntList *l, int idx) {
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

void printList(const IntList *l) {
    printf("[");
    for(int i = 0; i < l->size - 1; i++) {
        printf("%d, ", l->arr[i]);
    }
    printf("%d]\n", l->arr[l->size-1]);
}

int size(IntList *l) {
    return l->size;
}

void freeList(IntList *l) {
    free(l->arr);
    l->size = 0;
}
