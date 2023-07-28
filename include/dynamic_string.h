#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <stdlib.h>

#define SELF_CONST const struct DynamicString*
#define SELF struct DynamicString*

typedef struct DynamicString {
    
    struct DynamicString* self;
    char* data;
    size_t size;

    size_t (*get_size)(SELF_CONST);
    const char* (*get_str_immutable)(SELF_CONST);
    void (*dest_str)(SELF);
    struct DynamicString*(*copy)(SELF_CONST);

} DynamicString_t;

size_t get_size_private(SELF_CONST);

const char* get_str_immutable_private(SELF_CONST);

void dest_str_private(SELF);

DynamicString_t* copy_private(SELF_CONST);

DynamicString_t* init_dynamic_string(const char *str);

#endif //DYNAMIC_STRING_H