# Simple-String-Library

## *Viktor Nikolov*

This library contains a simple implementation of a dynamic string that can be included in other programs. Currently the library is in a work in progress state.


The following **functionality** is completed:

DynamicString:
* [x] get_size - Returns the number of chars in the string.
* [x] get_alloc - Returns the allocated size including null terminator
* [x] get_str_immutable - Returns a const version of the data.
* [x] get_str - Returns a non const version of the data. 
* [x] copy - Allocates new memory and copies data. Returns pointer
             to new memory.
* [x] append_str - Reallocates memory for the old string and for the new                appending string. Appends string at the end.
* [x] dest_str - Frees the heap allocated memory.
   

**TO DO**
* [x] Add a copy function
* [ ] Add a slice function
* [ ] Add an append function
* [ ] Possibly add a reverse function (Returns the data in reverse order)
* [ ] Create a shared library
* [ ] Create a static library
* [ ] Add unit tests. Try doing them in python.
* [ ] Add comments and documentation. 
* [ ] Add input verification in the functions.
* [ ] Add NULL pointer checks where memory is allocated. 

## Notes

* This library even though made in 'C' uses an object oriented approach or at least that is what I'm attempting to do.
* Naming convention is snake_case.
