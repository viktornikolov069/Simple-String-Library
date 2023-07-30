#include "dynamic_string.h"
#include <string.h>
#include <stdio.h>

#define CHECK_ALLOC_RETURN_NULL(X) ({ if((X) == NULL) { \
                                        fprintf(stderr, \
                                        "Allocation Error ("__FILE__":%d)\n", __LINE__); \
                                        return NULL;}})

#define PRINT_LINE_ERROR fprintf(stderr, "Allocation Error ("__FILE__":%d)\n", __LINE__)

size_t get_size_private(const DynamicString_t *self) {
    return self->size;
}

size_t get_alloc_private(const DynamicString_t *self) {
    return self->alloc;
}

const char* get_str_immutable_private(const DynamicString_t *self) {
    return self->data;
}

char* get_str_private(const DynamicString_t *self) {
    return self->data;
}

DynamicString_t* copy_private(const DynamicString_t *self) {
    DynamicString_t *copy_str = (DynamicString_t*)malloc(sizeof(DynamicString_t));

    //malloc safety check
    CHECK_ALLOC_RETURN_NULL(copy_str);

    //Shallow copy
    memcpy(copy_str, self, sizeof(DynamicString_t));

    //Deep copy
    copy_str->data = (char*)calloc(self->size, sizeof(char));
    memcpy(copy_str->data, self->data, self->size);
    copy_str->data[self->size] = '\0';

    //Point to self
    copy_str->self = copy_str;
    return copy_str;
}

void dest_str_private(DynamicString_t *str) {
    if (str == NULL) {
        return;
    }
    free(str->data);
    free(str->self);

    //Point all freed pointers to NULL
    str->data = NULL;
    str->self = NULL;
    str = NULL;
}

void append_str_private(DynamicString_t *self ,const char* str) {
    size_t str_size = strlen(str);
    
    //Reallocate the old data and adds space for the new data
    self->data = realloc(self->data, self->size + str_size + 1);

    //realloc safety check
    if (self->data == NULL) {
        PRINT_LINE_ERROR;
        return;
    }

    //Copy the new data on the newly allocated space
    //starting from the end of the old data.
    memcpy(self->data + self->size, str, str_size);

    //Update the size variables
    self->alloc = self->size + str_size + 1;
    self->size = self->size + str_size;

    //Place null terminator at the end of data block 
    self->data[self->size] = '\0';
}

DynamicString_t* init_dynamic_string(const char *str) {
    DynamicString_t *new_str = (DynamicString_t*)malloc(sizeof(DynamicString_t));;

    //malloc safety check
    CHECK_ALLOC_RETURN_NULL(new_str);

    if (str != NULL) {
        new_str->self = new_str;

        //Add one for the null terminator
        new_str->alloc = strlen(str) + 1;
        new_str->size = strlen(str);

        //Zero-initialize data
        new_str->data = (char*)calloc(new_str->alloc, sizeof(char));
        strncpy(new_str->data, str, new_str->size);

        //strncpy probably copied the null terminator as well in
        //the previous step but just in case I'll set it again.
        new_str->data[new_str->size] = '\0';
    } else {
		new_str->alloc = 1;
		new_str->size = 0;
		new_str->data = (char*)calloc(new_str->alloc, sizeof(char));
		new_str->data[0] = '\0';
    }

    //Assigning the func. pointers to the 
    //actual functions which are purposely marked as private.
    //The idea is to simulate having member functions 
    //which isn't possible in C.
    new_str->get_size = get_size_private;
    new_str->get_alloc = get_alloc_private;
    new_str->get_str_immutable = get_str_immutable_private;
    new_str->get_str = get_str_private;
    new_str->dest_str = dest_str_private;
    new_str->copy = copy_private;
    new_str->append_str = append_str_private;

    return new_str;
}