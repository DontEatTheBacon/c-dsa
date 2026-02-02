#include "container.h"

int main(int argc, char** argv)
{
    Container* container = create_container(0);

    add_float(container, 6.7f);
    add_int(container, 4);
    add_string(container, "hello");
    add_string(container, "nig");
    add_float(container, 4.0f);
    add_int(container, 4);
    add_string(container, "andrew");
    add_string(container, "chopped");

    print_container(container);

    delete_container(container);

    return 0;
}