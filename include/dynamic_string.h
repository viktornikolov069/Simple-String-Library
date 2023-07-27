#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <stdlib.h>

#define SELF_DYNAMIC const struct DynamicString*


typedef struct DynamicString {

    // we need a constructor
    // we need a destructor
    // we need a this pointer
    
    // we need a copy function


    // make a function that returns the size
    // make append function
    // make slice function
    // make reverse function
    // create the string as a shared lib and as a static lib

    
    struct DynamicString* self;
    char* data;
    size_t size;

    size_t (*getSize)(SELF_DYNAMIC);
    const char* (*getStrImmutable)(SELF_DYNAMIC);
    void (*destStr)(const struct DynamicString*);


} DynamicString_t;

size_t get_size(const DynamicString_t *self);

const char* get_str_immutable(const DynamicString_t *self);

void dest_str(const DynamicString_t *str);

DynamicString_t* InitDynamicString(const char *str);

#endif //DYNAMIC_STRING_H