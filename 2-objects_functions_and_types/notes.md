# Chapter 2 notes
## Table of Contents
- [Declaring Variables](#declaring-variables)
- [Scope](#scope)
- [Storage Duration](#storage-duration)
- [Alignment](#alignment)
- [Object Types](#object-types)
- [Character Types](#character-types)
- [Integer Types](#integer-types)
- [Enum Types](#enum-types)
- [Floating-Point Types](#floating-point-types)
- [Void Types](#void-types)
- [Function Types](#function-types)
- [Derived Types](#derived-types)
- [Pointer Types](#pointer-types)
- [Arrays](#arrays)
- [Type Definitions](#type-definitions)
- [Structures](#structures)

### **Declaring Variables**
- Variables are objects with a declared type
- Type is important since another type will interpret the bit pattern differently
- Functions are not objects but do have return types and a number of types as parameter
- **Pointers** = adress in memory
- Pointer type derived from object or function called referenced type
- Pointer from referenced type T = pointer to T
- Object pointers != function pointers
- Function arguments are copies of the original variable
- **\*** = points to memory address of an object or function
- **Dereferencing** = accessing the value stored at the memory address the pointer points to
- **&** = creates a pointer to its address

### **Scope**
- **Scope** = Region where a C identifier (variable, function, ...) can be accessed
- C has 4 types of scope:
  - **File Scope:**<br>
    Scope is entire text file and any files that appear afterwards.
  - **Block Scope:**
    Identifier is only accessible within the block it's defined in.
  - **Function Prototype Scope:**
    Allows functions to be defined before they are called. (no {} with logic)
  - **Function Scope:**
    Function scope is logic between {}.
    Labels also have function scope.

- Scopes can be nested with inner and outer scopes.
- Best practice is to use different identifiers to avoid confusion.
- Identifiers in large scopes need to be descriptive/longer.

### **Storage Duration**
- four storage durations exist:
  - **Automatic:**<br>
    Lifetime begins when the block where it's declared begins execution and ends when execution of this block ends.
  - **Static:**<br>
    Static lifespan is during the **entire execution of the program**. Objects in file scope are static. By specifying `static` you can make block-scoped variables static. Static objects cannot be declared with a variable.
  - **Thread:**<br>
    Used in **concurrent programming**. (Not seen in this book)
  - **Allocated:**<br>
    Deals with **dynamically allocated memory**. Seen in chapter 6.

### **Alignment**
- Alignment is the number of bytes between successive addresses which objects can be allocated to. This differs from cpu to cpu.
- Alignments are always a non-negative multiple of 2.
- Dynamically allocated memory using `malloc` is required to be alligned for all standards.
- `_Alignas` = Controls the alignment of a variable or type explicitly. Overrides the default alignment.<br>
Is usually used when you need to meet specific hardware requirements or use specific operations.
- Stricter alignment = the variable needs to be placed at a memory address that are a multiple of a specific value

### **Object Types**
- `_Bool` = objects can only store 0 and 1 (underscore is to separate from existing programs that already have bool or boolean declared)
- Identifiers beginning with `_` and followed by another `_` or an uppercase letter is always reserved by the C standard committee
- `#include <stdbool.h>` adds the `bool` and `true` and `false` global identifiers. (`bool` is recommended as type)

### **Character Types**
- `char` (signed or unsigned): compiler causes this to have the same alignment, size, range, representation and behaviour ass either signed or unsigned. (char is a separate type from both). bad to use integers as char. Either signed or unsigned for small values.
- `signed char`
- `unsigned char`
- `wchar_t`: Takes more space than a basic character. Typically 16-32 bits. Used for non-english characters.

### **Integer Types**
- **Signed Integer Types (-128 to 127):**<br>
Represents negative & positive numbers & zero. Includes `signed char`, `short int`, `int`, `long int`, `long long int`. Sacrifice 1 bit to represent negative numbers.
- **Unsigned Integer Types (0 to 255):**<br>
For each Signed Integer there is a corresponding Unsigned Integer that uses the same amount of storage. This includes: `unsigned char`, `unsigned short`, `unsigned short int`, `unsigned long int`, `unsigned long long int`. These can only represent positive numbers and zero.
- limits of various integer types are specified in `<limits.h>` header file.
- Specify width integers by using type definitions from `<stdint.h>` or `<inttypes.h` headers like ex. `uint32_t`. Also provide widest available as `uintmax_t` and `intmax_t`. (see Chapter 3)

### **Enum Types**
- `enumeration` or `enum` allows you to define a type that defines a name to integer values.
- Not defining the first enum defaults to 0.
- When assigning something with `=`. You can have duplicate values.
- enum must be representable by int. gcc uses unsigned int (0-256), c++ uses signed int (-127-128).

### **Floating-Point Types**
- `float`, `double`, `long double` (see chapter 3)

### **Void Types**
- `void` = cannot hold any value
- derived type `void *` is a pointer reference to *any* object. (derived types)

### **Function Types**
- Function types are a derived type. They are derived from the return type and the number of types of its parameters.
- Specifying parameter names is optional but recommended.
Specifying no parameter name and type works for now but is deprecated and is not recommended.
- function definition provides the implementation of the function.

### **Derived Types**
- Derived types are types that are constructed from other types.<br>includes:
  - Pointers
  - Arrays
  - Type Definitions
  - Structures
  - Unions

### **Pointer Types**
- Pointer type = derived from **function** or **object** type called the *referenced* type.<br>
ex.:
```c
int *p;
char *cp;
void *vp;
```
- A void pointer is a generic pointer. Can hold the address of *any* object (`int`, `float`, `char`, ...) but not to the address of a function.
- Address-of function/object = `&`<br>
ex.:
```c
int i = 17;
int *ip = &i;
/**
ip and &*ip both point to the memory address of i and is valid code
`ip = &*ip;`
**/
```
- `*` converts pointer to a type into a value of that type.
- If it points to a function the result is the function designator.
- If it points to an object the result is the value of the designated object.

### **Arrays**
- An array is a contiguously allocated sequence of objects that all have the same element type.
ex.:
```c
// an array of 11 elements of type int
int ia[11];

// an array of 17 elements of type pointer to float
float *afp[17];
```
- array's are defined by `[]`.
- [Example](./arrays.c)
```c
&str[10] = str + 10
/**
&(*(str + 10)) = str + 10   // & and * cancel

str + 10 would return a pointer to the 10th element in the array here. Same with &str[10]
**/
```
- An array name in memory is the entire block of the content of the array
- The array name index moves forward elements in the array (not bytes).
- `*` dereferences an array so gets the value of the value.
- [Matrix](./matrix.c)

### **Type Definitions**
- `typedef` to declare alias for a type (does not create a new type).<br>
ex.:
```c
// unsigned int = uint_type
typedef unsigned int uint_type;

/**
schar_type = Alias for signed char
*schar_type = Alias for pointer to signed char
(*fp)(void) = Alias for function pointer returning signed char
**/
typedef signed char schar_type, *schar_p, (*fp)(void);
```
- Identifiers that end in `_t` are type definitions for existing types. This is reserved by the C standard.

### **Structures**
- A **structure type** or **struct** contains sequentially allocated member objects. Each object has it's own name and can have it's own type.<br>
ex.:
- [example](./structures.c)

### **Unions**
- A union is a special data type that allows storing different data types in the same memory location. However, unlike a struct, a union can store only one of its members at a time.
- Is primarily used to save memory
- Memory allocated to the union is equal to the size of the largest member.
- [example](./unions.c)





