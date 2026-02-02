#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct Vector
{
    int* items;
    size_t size;
    size_t capacity;
} Vector;

Vector* create_vector(const size_t size);
void print_vector(const Vector* vector);
void delete_vector(Vector* vector);
void shrink_to_fit(Vector* vector);
int push_back(Vector* vector, const int value);
int pop_back(Vector* vector);

#endif