#include <stdio.h>
#include <stddef.h>

#include "container.h"

Container* create_container(const size_t capacity)
{
    Container* container = (Container*) malloc(sizeof(Container));
    if (!container)
    {
        return NULL;
    }

    container->items = (ContainerItem**) calloc(capacity, sizeof(ContainerItem*));
    if (!container->items)
    {
        free(container);
        return NULL;
    }

    container->capacity = capacity;
    container->size = 0;

    return container;
}

static ContainerItem* create_item(void* ptr, const Type type)
{
    ContainerItem* item = (ContainerItem*) malloc(sizeof(ContainerItem));
    if (!item)
    {
        return NULL;
    }

    item->type = type;
    item->ptr = ptr;

    return item;
}

void print_container(Container* container)
{
    printf("[");
    for (size_t i = 0; i < container->size; i++)
    {
        ContainerItem* item = (container->items)[i];
        if (item->type == INT)
        {
            printf("%d", *(int*)(item->ptr));
        }
        else if (item->type == FLOAT)
        {
            printf("%f", *(float*)(item->ptr));
        }
        else if (item->type == STRING)
        {
            printf("%s", (char*)(item->ptr));
        }
        printf(i + 1 < container->size ? ", " : "");
    }
    printf("]\n");
}

void add_int(Container* container, int value)
{
    int* ptr = (int*) malloc(sizeof(int));
    *ptr = value;

    ContainerItem* item = create_item(ptr, INT);
    (container->items)[container->size] = item;
    container->size += 1;
}

void add_float(Container* container, float value)
{
    float* ptr = (float*) malloc(sizeof(float));
    *ptr = value;

    ContainerItem* item = create_item(ptr, FLOAT);
    (container->items)[container->size] = item;
    container->size += 1;
}

void add_string(Container* container, char* value)
{
    ContainerItem* item = create_item(value, STRING);
    (container->items)[container->size] = item;
    container->size += 1;
}