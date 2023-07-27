#include "dynamic_string.h"

#include <string.h>
#include <stdio.h>

size_t get_size_private(const DynamicString_t *self) {
    return self->size;
}

const char* get_str_immutable_private(const DynamicString_t *self) {
    return self->data;
}

DynamicString_t* copy(const DynamicString_t *self) {
    DynamicString_t* copy_str = (DynamicString_t*)malloc(sizeof(DynamicString_t));
    memcpy(copy_str, self, sizeof(DynamicString_t));
    copy_str->data = (char*)calloc(self->size, sizeof(char));

    memcpy(copy_str->data, self->data, self->size);
    copy_str->data[self->size] = '\0';

    copy_str->self = copy_str;
    return copy_str;
}

void dest_str_private(const DynamicString_t *str) {
    free(str->data);
    free(str->self);
}

DynamicString_t* init_dynamic_string(const char *str) {
    DynamicString_t* new_str = (DynamicString_t*)malloc(sizeof(DynamicString_t));
    new_str->self = new_str;
    new_str->size = strlen(str);

    char* data = (char*)calloc(new_str->size, sizeof(char));
    strcpy(data, str);
    new_str->data = data;
    new_str->data[new_str->size] = '\0';

    new_str->get_size = get_size_private;
    new_str->get_str_immutable = get_str_immutable_private;
    new_str->dest_str = dest_str_private;
    new_str->copy = copy;

    return new_str;
}