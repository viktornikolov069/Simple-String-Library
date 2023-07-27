#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_string.h"


#define SELF_DYNAMIC const struct DynamicString*
#define SELF_STATIC const struct StaticString*

typedef struct StaticString {

    // we need a constructor
    // we need a destructor
    // we need a this pointer
    // make a function that returns the size
    // make append function
    // make slice function
    // make reverse function
    // create the string as a shared lib and as a static lib

    
    struct StaticString* self;
    char* data;
    size_t size;

    size_t (*getSize)(SELF_STATIC);
    const char* (*getStrImmutable)(SELF_STATIC);
    void (*destStr)(const struct DynamicString*);

} StaticString_t;


int main() {

    DynamicString_t *str = InitDynamicString("hello12345 4");
    printf("str size = %ld\n", strlen(str->data));
    
    if (strcmp(str->data, "") == 0) {
        printf("The string is empty.\n");
    } else if (str->data[strlen(str->data)] == '\0') {
        printf("The string has a null terminator at the end.\n");
    } else {
        printf("The string does not have a null terminator at the end.\n");
    }
    
    printf("str data = %s\n", str->getStrImmutable(str->self));
    printf("str size = %ld\n", str->getSize(str->self));
    str->destStr(str);
}