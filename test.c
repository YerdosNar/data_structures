#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "intQueue.h"
#include "intList.h"
#include "intStack.h"

void testList() {
    IntList int_list;
    IntList *l = &int_list;

    printf("\n===========\n");
    printf(" LIST TEST\n");
    printf("===========\n");
    init_list(l);

    for(int i = 1; i <= 10; i++) {
        add(l, i);
    }
    printf("\nSize = %d\n", size(l));
    printList(l);

    int arr[5] = {11, 12, 13, 14, 15};
    addArray(l, arr, 5);
    printf("\nAfter array addition:\n");
    printList(l);

    set(l, 10, 0);
    printf("\nAfter setting 10th item to 0.\n");
    printList(l);

    printf("\n11th item is: %d\n", get(l, 11));

    printf("\nIndex of 7 is: %d\n", indexOf(l, 7));

    printf("\nDoes the list contain 100? ");
    if(contains(l, 100)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    printf("\nDoes the list contain 1? ");
    if(contains(l, 1)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    deleteByValue(l, 14);
    printf("\nAfter deleting 14 from the list.\n");
    printList(l);

    deleteByIdx(l, 2);
    printf("\nAfter deleting 3rd element from the list.\n");
    printList(l);

    freeList(l);
}

void testStack() {
    IntStack int_stack;
    IntStack *st;
    init_stack(st);

    printf("\n============\n");
    printf(" STACK TEST");
    printf("\n============\n");

    printf("Is the stack empty? ");
    if(stIsEmpty(st)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    for(int i = 1; i <= 10; i++) {
        push(st, i);
    }
    printf("\n");
    show(st);

    printf("Pop = %d\n", pop(st));
    printf("Pop = %d\n", pop(st));

    printf("\nAfter popping two elements:");
    show(st);

    printf("Is the stack empty? ");
    if(stIsEmpty(st)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    push(st, 100);
    printf("\nAfter pushing 100 into the stack:\n");
    show(st);

    freeStack(st);
}

void testLinkedList() {
    //I will complete later
}

void testQueue() {
    Queue int_queue;
    Queue *q = &int_queue;
    initQueue(q, 10);

    printf("\n============\n");
    printf(" QUEUE TEST\n");
    printf("============\n");
    //Initial check
    printf("\nFull = %d, Empty = %d\n\n", qIsFull(q), qIsEmpty(q));

    for(int i = 1; i <= 10; i++) {
        enqueue(q, i);
    }
    printQueue(q);
    printf("\nFull = %d, Empty = %d\n", qIsFull(q), qIsEmpty(q));

    printf("\nDeQueue = %d\n", dequeue(q));
    printf("After DeQueue:\n");
    printQueue(q);
    //Midle check
    printf("\nFull = %d, Empty = %d\n", qIsFull(q), qIsEmpty(q));

    printf("\nAfter EnQueue(11):\n");
    enqueue(q, 11);
    printQueue(q);

    //Last check
    printf("\nFull = %d, Empty = %d\n", qIsFull(q), qIsEmpty(q));

    freeQueue(q);
}

void exiting() {
    printf("Exiting.");
    for(int i = 0; i < 2; i++) {
        sleep(1);
        printf(".");
    }
    printf("\n");
}

int main() {
    char input[100];
    printf("What do you want to test\nStack = st\nQueue = q\nList = l\nLinkedList = ll\n");
    while(1) {
        printf("Enter your choice: ");
        scanf("%s", input);

        for(int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }

        if(strcmp(input, "st") == 0) testStack();
        else if(strcmp(input, "q") == 0) testQueue();
        else if(strcmp(input, "l") == 0) testList();
        else if(strcmp(input, "ll")== 0) testLinkedList();
        else if(strcmp(input, "nothing") == 0) {
            exiting();
            break;
        } else {
            printf("Invalid choice.\n");
        }

        printf("\nNow what to test?\n");
    }


    return 0;
}
