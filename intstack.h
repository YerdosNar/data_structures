#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int *arr;
	size_t size;
} intstack;

void push(intstack *s, int num);
int pop(intstack *s);
bool isEmpty(intstack *s);
void show(intstack *s);

#endif
