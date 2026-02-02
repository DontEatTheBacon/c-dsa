#ifndef CONTAINER_H
#define CONTAINER_H

typedef enum { INT, FLOAT, STRING } Type;

typedef struct ContainerItem
{
    Type type;
    void* ptr;
} ContainerItem;

typedef struct Container
{
    size_t size;
    size_t capacity;
    ContainerItem** items;
} Container;

Container* create_container(const size_t capacity);
void print_container(Container* container);
void add_int(Container* container, int value);
void add_float(Container* container, float value);
void add_string(Container* container, char* value);

#endif