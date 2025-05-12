#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int *arr;
	size_t size;
} IntStack;

void init_stack(IntStack *s);
void push(IntStack *s, int num);
int pop(IntStack *s);
bool stIsEmpty(IntStack *s);
void show(IntStack *s);
void freeStack(IntStack *s);

#endif
