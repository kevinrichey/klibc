----------------------------------------

# klib - Core Library

----------------------------------------

## Utility Macros

### UNUSED(var)

Suppress unused parameter warnings for variable *var*.

### STANDARD_ENUM_VALUES(EnumName_)

Insert the standard enumerators to an enum, prefixed with *EnumName_*:

- *EnumName_*First == 0.
- *EnumName_*Last == last enum value.
- *EnumName_*End == last enum value + 1.

### VA_NARGS(...)


Returns
:  number of arguments passed.


### ARRAY_LENGTH(a)


Returns
:  length of statically sized array *a*.

Undefined behavior if *a* is dynamically allocated array.

----------------------------------------

## Debugging & Error Checking

### Status_String

	const char *Status_string(Status stat);

Convert *stat* code to string.

Returns
:  Pointer to static constant global string. Do not modify or free().


### Error_print

	void Error_print(FILE *out, ErrorInfo *e);

Print error to file stream *out*. 

----------------------------------------

## Unit Testing

### TEST_CASE(test_name_)

Define new test case *test_name_*. 

### test(condition_)

If boolean expression *condition_* is false, the test fails.

----------------------------------------

## vector - tuple with named and random access

### vector(TYPE, members...)

Declare a new vector of *TYPE* with *members*.
Access elements through the named members or by random access
through the *at[]* array member.

Example - declare an x,y point
: `vector(int, x, y)  point;`
: `point.x = 100;`
: `point.at[1] = 200;   // at[1] is random access to member y`


Example - declare an RGB color type
: `typedef vector(unsigned, red, green, blue)  rgb;`

### vec_length(v)


Returns
:  length (number of members) in vector *v*.


----------------------------------------

## list - Dynamic Resizeable Arrays

### list(type)

Declare a new list of *type* objects.

Example - declare list if int
: `list(int) *numbers = NULL;`

Example - define new list of doubles type
: `typedef list(double)  list_doubles;`

### list_resize(list, s)

Resize *list* to store at least *s* elements.

Side Effects
: Pointer *list* may be modified. 

### list_size(list)

	static inline int list_size(void *list)


Returns
:  int size (max capacity) of *list*.


### list_length(list)

	static inline int list_length(void *list)


Returns
:  int number of elements in *list*.


### list_is_full(list)

	static inline bool list_is_full(void *list)


Returns
:  *true* if *list* is full (cannot add more elemnets).


### list_is_empty(list)

	static inline bool list_is_empty(void *list)


Returns
:  *true* if *list* is empty (no elements in list)


### list_dispose(list)

	void list_dispose(void *list);

Free *list* when it's not longer used.

