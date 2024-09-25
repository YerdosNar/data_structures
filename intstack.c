#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "intstack.h"

void init_stack(intstack *s) {
	s->arr = (int *)malloc(1 * sizeof(int));
	s->size = 0;
}

void push(intstack *s, int num) {
	int *newarr = (int *)realloc(s->arr, (s->size + 1) * sizeof(int));
	if(newarr != NULL) {
		s->arr = newarr;
		s->arr[s->size + 1] = num;
		s->size++;
	}
}

int pop(intstack *s) {
	int *newarr = (int *)realloc(s->arr, (s->size - 1) * sizeof(int));
	int popping = s->arr[s->size - 1];
	if(newarr != NULL) {
		s->arr = newarr;
		s->size--;
	}
	return popping;
}

bool isEmpty(intstack *s) {
	return s->size == 1;
}

void show(intstack *s) {
	printf("[");
	if(!isEmpty(s)) {
		for(int i = 0; i < s->size - 1; i++) {
			printf("%d, ", s->arr[i]);
		}
		printf("%d", s->arr[s->size - 1]);
	} else {
		printf("]");
	}
}
