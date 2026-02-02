#include "container.h"

int main(int argc, char** argv)
{
    Container* container = create_container(3);

    add_float(container, 6.7f);
    add_int(container, 4);
    add_string(container, "hello");

    print_container(container);

    return 0;
}