#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_string.h"


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

    puts("\nCreate strCopy and copy data from str to strCopy\n");
    DynamicString_t *strCopy = str->copy(NULL);

    printf("Address of str = %p\n", str);
    printf("Address of strCopy = %p\n", strCopy);
    printf("Address of strCopy.data = %p\n", strCopy->data);
    printf("Address of str.data = %p\n", str->data);
    printf("difference between str.data and strCopy.data = %ld\n", str->data - strCopy->data);

    printf("str size = %ld\n", strlen(strCopy->data));
    printf("strCopy data = %s\n", strCopy->getStrImmutable(strCopy->self));
    printf("strCopy size = %ld\n", sizeof(strCopy));

    puts("Print memory\n");

    printf("str->destStr = %p\n", str->destStr);
    printf("strCopy->destStr = %p\n", strCopy->destStr);

    str->destStr(str);
    strCopy->destStr(strCopy);
}