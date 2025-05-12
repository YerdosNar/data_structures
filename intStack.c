#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "intStack.h"

void init_stack(IntStack *s) {
	s->arr = NULL;
	s->size = 0;
}

bool stIsEmpty(IntStack *s) {
	return s->size == 0;
}

void push(IntStack *s, int num) {
	int *newarr = (int *)realloc(s->arr, (s->size + 1) * sizeof(int));
	if(newarr != NULL) {
		s->arr = newarr;
		s->arr[s->size] = num;
		s->size++;
	}
}

int pop(IntStack *s) {
    if(stIsEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
	int popping = s->arr[s->size - 1];
	int *newarr = (int *)realloc(s->arr, (s->size - 1) * sizeof(int));
	if(newarr != NULL) {
		s->arr = newarr;
		s->size--;
	}
	return popping;
}

void show(IntStack *s) {
	printf("Stack [");
    if(stIsEmpty(s)) {
        printf("]");
    } else {
        for(int i = 0; i < s->size; i++) {
            printf("%d", s->arr[i]);
            if(i != s->size-1) {
                printf(", ");
            }
        }
        printf("]");
    }
    printf("\n");
}

void freeStack(IntStack *s) {
    free(s->arr);
    s->arr = NULL;
    s->size = 0;
}
