#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char **items;
    size_t size;
} StringList;

void init_sl(StringList *sl) {
    sl->items = (char **) malloc(1 * sizeof(int));
    sl->size = 0;
}

void add_string(StringList *sl, char *item) {
    sl->items = (char **)realloc(sl->items, (sl->size+1) * sizeof(char *));
    sl->items[sl->size] = item;
    sl->size++;
}

void add_string_array(StringList *sl, char *array[], int size) {
    char **newarr = (char **)realloc(sl->items, (sl->size + size) * sizeof(char *));
    if(newarr != NULL) {
        for(int i = sl->size; i < sl->size + size; i++) {
            sl->items[i] = array[i - sl->size];
        }
        sl->items = newarr;
        sl->size += size;
    }
}
