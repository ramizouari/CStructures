//
// Created by ramizouari on 02/04/2022.
//

#ifndef CSTRUCTURES_DYNAMIC_ARRAY_H
#define CSTRUCTURES_DYNAMIC_ARRAY_H
#include <stdlib.h>

typedef struct dynamic_array {
    void *array;
    int size;
    int capacity;
} dynamic_array;

dynamic_array dynamic_array_init(int capacity)
{
    dynamic_array da;
    da.array = malloc(capacity * sizeof(void *));
    da.size = 0;
    da.capacity = capacity;
    return da;
}

void dynamic_array_add(dynamic_array *da, void *element)
{
    if (da->size == da->capacity) {
        da->capacity *= 2;
        da->array = realloc(da->array, da->capacity * sizeof(void *));
    }
    da->array[da->size] = element;
    da->size++;
}

void dynamic_array_delete(dynamic_array *da, int index)
{
    if (index < 0 || index >= da->size) {
        return;
    }
    for (int i = index; i < da->size - 1; i++) {
        da->array[i] = da->array[i + 1];
    }
    da->size--;
}

void dynamic_array_find(dynamic_array *da, void *element)
{
    for (int i = 0; i < da->size; i++) {
        if (da->array[i] == element) {
            return i;
        }
    }
    return -1;
}

void dynamic_array_free(dynamic_array *da)
{
    free(da->array);
    da->array = NULL;
    da->size = 0;
    da->capacity = 0;
}


#endif //CSTRUCTURES_DYNAMIC_ARRAY_H
