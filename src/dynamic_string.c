#include "dynamic_string.h"

#include <string.h>
#include <stdio.h>

size_t get_size(const DynamicString_t *self) {
    return self->size;
}

const char* get_str_immutable(const DynamicString_t *self) {
    return self->data;
}

DynamicString_t* copy(const DynamicString_t *self) {
    DynamicString_t* copyStr = (DynamicString_t*)malloc(sizeof(DynamicString_t));
    memcpy(copyStr, self, sizeof(DynamicString_t));
    copyStr->self = copyStr;
    copyStr->data = (char*)calloc(self->size, sizeof(char));
    
    memcpy(copyStr->data, self->data, self->size);
    copyStr->data[self->size] = '\0';

    return copyStr;
}

void dest_str(const DynamicString_t *str) {
    free(str->data);
    free(str->self);
}

DynamicString_t* InitDynamicString(const char *str) {
    DynamicString_t* newStr = (DynamicString_t*)malloc(sizeof(DynamicString_t));
    newStr->self = newStr;
    newStr->size = strlen(str);

    char* data = (char*)calloc(newStr->size, sizeof(char));
    strcpy(data, str);
    newStr->data = data;
    newStr->data[newStr->size] = '\0';

    newStr->getSize = get_size;
    newStr->getStrImmutable = get_str_immutable;
    newStr->destStr = dest_str;
    newStr->copy = copy;

    return newStr;
}

// Add the init_str inside the string struct to make it so the
// init_str can't be called from everywhere but only from the 
// string_t object ---> I don't think this will work in C
