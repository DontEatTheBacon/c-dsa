#include <stdio.h>
#include <stdlib.h>

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

ContainerItem* create_item(void* ptr, const Type type)
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

int main(int argc, char** argv)
{
    Container* container = create_container(3);

    add_float(container, 6.7f);
    add_int(container, 4);
    add_string(container, "hello");

    print_container(container);

    return 0;
}