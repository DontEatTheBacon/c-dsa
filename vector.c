#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define VECTOR_INIT_SIZE 8

Vector* create_vector(const size_t capacity)
{
    assert(capacity >= 0);

    Vector* newVector = (Vector*) malloc(sizeof(Vector));

    // malloc failed
    if (newVector == NULL)
    {
        return NULL;
    }

    newVector->capacity = (capacity == 0) ? VECTOR_INIT_SIZE : capacity;
    newVector->items = (int*) calloc(newVector->capacity, sizeof(int));
    
    // calloc failed
    if (newVector->items == NULL)
    {
        free(newVector);
        return NULL;
    }

    newVector->size = 0;
    return newVector;
}

void print_vector(const Vector* vector)
{
    printf("[");
    for (size_t i = 0; i < vector->size; i++)
    {
        printf("%d%s", vector->items[i],
        (i + 1 < vector->size) ? ", " : "");
    }
    printf("]\n");
}

static int resize_vector(Vector* vector, const size_t new_capacity)
{
    size_t old_capacity = vector->capacity;
    int* temp;
    
    temp = (int*) realloc(vector->items, new_capacity * sizeof(int));

    // realloc failed
    if (temp == NULL)
    {
        return 0;
    }

    vector->items = temp;
    vector->capacity = new_capacity;

    // if vector is truncated adjust size
    if (new_capacity < old_capacity)
    {
        vector->size = new_capacity;
    }

    return 1;
}

void delete_vector(Vector* vector)
{
    free(vector->items);
    free(vector);
}

int push_back(Vector* vector, const int value)
{
    // ensure capacity
    if (vector->size == vector->capacity)
    {
        // resize failed
        if (!resize_vector(vector, vector->capacity * 2))
        {
            return 0;
        }
    }

    vector->items[vector->size] = value;
    vector->size += 1;

    return 1;
}

int pop_back(Vector* vector)
{
    if (vector->size == 0)
    {
        return 0;
    }

    vector->size--;

    return 1;
}

void shrink_to_fit(Vector* vector)
{
    if (vector->size < vector->capacity)
    {
        int* temp = (int*) realloc(vector->items, vector->size);
        if (temp)
        {
            vector->items = temp;
            vector->capacity = vector->size;
        }
    }
}