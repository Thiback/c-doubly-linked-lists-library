# Doubly Linked List Library

This is an object oriented (as far as C allows it), doubly-linked list library. Besides every nodes being implemented as a structure, the list itself is a structure with methods.

### Nodes

Represented by structures (__node_t__), each containing :
- a pointer to the previous node
- a pointer to the next node
- a pointer to the data itself

### List

Represented by structures (__dllist_t__), each containing :
- a pointer to the first node (node_t *head) and to the last node (node_t *tail)
- the number of elements within the list (size_t len), updated whenever a method uses it.
- a series of function pointers, effectively acting as methods for the __dllist_t__ object.
Do note that for each of these, as per C imperative nature, you must pass a pointer to the list as first argument to these methods.

The list of the "methods" include:
-   __add_head__
-   __insert_data__ (to insert a node to a position on the list)
-   __add_tail__
-   __listlen__ (returns the length of the list).
-   __at__ (to get an element from the list using an index)
-   __remove_tail__
-   __remove_head__
-   __remove_node_pos__
-   __swap__ (to swap 2 elements within the list)
-   __reverse__
-   __callback__ (this function takes a function pointer, and calls it upon the data pointer of each element of the list)
-   __delete__ (frees all the nodes of the list. This is akin to a destructor)
-   __to_ptr_array__ (converts the list to a pointer array)

Check out the small program written in src/main.c to have a usage example of the library.
This library has been tested using criterion.