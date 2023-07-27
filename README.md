# Simple-String-Library

## *Viktor Nikolov*

This library contains implementations of dynamic and static string structures that can be included in other programs. Currently the library is in a work in progress state.


The following **functionality** is completed:

DynamicString:
* [x] getSize - returns the number of chars in the string.
* [x] getStrImmutable - returns a const version of the data inside the string. 
* [x] destStr - frees the heap allocated memory
   
StaticString:
* [x] Under development


**TO DO**
* [ ] Add a copy function
* [ ] Add a slice function
* [ ] Add an append function
* [ ] Possibly add a reverse function (Returns the data in reverse order)
* [ ] Create a shared library
* [ ] Create a static library

## Notes

This library even though made in 'C' uses an object oriented approach or at least that is what I'm attempting to do.