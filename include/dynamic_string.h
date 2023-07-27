#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <stdlib.h>

#define SELF const struct DynamicString*

typedef struct DynamicString {
    
    struct DynamicString* self;
    char* data;
    size_t size;

    size_t (*getSize)(SELF);
    const char* (*getStrImmutable)(SELF);
    void (*destStr)(SELF);
    struct DynamicString*(*copy)(SELF);

} DynamicString_t;

size_t get_size(SELF);

const char* get_str_immutable(SELF);

void dest_str(SELF);

DynamicString_t* copy(SELF);

DynamicString_t* InitDynamicString(const char *str);

#endif //DYNAMIC_STRING_H