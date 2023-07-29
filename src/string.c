#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_string.h"


int main() {

    DynamicString_t *str = init_dynamic_string("hello12345 4");
    printf("str size = %ld\n", strlen(str->data));
    
    if (strcmp(str->data, "") == 0) {
        printf("The string is empty.\n");
    } else if (str->data[strlen(str->data)] == '\0') {
        printf("The string has a null terminator at the end.\n");
    } else {
        printf("The string does not have a null terminator at the end.\n");
    }
    
    printf("str data = %s\n", str->get_str_immutable(str->self));
    printf("str size = %ld\n", str->get_size(str->self));

    puts("\nCreate str_copy and copy data from str to str_copy\n");
    DynamicString_t *str_copy = str->copy(str);

    printf("&str = %p\n", str);
    printf("&str_copy = %p\n", str_copy);

    printf("str->self = %p\n", str->self);
    printf("str_copy->sel = %p\n", str_copy->self);
    
    printf("str_copy->data = %s\n", str_copy->get_str_immutable(str->self));
    printf("str_copy->size = %ld\n", str_copy->get_size(str->self));

    str->dest_str(str);
    str_copy->dest_str(str_copy);
}